def create():
	my_set=[]
	ch="y"
	while(ch=='y'):
		print("Enter the Number:")
		num=int(input())
		my_set.append(num)
		print("\n Do you want to enter more number?(y/n)")
		ch=input()
	return my_set
def add(s,num):
	print("Enter the position do you want to insert the element:")
	pos=int(input())
	for i in range(len(s)):
		if(i==pos):
			s=s[:pos]+[num]+s[pos:]
	print(s)
def remove(s,num):
	count=0
	for i in range(len(s)):
		if(s[i]==num):
			count=count+1
	if(count>=1):
		pos=A.index[num]
		new_s=s[:pos]+s[pos+1:]
		print(new_s)
	else:
		print("Element not found")
def contains(A,num):
	found=False
	for i in range(len(A)):
		if(A[i]==num):
			found=True
			break
		else:
			found=False
	return found
def size(A):
	count=0
	for i in range(len(A)):
		count=count+1
	return count
def union(A,B):
	c=list({i:i for i in A+B}.values())
	print("Union set:",c)
def intersection(A,B):
	c=[i for i in A if i in B]
	print("Intersection: ",c)
def diff(A,B):
	c=[element for element in A if element not in B]
	print("Difference:",c)
def subset(A,B):
	status=False
	if(all(i in A for i in B)):
		status=True
	if(status):
		print("Yes subset exists")
	else:
		print("No subset")
A={}
print("\n Create set A")
A=create()
print("A=",A)
B={}
print("\n Create set B")
B=create()
print("B=",B)
while(True):
	print("Main manue")
	print("1.Add Element")
	print("2.Remove element ")
	print("3.Searching")
	print("4.size of set")
	print("5.Union")
	print("6.Intersection")
	print("7.Difference")
	print("8.Check Subset")
	print("9.Exit")
	ch=int(input())
	if ch==1:
		print("In which set do you want to add the element A/B:")
		c=input()
		if(c=='A'or c=='a'):
			print("A=",A)
			print("enter the element to be added in the set:")
			num=int(input())
			add(A,num)
		if(c=='B'or c=='b'):
			print("B=",B)
			print("enter the element to be added in the set:")
			num=int(input())
			add(B,num)
	elif ch==2:
		print("A=",A)
		print("Enter the element to be removed in the set:")
		num=int(input())
		print(A)
		remove(A,num)
	elif ch==3:
		print("A=",A)
		print("Enter the element to be searched in the set:")
		num=int(input())
		if(contains(A,num)):
			print("Element is present")
		else:
			 print("Element is not present")
	elif ch==4:
		print("A=",A)
		print("The size of set: ",size(A))
	elif ch==5:
		print("A=",A)
		print("B=",B)
		union(A,B)
	elif ch==6:
		print("A=",A)
		print("B=",B)
		intersection(A,B)
	elif ch==7:
		print("A=",A)
		print("B=",B)
		diff(A,B)
	elif ch==8:
		print("A=",A)
		print("B=",B)
		subset(A,B)
	else:
		break
