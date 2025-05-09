import csv
import sys


def main():

    if len(sys.argv) != 3:
        print("Usage python dna.py <argv1> <argv2>")
        sys.exit(1)

    rows = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)

    with open(sys.argv[2]) as file:
        sequence = file.read()

    rows2 = []
    for row in rows:
        result = []
        for subsequence in row:
            if subsequence != "name":
                match_length = longest_match(sequence, subsequence)
                result.append(match_length)
        rows2.append(result)

    for i, row in enumerate(rows):
        str_values = [int(row[subsequence]) for subsequence in row if subsequence != "name"]
        if str_values == rows2[i]:
            print(f"{row["name"]}")
            return

    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
