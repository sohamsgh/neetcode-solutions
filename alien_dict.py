import numpy as np

def dic_order(words):
    mdict = {}
    countdict = {}
    count = 0
    for word in words:
        # in python we can iterate over letters of a string directly
        for letter in word:
            if not letter in adict:
                mdict[letter] = count
                countdict[letter] = 0
                count +=1
    mat = np.zeros((count, count))
    for i in range(0,len(words) -1):
        w1 = words[i]
        w2 = words[i+1]
        print (w1, w2)
        for l1, l2 in zip(w1, w2):
            if l1 != l2:
                if ( not mat[mdict[l1], mdict[l2]]):
                    mat[mdict[l1], mdict[l2]]
                    countdict[l2] += 1
                break
    order = sorted(countdict, key=countdict.get)
    return order

Input = ["wrt","wrf","er","ett","rftt"]
Output =  "wertf"
dict_order(Input)
