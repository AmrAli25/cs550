from cs50 import get_string
import string
# Get the text
text = get_string("Text:")
# Declare variables
letters = 0
words = 1
sentences = 0
# find letters and words and sentences
for letter in text:
    if letter == '.' or letter == '!' or letter == '?':
        sentences += 1
    elif letter in string.punctuation:
        continue
    elif letter in string.whitespace:
        words += 1
    else:
        letters += 1
# find Coleman-Liau index
L = letters * 100 / words
S = sentences * 100 / words
index = round(0.0588 * L - 0.296 * S - 15.8)
# print the result
if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")