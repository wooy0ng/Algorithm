package practice1;
import java.util.Arrays;

public class practice1 {
	public static void swap(int[] arr, int x, int y) {
		int tmp = arr[x];
		arr[x] = arr[y];
		arr[y] = tmp;
	}
	
	public static int sortation(int left, int right, int[] arr) {
		int pivotIdx = left;
		int leftIdx = pivotIdx + 1;
		int rightIdx = right;
		
		while(leftIdx < rightIdx) {
			if(arr[leftIdx] > arr[rightIdx]) {
				swap(arr, leftIdx, rightIdx);
			}
			leftIdx++; rightIdx--;
		}
		if(arr[pivotIdx] > arr[rightIdx]) {
			swap(arr, pivotIdx, rightIdx);
		}
		
		pivotIdx = rightIdx;
		
		return pivotIdx;
	}
	
	public static void quick_sort(int left, int right, int[] arr) {
		if(left < right) {
			int pivot = sortation(left, right, arr);
			
			quick_sort(left, pivot - 1, arr);
			quick_sort(pivot, right, arr);
		}
	}
	
	public static void main(String[] args) {
		int[] arr = { 5, 1, 3, 2, 7, 11, 15, 13, 10, 8 };
		
		quick_sort(0, arr.length - 1,arr);
		System.out.println(Arrays.toString(arr));
	}
}