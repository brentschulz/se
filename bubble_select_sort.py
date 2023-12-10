
arr =[12,13,7,6,2,8]
def bubble_sort(arr):
    for j in range(len(arr)-1):
        for i in range(len(arr)-1):
            if arr[i]> arr[i+1]:
                temp = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = temp
        j+=1
bubble_sort(arr)
print(arr)

arr1 = [3,17,8,10,4,6,6,13]
def select_sort(arr1):
    for i in range(len(arr1)):

        for j in range(i, len(arr1)):
            if arr1[i] > arr1[j]:
                arr1[i], arr1[j] = arr1[j], arr1[i]
            j+=1
        i+=1
select_sort(arr1)
print(arr1)

