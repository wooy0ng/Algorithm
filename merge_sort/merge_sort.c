#include <stdio.h>
#include <stdbool.h>

int tmp[10];

void print(int* arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", *(arr + i));
	printf("\n");
}

void sortation(int left, int mid, int right, int* arr) {
	int p, q, r;
	p = left;
	q = mid + 1;
	r = left;		// array of tmp - idx

	while (p <= mid && q <= right) {
		if (arr[p] > arr[q])
			tmp[r++] = arr[q++];
		else
			tmp[r++] = arr[p++];
	}
	if (p > mid) {
		for(int i = q; i <= right;i++)
			tmp[r++] = arr[i];
	}
	else {
		for (int i = p; i <= mid; i++)
			tmp[r++] = arr[i];
	}
	for (int i = left; i <= right; i++)
		arr[i] = tmp[i];
}

void merge_sort(int left, int right, int* arr) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(left, mid, arr);		
		merge_sort(mid + 1, right, arr); 

		sortation(left, mid ,right, arr);
	}

}

int main() {
	int arr[10] = { 5, 1, 3, 2, 7, 15, 11, 13, 10, 8 };
	merge_sort(0, (sizeof(arr) / sizeof(int)) - 1, arr);

	print(arr, 10);
	return 0;
}