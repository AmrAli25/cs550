from cs50 import get_int
from cs50 import get_string

# Get Credit number
num = get_string("Number:")
# Check the length of the card
if len(num) >= 13:
    # Check if is it American Express
    if str(34) in num or str(37) in num:
        print("AMEX")
    # Check if is it Master card
    elif str(51) in num or str(52) in num or str(53) in num or str(54) in num or str(55) in num:
        print("MASTERCARD")
    # Check if is it 
    else:
        print("VISA")
else:
    print("INVALID")
