def longest_word(s):
    words = s.split()
    return max(words, key=len)

def char_frequency(s, char):
    return s.count(char)

def is_palindrome(s):
    s = s.lower()
    return s == s[::-1]

def first_appearance_index(s, substring):
    return s.find(substring)

def word_occurrences(s):
    words = s.split()
    word_count = {}
    for word in words:
        word_count[word] = word_count.get(word, 0) + 1
    return word_count

input_string = "python programming is fun and python is versatile"

print("Word with the longest length:", longest_word(input_string))

char_to_check = 'p'
print("Frequency of " , char_to_check,":", char_frequency(input_string, char_to_check))

print("Is palindrome:", is_palindrome(input_string))

substring_to_find = 'python'
print("Index of first appearance of", substring_to_find, ":", first_appearance_index(input_string, substring_to_find))

print("Word occurrences:", word_occurrences(input_string))
