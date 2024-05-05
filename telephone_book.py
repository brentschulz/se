def initializeHashtable():
    size=int(input('Enter size of hash table:'))
    hashtable =[[-1, 'null'] for i in range(size)]
    print('Hashtable of size',size,'is succesfully created.....')
    print(' ')
    return(size,hashtable)

choice =1
while(choice!=3):
    print('menu')
    print('1.Linear probing')
    print('2.Double Hashing')
    print('3.Exit\n')
    choice = int(input('Enter your choice:'))
    print()
    count =0
    
    
    if choice ==1:
        size,hashtable = initializeHashtable()
        choice1 =1
        while(choice1 != 4):
             print('\n* Menu for linear probing *')
             print('   1.Insert')
             print('   2.Search')
             print('   3.Display')
             print('   4.Back\n')
             choice1=int(input('Enter your choice:'))
             print()
             if choice1 == 1:
                 if(count == size):
                     print('Hash table is Full......')
                 else:
                     number = int(input('Enter number ;'))
                     name = input('Enter Name :')
                     hashvalue = number % size
                     while(hashtable[hashvalue][0] !=-1):
                         print('\collsion has occured .....')
                         print('Now,calculating new hash value by using linear probing')
                         hashvalue =(hashvalue + 1)%size
                     hashtable[hashvalue][0] = number
                     hashtable[hashvalue][1] = name
                     count+=1
                     print('data is succesfully inserted in the hashtable ')
                     print('total inserted record=',count)
                     print(' ')
             if choice1 == 2:
                 number = int(input('Enter number to search;'))
                 hashvalue = number % size
                 comparision = 0
                
                 while(hashtable[hashvalue][0] != number and comparision<size):
                     hashvalue =(hashvalue +1)%size
                     comparision +=1
                     
                 if comparision < size:
                     print('The number', number,'is found at location',hashvalue,'with total comparisions',comparision+1)
                 else:
                     print('the number is not found in the hashtable...with comparision',comparision+1)
             if choice1 ==3:
                 for i in range(size):
                     print('Hash value ',i,' ->',hashtable[i])
                     
                    
    if choice==2:
        size,hashtable = initializeHashtable()
        choice1 =1
        
        while(choice1 != 4):
             print('\n* Menu for double hashing *')
             print('   1.Insert')
             print('   2.Search')
             print('   3.Display')
             print('   4.Back\n')
             choice1=int(input('Enter your choice:'))
             print()
             if choice1 == 1:
                 if(count == size):
                     print('Hash table is Full......')
                 else:
                     number = int(input('Enter number ;'))
                     name = input('Enter Name :')
                     hashvalue = number % size
                     while(hashtable[hashvalue][0] !=-1):
                         print('\collsion has occured .....')
                         print('Now,calculating new hash value by using Double Hashing probing')
                         hashvalue1= number % size
                         prime =int(input("\nEnter prime number less than size of hash table:"))
                         for i in range(size):
                         	hashvalue2 =(prime-(number % prime))
                         	hashvalue3 =(hashvalue1 + i* hashvalue2) % size
                         	i=i+1
                         	hashvalue=hashvalue3
                     hashtable[hashvalue][0] = number
                     hashtable[hashvalue][1] = name
                     count +=1 
                 print('Data is successfully inserted in the hash table')
                 print('Total inserted record=',count)
             if choice1 == 2:
                 number = int(input('enter number to search: '))
                 hashvalue = number % size
                 comparision = 0
                 while(hashtable[hashvalue][0] != number and comparision<size):
                     hashvalue1 = number % size
                     prime =int(input("enter prime number less than size of hash table :"))
                     for i in range(size):
                     	hashvalue2 =(prime-(number % prime))
                     	hashvalue3 =(hashvalue1 + i* hashvalue2) % size
                     	hashvalue =hashvalue3
                     	comparision +=1
                   
                 if comparision < size:
                     print('The number', number,'is found at location',hashvalue,'with total comparisions',comparision+1)
                 else:
                     print('the number is not found in the hashtable...with comparision',comparision+1)
             if choice1 ==3:
                 for i in range(size):
                     print('Hash value ',i,' ->',hashtable[i])
    if choice==3:
	    break;


