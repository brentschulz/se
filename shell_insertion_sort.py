def insertion_sort(arr):
    for i in range(1, len(arr)):
        j = i
        while arr[j - 1] > arr[j] and j > 0:
            arr[j -1], arr[j] = arr[j], arr[j -1]
            j-=1

arr = [12,5,8,16,14,10]
insertion_sort(arr)
print(arr)

def shell_sort(arr):
    size = len(arr)
    gap = size // 2
    while gap > 0:
        for i in range(gap, size):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap = gap //2

shell_sort(arr) 
print(arr)
