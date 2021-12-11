# Find the match for DNA sample
import csv
import sys


def main():

    # Ensure correct writting
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # define the variables
    STRs = []
    persons = []
    # Read the csv file
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        # Read the data from the csv file into a list of dict
        for row in reader:
            persons.append(row)
        # Read the names of STRs in csv file and make it a dict
        STRs = reader.fieldnames[1:]

    STRs_dict = dict.fromkeys(STRs, 0)

    # Read the sequence file
    with open(sys.argv[2]) as txt:
        sequence = txt.readline()

        for STR in STRs:
            # update the STRs with the reapetition of it
            STRs_dict[STR] = update(sequence, STR)

    # check if any one has the same dna as sequences
    for person in persons:
        match = 0
        for STR in STRs:
            if int(person[STR]) != STRs_dict[STR]:
                continue
            match += 1
        if match == len(STRs):
            print(person['name'])
            sys.exit(0)
    print("No match")
    sys.exit(1)

# function to find the repeats


def update(sequence, STR):
    max_repeats = 0
    N = len(STR)
    # loop over the sequence
    for i in range(len(sequence)):
        repeats = 0
        # find the repeat one
        if sequence[i: i + N] == STR:
            repeats += 1
            # find for the whole txt
            while sequence[i: i + N] == sequence[i + N: i + (2 * N)]:
                repeats += 1
                # increase i
                i += N

        if repeats > max_repeats:
            max_repeats = repeats

    return max_repeats


if __name__ == "__main__":
    main()
