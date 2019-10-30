# A simple Python program 
# bucket sort an array of elements

def insertionSort(arr): 
    for i in range(1, len(arr)): 
        up = arr[i] 
        j = i - 1
        while j >=0 and arr[j] > up:  
            arr[j + 1] = arr[j] 
            j -= 1
        arr[j + 1] = up      
    return arr
              
def bucketSort(x): 
    arr = [] 
    slot_no = 10 
    for i in range(slot_no): 
        arr.append([]) 

    for j in x: 
        index_b = int(slot_no * j)  
        arr[index_b].append(j) 
      
    for i in range(slot_no): 
        arr[i] = insertionSort(arr[i]) 
          
    k = 0
    for i in range(slot_no): 
        for j in range(len(arr[i])): 
            x[k] = arr[i][j] 
            k += 1
