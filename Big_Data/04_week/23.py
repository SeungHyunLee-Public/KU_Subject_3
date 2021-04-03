first_value = 0
second_value = 0

for i in range(1, 10):
    if i == 5:
        continue
        first_value = i
    if i == 10:
        break
        second_value = i

print(first_value + second_value)
