def bubble_sort(arr,size):
    not_changed = True
    while(size):
        for i in range(size - 1):
            if(arr[i]>arr[i+1]):
                not_changed = False
                tmp = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = tmp
        if not_changed is True:
            break
        else:
            #print(arr)
            not_changed = True
            size -= 1

if __name__ == "__main__":
    arr = [ 5, 1, 3, 2, 7, 11, 15, 13, 10, 8 ]
    bubble_sort(arr, len(arr))
    print(arr)