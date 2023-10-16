import random as rd

def Counting_Sort(Array,n,exp = 0):
    '''base n'''
    D = [[] for i in range(n)]
    for i in Array:
        idx = (i//n**exp) % n
        D[idx].append(i)
    i = 0
    for chain in D:
        for num in chain:
            Array[i] = num
            i += 1


def Radix_Sort(Array):
    '''base n'''
    exp = 0
    n = len(Array)
    maximum = max(Array)
    while maximum > 0:
        Counting_Sort(Array,n,exp)
        exp += 1
        maximum /= n

for i in range(5):
    a = [9998,9937,2192,8739,2100,9911,9999,10000,10001,1000000]
    b = [9998,9937,2192,8739,2100,9911]
    Radix_Sort(a)
    print(a)