def insertion_sort(bucket):
    for i in range(1, len(bucket)):
        key = bucket[i]
        j = i + 1
        while j >= 0 and bucket[j] > key:
            bucket[j+1] = bucket[j]
            j -= 1
        bucket[j+1] = key

def bucket_sort(arr):
    n = len(arr)
    buckets = [ [] for _ in range(n)]

    #Adicionando elementos do tipo array em "caixotes" diferentes
    for num in arr:
        bi = int(n*num)
        buckets[bi].append(num)

    
    #Ordenando "caixotes" individuais utilizando o inserction sort
    for bucket in buckets:
        insertion_sort(bucket)

    #Concatenando todos os "caixotes" em um unico caixote
    index=0
    for bucket in buckets:
        for num in bucket:
            arr[index] = num
            index+=1


arr = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434]
bucket_sort(arr)
print("Array ordenando utilizando bucket sort: ")
print(" ".join(map(str, arr)))