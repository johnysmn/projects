from cs50 import get_float

while True:
    cash = get_float("Change: ")
    if cash > 0:
        cash *= 100
        break

quarters = 0
dimes = 0
nickels = 0
pennies = 0

while cash >= 25:
    quarters += 1
    cash -= 25

while cash >= 10:
    dimes += 1
    cash -= 10

while cash >= 5:
    nickels += 1
    cash -= 5

while cash >= 1:
    pennies += 1
    cash -= 1

print(f"{quarters + dimes + nickels + pennies}")

