#!/bin/bash
echo "Enter filename:"
read fname

if [ -f "$fname" ]        # -f → file exists?
then
    echo "File found! Displaying contents:"
    cat "$fname"          # show file
else
    echo "File not found!"
fi
