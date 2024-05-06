def create_set():
    my_set = set()
    while True:
        num = int(input("Enter a number (or enter -1 to stop): "))
        if num == -1:
            break
        my_set.add(num)
    return my_set

def add_element(s, num):
    s.add(num)
    print(s)

def remove_element(s, num):
    if num in s:
        s.remove(num)
        print(s)
    else:
        print("Element not found")

def search_element(s, num):
    if num in s:
        print("Element is present")
    else:
        print("Element is not present")

def set_size(s):
    print("Size of set:", len(s))

def set_union(s1, s2):
    union_set = s1.union(s2)
    print("Union set:", union_set)

def set_intersection(s1, s2):
    intersection_set = s1.intersection(s2)
    print("Intersection:", intersection_set)

def set_difference(s1, s2):
    difference_set = s1.difference(s2)
    print("Difference:", difference_set)

def is_subset(s1, s2):
    if s1.issubset(s2):
        print("Yes, subset exists")
    else:
        print("No, subset does not exist")

# Create sets A and B
print("Create set A")
A = create_set()
print("A =", A)

print("\nCreate set B")
B = create_set()
print("B =", B)

while True:
    print("\nMain Menu")
    print("1. Add Element")
    print("2. Remove Element")
    print("3. Searching")
    print("4. Size of Set")
    print("5. Union")
    print("6. Intersection")
    print("7. Difference")
    print("8. Check Subset")
    print("9. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        set_choice = input("In which set do you want to add the element A/B: ").upper()
        num = int(input("Enter the element to be added in the set: "))
        if set_choice == 'A':
            add_element(A, num)
        elif set_choice == 'B':
            add_element(B, num)
    elif choice == 2:
        set_choice = input("From which set do you want to remove the element A/B: ").upper()
        num = int(input("Enter the element to be removed from the set: "))
        if set_choice == 'A':
            remove_element(A, num)
        elif set_choice == 'B':
            remove_element(B, num)
    elif choice == 3:
        set_choice = input("In which set do you want to search the element A/B: ").upper()
        num = int(input("Enter the element to be searched in the set: "))
        if set_choice == 'A':
            search_element(A, num)
        elif set_choice == 'B':
            search_element(B, num)
    elif choice == 4:
        set_choice = input("For which set do you want to find the size A/B: ").upper()
        if set_choice == 'A':
            set_size(A)
        elif set_choice == 'B':
            set_size(B)
    elif choice == 5:
        set_union(A, B)
    elif choice == 6:
        set_intersection(A, B)
    elif choice == 7:
        set_difference(A, B)
    elif choice == 8:
        is_subset(A, B)
    elif choice == 9:
        break
    else:
        print("Invalid choice. Please try again.")

