#include <stdio.h>

void print(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

void selection_sort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		print(arr, size);
	}
}

int main() {
	int arr[5] = { 2, 10, 3,1,9 };
	selection_sort(arr, sizeof(arr) / sizeof(int));
	return 0;
}