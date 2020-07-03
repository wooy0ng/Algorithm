package double_linked_list;

class Node{
	Node prev;
	Node next;
	int data;
	
	public Node(){
		this.prev = null;
		this.next = null;
		this.data = 0;
	}
	public Node(int data) {
		this.prev = null;
		this.next = null;
		this.data = data;
	}
}


class D_linked_list{
	Node head;
	Node tail;
	public int nodeCount;
	
	public D_linked_list() {
		this.head = null;
		this.tail = null;
	}
	
	void List_head_input(int data) {
		Node newNode = new Node(data);
		if(this.head == null && this.tail == null) {
			this.head = newNode;
			this.tail = newNode;
		}
		else {
			newNode.next = this.head;
			this.head.prev = newNode;
			this.head = newNode;
		}
		nodeCount++;
	}
	void List_tail_input(int data) {
		Node newNode = new Node(data);
		if(this.head == null && this.tail == null) {
			this.head = newNode;
			this.tail = newNode;
		}
		else {
			newNode.prev = this.tail;
			this.tail.next = newNode;
			this.tail = newNode;
		}
		nodeCount++;
	}
	void List_delete(int idx) {
		Node tmp = this.head;
		int cnt = 0;
		
		while(tmp != null) {
			if(idx == 0) {
				this.head.next.prev = null;
				this.head = this.head.next;
				break;
			}
			else if(idx == this.nodeCount - 1) {
				this.tail.prev.next = null;
				this.tail = this.tail.prev;
				break;
			}
			else if(idx == cnt) {
				tmp.prev.next = tmp.next;
				tmp.next.prev = tmp.prev;
				tmp = null;
				break;
			}
			tmp = tmp.next;
			cnt++;
		}	
		nodeCount--;
	}
	
	void List_print() {
		Node tmp = this.head;
		while(tmp != null) {
			System.out.print(tmp.data + " ");
			tmp = tmp.next;
		}
		System.out.print('\n');
	}
	
}

public class practice {
	public static void main(String[] args) {
		int arr[] = {5,10,15,20,2,4,6,9,12};
		D_linked_list d = new D_linked_list();
		for(int i = 0; i < arr.length; i++) 
			d.List_head_input(arr[i]);
		d.List_print();
		
		d.List_delete(8);
		d.List_print();
		d.List_delete(0);
		d.List_print();
		d.List_delete(5);
		d.List_print();
			
		d.List_tail_input(9);
		d.List_print();
	}
}