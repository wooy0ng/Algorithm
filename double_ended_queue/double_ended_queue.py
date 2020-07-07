class node:
    def __init__(self, data):
        self.prev = None
        self.next = None
        self.data = data

class deque:
    def __init__(self):
        self.rear = None
        self.front = None
        self.nodeCount = 0

    def isEmpty(self):
        if self.rear is None and self.front is None:
            return True
        else:
            return False

    def rear_Enqueue(self, data):
        newNode = node(data)
        if self.isEmpty() is True:
            self.rear = newNode
            self.front = newNode
        else:
            self.rear.prev = newNode
            newNode.next = self.rear
            self.rear = newNode
        self.nodeCount += 1

    def front_Enqueue(self, data):
        newNode = node(data)
        if self.isEmpty() is True:
            self.rear = newNode
            self.front = newNode
        else:
            self.front.next = newNode
            newNode.prev = self.front
            self.front = newNode
        self.nodeCount += 1

    def rear_Dequeue(self):
        if self.isEmpty() is not True:
            tmp = self.rear
            tmp.next.prev = None
            self.rear = tmp.next
            tmp = None
            self.nodeCount -= 1

    def front_Dequeue(self):
        if self.isEmpty() is not True:
            tmp = self.front
            tmp.prev.next = None
            self.front = tmp.prev
            tmp = None
            self.nodeCount -= 1

    def print_Dequeue(self):
        tmp = self.rear
        while tmp is not None:
            print tmp.data,
            tmp = tmp.next
        print '\n'

if __name__ == "__main__":
    arr = [5, 10, 15, 20, 2, 4, 6, 8]
    d = deque()
    for data in arr:
        d.rear_Enqueue(data)
    d.print_Dequeue()

    d.rear_Dequeue()
    d.print_Dequeue()
    d.front_Dequeue()
    d.print_Dequeue()

    d.front_Enqueue(70)
    d.print_Dequeue()