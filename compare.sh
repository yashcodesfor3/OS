#!/bin/bash                   
# tells system to use Bash shell
echo "Enter first number:"    # prompt user
read num1                     # store first number
echo "Enter second number:"   # prompt again
read num2                     # store second number

if [ $num1 -gt $num2 ]        # check if num1 greater
then
    echo "$num1 is greater than $num2"
elif [ $num1 -lt $num2 ]      # check if num1 less
then
    echo "$num1 is less than $num2"
else                           # otherwise equal
    echo "Both numbers are equal"
fi                             # end if
