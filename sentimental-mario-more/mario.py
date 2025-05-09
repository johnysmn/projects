import cs50

while True:
    height = cs50.get_int("Height: ")
    if height > 0 and height <= 8:
        break

space = height
brick = 0

while space != 0:
    space -= 1
    brick += 1
    print(" " * space, end="")
    print("#" * brick,"", "#" * brick)
