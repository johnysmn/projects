import csv

name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv", "a") as file:
    wtr = csv.DictWriter(file, fieldnames=["name", "number"])
    wtr.writerow({"name": name, "number": number})

