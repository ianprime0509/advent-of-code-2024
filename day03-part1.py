import re

with open("day03.txt") as input_file:
    data = input_file.read()

mul = re.compile(r"mul\((\d+),(\d+)\)")

result = 0
for match in mul.finditer(data):
    result += int(match[1]) * int(match[2])
print(result)
