package practice1;
import java.util.Arrays;

public class practice1 {
	
	public static void bubble_sort(int[] arr, int size) {
		boolean not_changed = true;
		do {
			for(int i = 0; i < size - 1; i++) {
				if(arr[i]>arr[i+1]) {
					not_changed = false;
					int tmp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = tmp;
				}
			}
			if(not_changed)
				break;
			else {
				size--;
				not_changed = true;
				//System.out.println(Arrays.toString(arr));
			}
			
		}while(true);
	}
	
	public static void main(String[] args) {
		int[] arr = { 5, 1, 3, 2, 7, 11, 15, 13, 10, 8 };
		
		bubble_sort(arr, arr.length);
		System.out.println(Arrays.toString(arr));
	}
}
