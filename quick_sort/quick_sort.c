#include <stdio.h>
#include <stdbool.h>

void print(int* arr, int size) {
	for (int i = 0; i < size; i++) 
		printf("%d ", *(arr + i));
	printf("\n");
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// int arr[10] = { 5, 1, 3, 2, 7, 15, 11, 13, 10, 8 };
int sortation(int left, int right, int* arr) {
	int pivotIdx = left;
	int leftIdx = pivotIdx + 1;
	int rightIdx = right;

	while (leftIdx < rightIdx) {   // O(N)
		if (arr[leftIdx] > arr[rightIdx])
			swap(&arr[leftIdx], &arr[rightIdx]);
		leftIdx++; rightIdx--;
	}
	if (arr[pivotIdx] > arr[rightIdx])
		swap(&arr[pivotIdx], &arr[rightIdx]);
	print(arr, 10);
	pivotIdx = rightIdx;
	return pivotIdx;
}

void quick_sort(int left, int right, int* arr) {	// 0, 9
	if (left < right) {
		int pivotIdx = sortation(left, right, arr);		// 5

		quick_sort(left, pivotIdx - 1, arr);    // O(logN) or O(N)
		quick_sort(pivotIdx, right, arr);
	}
}

int main(){
	int arr[10] = { 5, 1, 3, 2, 7, 15, 11, 13, 10, 8 };
	int size = sizeof(arr) / sizeof(int);

	quick_sort(0, size - 1, arr);
	print(arr, size);
	return 0;
}