class node:
	def __init__(self, item):
		self.data = item
		self.nextNode = None
	
class LinkedList:
	def __init__(self):
		self.head = None
		self.tail = None
		self.nodeCount = 0
	
	def Append(self, item):
		newNode = node(item)
		if self.nodeCount == 0:
			self.head = newNode
			self.tail = newNode
		else:
			self.tail.nextNode = newNode
			self.tail = newNode
		self.nodeCount += 1
		
	def getAt(self, pos):
		cnt = 0
		Node = self.head
		while Node is not None:
			current = Node
			if pos == cnt:
				return current
			Node = Node.nextNode
			cnt += 1
	
	
	def Delete(self, pos):
		if pos < self.nodeCount:
			Delete_Node = self.getAt(pos)
		else:
			Delete_Node = self.tail
			
		if pos == 0:
			self.head = Delete_Node.nextNode
			Delete_Node.nextNode = None
		else:
			prev_Node = self.getAt(pos - 1)
			prev_Node.nextNode = Delete_Node.nextNode
			Delete_Node.nextNode = None
			if pos == self.nodeCount:
				self.tail = prev_Node
			
		print("Delete(%d, %d)" %(pos, Delete_Node.data))
		self.nodeCount -= 1
		
	def Insert(self, pos, item):
		Insert_Node = node(item)
		if pos == 0:
			current_Node = self.head
			Insert_Node.nextNode = current_Node
			self.head = Insert_Node
		else:
			prev_Node = self.getAt(pos - 1)
			current_Node = prev_Node.nextNode
			
			prev_Node.nextNode = Insert_Node
			Insert_Node.nextNode = current_Node
		
		if pos > self.nodeCount:
			tmp_Node = self.tail
			tmp_Node.nextNode = Insert_Node
			self.tail = Insert_Node
			
		print("Insert(%d, %d)" %(pos, item))
		self.nodeCount += 1
		
	def PrintList(self):
		Node = self.head
		for idx in range(self.nodeCount):
			if Node.nextNode is not None:
				print(Node.data, end = " -> ")
			else:
				print(Node.data)
			Node = Node.nextNode
	
	

if __name__ == "__main__":
	L = list(map(int, input().strip().split(' ')))
	Linked = LinkedList()
	for data in L:
		Linked.Append(data)
	Linked.PrintList()
	
	# Delete Node
	Linked.Delete(0)	
	Linked.PrintList() # 10 -> 15 -> 20 -> 25 -> 30
	Linked.Delete(4)
	Linked.PrintList() # 10 -> 15 -> 20 -> 25
	Linked.Delete(2)
	Linked.PrintList() # 10 -> 15 -> 25
	
	# Insert Node
	Linked.Insert(0, 6)
	Linked.PrintList() # 6 -> 10 -> 15 -> 25
	Linked.Insert(4, 30)
	Linked.PrintList() # 6 -> 10 -> 15 -> 25 -> 30
	Linked.Insert(3, 27)
	Linked.PrintList() # 6 -> 10 -> 15 -> 27 -> 25 -> 30
