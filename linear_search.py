def accept_array(A):
    n = int(input("Enter total no. of student:"))
    for i in range(n):
        x = int(input("enter the roll no. of student"))
        A.append(x)
    print("Data accepted!!")
    return n

A = []
n = accept_array(A)

def Linear_Search(A,n,x) :
   for i in range(n) :
      if(A[i] == x) :
         return i    
   return -1 

x = int(input("enter element to be searched:"))
n = Linear_Search(A,n,x)
print("element found at index: ",n)

def Sentinel_Search(A,n,X) :
   last = A[n-1]
   i = 0
   A[n-1] = X   
   while(A[i] != X) :
      i  = i  +1
   A[n-1] = last
   if( (i < n-1) or (X == A[n-1]) ) :
      return i   
   else :
      return -1   
   
p = Sentinel_Search(A,n,x)
print("element found at index:", p)

