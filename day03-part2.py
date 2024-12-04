import re

with open("day03.txt") as input_file:
    data = input_file.read()

mul = re.compile(r"mul\((\d+),(\d+)\)|(do|don't)\(\)")

result = 0
mul_enabled = True
for match in mul.finditer(data):
    command = match[3] or "mul"
    match command:
        case "mul":
            if mul_enabled:
                result += int(match[1]) * int(match[2])
        case "don't":
            mul_enabled = False
        case "do":
            mul_enabled = True
print(result)
