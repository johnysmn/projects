from cs50 import get_string

text = get_string("Text: ")

letters = 0
words = 1
sentences = 0

for i in text:
    if i.isalpha():
        letters += 1

for j in text:
    if j.isspace():
        words += 1

for j in text:
    if j == "!" or j == "?" or j == ".":
        sentences += 1

L = letters / words * 100
S = sentences / words * 100
index = 0.0588 * L - 0.296 * S - 15.8

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")

