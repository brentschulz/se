def longest_word(s):
    # To display the word with the longest length
    words = s.split()
    return max(words, key=len)

def char_frequency(s, char):
    # To determine the frequency of occurrence of a particular character in the string
    return s.count(char)

def is_palindrome(s):
    # To check whether the given string is palindrome or not
    s = s.lower()
    return s == s[::-1]

def first_appearance_index(s, substring):
    # To display the index of the first appearance of the substring
    return s.find(substring)

def word_occurrences(s):
    # To count the occurrences of each word in the given string
    words = s.split()
    word_count = {}
    for word in words:
        word_count[word] = word_count.get(word, 0) + 1
    return word_count

# Example string (replace with your actual string)
input_string = "python programming is fun and python is versatile"

# a) To display word with the longest length
print("Word with the longest length:", longest_word(input_string))

# b) To determine the frequency of occurrence of a particular character in the string
char_to_check = 'p'
print(f"Frequency of '{char_to_check}':", char_frequency(input_string, char_to_check))

# c) To check whether the given string is palindrome or not
print("Is palindrome:", is_palindrome(input_string))

# d) To display the index of the first appearance of the substring
substring_to_find = 'python'
print(f"Index of first appearance of '{substring_to_find}':", first_appearance_index(input_string, substring_to_find))

# e) To count the occurrences of each word in the given string
print("Word occurrences:", word_occurrences(input_string))

