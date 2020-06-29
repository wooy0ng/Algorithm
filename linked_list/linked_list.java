package practice;

class Node{
	public int data;
	public Node next;
	
	public Node() {
		this.data = 0;
		this.next = null;
	}
	public Node(int data) {
		this.data = data;
		this.next = null;
	}
	public Node(int data, Node node) {
		this.data = data;
		this.next = node;
	}
}

public class linked_list {
	private Node head;
	public int nodeCount = 0;
	 
	public linked_list() {
		head = null;
	}
	
	// add data
	public void Append(int data) {
		Node newNode = new Node(data);
		if(head == null) {
			this.head = newNode;
		}
		else {
			Node tmp = head;
			while(tmp.next != null) {
				tmp = tmp.next;
			}
			tmp.next = newNode;
		}
		nodeCount++;
	}
	
	public void Insert(int pos, int data) {
		if(pos > nodeCount) {
			System.out.println("error\n");
			System.exit(0);
		}
		Node newNode = new Node(data);
		
		Node prev_node = getAt(pos);
		if(prev_node == null) {
			prev_node = getAt(pos-1);
			prev_node.next = newNode;
		}
		else {
			newNode.next = prev_node.next;
			prev_node.next = newNode;
		}
		nodeCount++;
	}
	
	public Node getAt(int pos) {
		int cnt = 0;
		Node tmp = head;
		Node return_node = null;
		
		while(cnt < nodeCount) {
			if(cnt == pos)
				break;
			tmp = tmp.next;
			cnt++;
		}
		if(cnt < pos)
			return_node = null;
		else
			return_node = tmp;
		return return_node;
	}
	
	// delete data
	public void Delete(int pos) {
		Node delete_node = getAt(pos);
		if(delete_node == null) {
			System.out.println("error\n");
			System.exit(0);
		}
		
		if(pos == 0) {
			head = head.next;
			delete_node = null;
		}
		else {
			Node prev_node = getAt(pos - 1);
			if(delete_node.next == null) {
				prev_node.next = null;
				delete_node = null;
			}
			else {
			Node next_node = getAt(pos + 1);
			prev_node.next = next_node;
			delete_node = null;
			}
		}
		nodeCount--;
	}
	
	public void printlist() {
		Node tmp = head;
		do{
			System.out.print(tmp.data + "->");
			tmp = tmp.next;
		} while(tmp.next != null); 
		System.out.println(tmp.data);
	}
	
	
	public static void main(String args[]) {
		linked_list List = new linked_list();
		
		List.Append(5);
		List.Append(6);
		List.Append(8);
		List.Append(12);
		List.printlist(); // 5->6->8->12
		
		List.Insert(2, 29);
		List.printlist(); // 5->6->8->29->12
		List.Insert(5, 39);
		List.printlist(); // 5->6->8->29->12->39
		List.Insert(4, 9);
		List.printlist(); // 5->6->8->29->12->9->39
		
		List.Delete(5);
		List.printlist(); // 5->6->8->29->12->39
		List.Delete(5);
		List.printlist(); // 5->6->8->29->12
		List.Delete(0);
		List.printlist(); // 6->8->29->12
	}
}