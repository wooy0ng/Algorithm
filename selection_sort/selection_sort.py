def selection_sort(arr):
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if(arr[i]>arr[j]):
                tmp = arr[i]
                arr[i] = arr[j]
                arr[j] = tmp
    return arr

if __name__ == "__main__":
    arr = [2,10,3,1,9]
    selection_sort(arr)
    print(arr)
