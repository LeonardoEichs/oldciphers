alphabet = "abcdefghijklmnopqrstuvwxyz"
shift = int(input("Shift by how much?\n>> "))

def cipher(s):
    answ = ""
    for c in s:
        if c == " ":
            answ += " "
            continue
        answ += alphabet[(alphabet.index(c) + shift) % 26]
    return answ

inp = -1
while(inp != 0):
    inp = input("Type text\n>> ")
    print(">> " + cipher(inp))
