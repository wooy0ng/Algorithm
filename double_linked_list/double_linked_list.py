class Node:
	def __init__(self, item):
		self.data = item
		self.prev = None
		self.next = None
	
class Double_Linked:
	def __init__(self):
		self.nodeCount = 0
		self.head = Node(None)
		self.tail = Node(None)
		
		self.head.next = self.tail
		self.head.prev = None
		self.tail.prev = self.head
		self.tail.next = None
	
	def Append(self, item):
		newNode = Node(item)
		if self.nodeCount == 0:
			prev_node = self.head
			next_node = self.tail
		else:
			prev_node = self.tail.prev
			next_node = self.tail
		newNode.prev = prev_node
		newNode.next = next_node
		
		prev_node.next = newNode
		next_node.prev = newNode
		self.nodeCount += 1
	
	def getAt(self, pos):
		if pos < 0 or pos > self.nodeCount:
			return None
			
		current = self.head.next
		idx = 0
		while idx is not pos:
			current = current.next
			idx += 1
		return current
		
	def InsertNode(self, pos, item):
		newNode = Node(item)
		print("Insert(%d, %d)" %(pos, item))
		if pos == self.nodeCount - 1:
			prev_Node = self.tail.prev
			next_Node = self.tail
		elif pos == 0:
			prev_Node = self.head
			next_Node = self.head.next
		else:
			prev_Node = self.getAt(pos - 1)
			next_Node = prev_Node.next
			
		newNode.prev = prev_Node
		newNode.next = next_Node
		prev_Node.next = newNode
		next_Node.prev = newNode
		
		self.nodeCount += 1
	
	def DeleteNode(self, pos):
		if pos == 0:
			Delete_Node = self.head.next
			prev_Node = self.head
			next_Node = Delete_Node.next
		elif pos == self.nodeCount - 1:
			Delete_Node = self.tail.prev
			prev_Node = Delete_Node.prev
			next_Node = self.tail
		else:
			Delete_Node = self.getAt(pos)
			prev_Node = Delete_Node.prev
			next_Node = Delete_Node.next
		print("Delete(%d, %d)" %(pos, Delete_Node.data))
		
		Delete_Node.prev = None
		Delete_Node.next = None
		prev_Node.next = next_Node
		next_Node.prev = prev_Node
		self.nodeCount -= 1
		
		
	def PrintList(self):
		tmp = self.head.next
		while tmp.next.data is not None:
			print(tmp.data, end=" <-> ")
			tmp = tmp.next
		print(tmp.data)
		
		
	
if __name__ == "__main__":
	L = list(map(int, input().strip().split(' '))) # 5 10 15 20 25
	Double_Link = Double_Linked()
	for data in L:
		Double_Link.Append(data)
	Double_Link.PrintList()
	Double_Link.InsertNode(3, 28) # 5 10 15 28 20 25
	Double_Link.InsertNode(0, 30) # 30 5 10 15 28 20 25
	Double_Link.InsertNode(6, 50) # 30 5 10 15 28 20 25 50
	Double_Link.PrintList()
	
	Double_Link.DeleteNode(3) # 30 5 10 28 20 25 50
	Double_Link.DeleteNode(0) # 5 10 28 20 25 50
	Double_Link.DeleteNode(5) # 5 10 28 20 25
	Double_Link.PrintList()
