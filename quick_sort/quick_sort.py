def quick_sort(left, right, List):
    if left < right:
        List, pivot = sortation(left, right, List)

        quick_sort(left, pivot - 1, List)
        quick_sort(pivot, right, List)

def sortation(left, right, List):
    pivotIdx = left
    leftIdx = pivotIdx + 1
    rightIdx = right

    while leftIdx < rightIdx:
        if List[leftIdx] > List[rightIdx]:
            List[leftIdx], List[rightIdx] = List[rightIdx], List[leftIdx]
        leftIdx += 1
        rightIdx -= 1
    if List[pivotIdx] > List[rightIdx]:
        List[pivotIdx], List[rightIdx] = List[rightIdx], List[pivotIdx]
    pivotIdx = rightIdx

    return List, pivotIdx

if __name__ == "__main__":
    List = [5, 1, 3, 2, 7, 15, 11, 13, 10, 8]
    size = len(List)

    quick_sort(0, size - 1, List)
    print(List)