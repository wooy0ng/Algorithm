#include <stdio.h>
#include <stdbool.h>

void print(int* arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", *(arr + i));
	printf("\n");
}

void bubble_sort(int* arr, int size) {
	bool not_changed = true;
	do {
		for (int i = 0; (i < size) && (i + 1 != size); i++) {
			if (arr[i] > arr[i + 1]) {
				not_changed = false;
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
		if (not_changed)
			break;
		else
			not_changed = true;
		// print(arr, 10);
	} while (size--);
}

int main() {
	int arr[10] = { 5, 1, 3, 2, 7, 11, 15, 13, 10, 8 };
	int size = sizeof(arr) / sizeof(int);

	bubble_sort(arr, size);
	print(arr, size);
	return 0;
}
