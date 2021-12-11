
from cs50 import get_int
# Get the height :
h = get_int("Height:")
# Check if the height is in range:
while h < 1 or h > 8:
    print("INVALID")
    h = get_int("Height:")
# Print the pyramid
for i in range(1, h + 1):
    for j in range(1, h + 1):
        # Print the left pyramid
        if j > (h - i):
            print("#", end="")
        else:
            print(" ", end="")
        if j == h:
            print(" ", "#" * i, end="")
    print()
