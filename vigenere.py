alpha = "abcdefghijklmnopqrstuvwxyz"

key = input("Enter Key:\n>> ")
text = input("Enter Text:\n>> ")
new_key = ""

for i in range(len(text)):
    new_key += key[i % len(key)]

encrypted = ""
for i in range(len(text)):
    encrypted += alpha[ (alpha.index(text[i]) + alpha.index(new_key[i])) % 26]
print(encrypted)
