class linear_queue:
    def __init__(self):
        self.List = []

    def Enqueue(self, data):
        self.List.append(data)

    def Dequeue(self):
        pop_data = self.List[0]
        del self.List[0]
        return pop_data

    def isEmpty(self):
        if len(self.List) is 0:
            return True
        else:
            return False

def radix_sort(List, size):
    bucket = [linear_queue() for x in range(10)]

    max = 0
    for i in range(size):
        if max < List[i]:
            max = List[i]

    pos = 1
    while max / pos:
        for i in range(size):
            repo = (List[i] / pos) % 10
            bucket[repo].Enqueue(List[i])

        j = 0
        for i in range(10):
            while bucket[i].isEmpty() is not True:
                List[j] = bucket[i].Dequeue()
                j += 1
        pos *= 10
    return List



if __name__ == "__main__":
    List = [3771, 1, 5022, 3, 98]
    size = len(List)
    result = radix_sort(List, size)
    print result