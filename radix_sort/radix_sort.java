package radix_sort;

import java.util.Arrays;

class Node{
	public int data;
	public Node prev;
	
	public Node() {
		this.data = 0;
		this.prev = null;
	}
	public Node(int data) {
		this.data = data;
		this.prev = null;
	}
	public Node(int data, Node node) {
		this.data = data;
		this.prev = node;
	}	
}

class linear_queue{
	int nodeCount = 0;
	public Node rear;
	public Node front;
	
	public linear_queue() {
		this.rear = null;
		this.front = null;
	}
	
	public boolean isEmpty() {
		boolean result;
		if(rear == null) 
			result = true;
		else
			result = false;
		return result;
	}
	
	public void EnQueue(int data) {
		Node newNode = new Node(data);
		nodeCount++;
		if(this.isEmpty()) {
			this.rear = newNode;
			this.front = newNode;
		}
		else {
			this.rear.prev = newNode;
			this.rear = newNode;
		}	
	}
	
	public int DeQueue() {
		int result = this.front.data;
		this.front = this.front.prev;
		if(nodeCount == 1)
			this.rear = null;
		nodeCount--;
		return result;
	}
}


public class linked_list {	
	public static void main(String args[]) {
		int arr[] = {3771, 1, 5022, 3, 98};
		
		linear_queue[] q = new linear_queue[10];
		for(int i = 0; i< q.length; i++)
			q[i] = new linear_queue();
		
		
		int max = 0;
		for(int i = 0; i < arr.length; i++) {
			if(max < arr[i])
				max = arr[i];
		}
		
		int pos = 1;
		while((max / pos) != 0) {
			for(int i = 0 ;i < arr.length; i++) {
				int radix = (arr[i] / pos) % 10;
				q[radix].EnQueue(arr[i]);
			}
			for(int i = 0, j = 0; i < 10; i++) {
				while(!q[i].isEmpty()) {
					arr[j++] = q[i].DeQueue();
				}
			}
			pos *= 10;
		}
		
		System.out.println(Arrays.toString(arr));
	}
}