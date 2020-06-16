package practice;
import java.util.Arrays;

public class test {
	public static void selection_sort(int[] arr, int size) {
		for(int i = 0; i < size; i++) {
			for(int j = i + 1; j < size; j++) {
				if(arr[i] > arr[j]) {
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}
	public static void main(String[] args) {
		int[] arr;
		arr = new int[] {2, 10, 3, 1, 9};
		
		selection_sort(arr, arr.length);
		System.out.println(Arrays.toString(arr));
	}
}
