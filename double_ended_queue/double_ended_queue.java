package double_ended_queue;

class node{
	node prev;
	node next;
	int data;
	
	public node(int data) {
		this.prev = null;
		this.next = null;
		this.data = data;
	}
}

class Deque{
	node rear;
	node front;
	int nodeCount;
	
	public Deque() {
		this.rear = null;
		this.front = null;
		this.nodeCount = 0;
	}
	
	boolean isEmpty() {
		if(this.rear == null && this.front == null)
			return true;
		else
			return false;
	}
	void rear_Enqueue(int data) {
		node newNode = new node(data);
		if(this.isEmpty()) {
			this.rear = newNode;
			this.front = newNode;
		}
		else {
			this.rear.prev = newNode;
			newNode.next = this.rear;
			this.rear = newNode;
		}
		this.nodeCount++;
	}
	void front_Enqueue(int data) {
		node newNode = new node(data);
		if(this.isEmpty()) {
			this.rear = newNode;
			this.front = newNode;
		}
		else {
			this.front.next = newNode;
			newNode.prev = this.front;
			this.front = newNode;
		}
		this.nodeCount++;
	}
	void rear_Dequeue() {
		node tmp = this.rear;
		if(!this.isEmpty()) {
			tmp.next.prev = null;
			this.rear = tmp.next;
			tmp = null;
		}
		this.nodeCount--;
	}
	void front_Dequeue() {
		node tmp = this.front;
		if(!this.isEmpty()) {
			tmp.prev.next = null;
			this.front = tmp.prev;
			tmp = null;
		}
		this.nodeCount--;
	}
	void print_queue() {
		node tmp = this.rear;
		while(tmp != null) {
			System.out.print(tmp.data + " ");
			tmp = tmp.next;
		}
		System.out.println('\n');
	}
}

public class mainClass {
	public static void main(String[] args) {
		int arr[] = {5, 10, 15, 20, 2, 4, 6, 8, 20};
		Deque d = new Deque();
		
		for(int i = 0; i < arr.length; i++)
			d.rear_Enqueue(arr[i]);
		d.print_queue();
		
		d.rear_Dequeue();
		d.print_queue();
		d.front_Dequeue();
		d.print_queue();
		
		d.front_Enqueue(90);
		d.print_queue();
	}
}
