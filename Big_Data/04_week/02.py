a = 3.5
b = int(3.5)
print("(가) : ", a ** ((a // b) * 2))

print("(나) : ", ((a - b) * a) // b)

b = (((a - b) * a) % b)
print("(다) : ", b)

print("(라) : ", (a * 4) % (b * 4))
