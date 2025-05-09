names = {
    "johny": "81.99389-7745",
    "camila": "81.97329-7979"
}
name = input("Name: ").lower()
if name in names:
    print(f"You've found {name.capitalize()}! Here's the number: {names[name]}")
else:
    print("Not found.")
