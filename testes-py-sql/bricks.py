while True:
    try:
        n = int(input("Size: "))
        if n > 0:
            break
    except ValueError:
        print("Not integer.")
for _ in range(n):
    print("#" * n)
