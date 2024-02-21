#!/bin/bash

# basic SH script to send executables directly to processor over ethernet using ssh 
# files land in /media/bin

# tested using test.py

# Access command-line argument (file path)
filename="$1"

echo "Pass filename of program you want to transfer to PS: $filename"

scp $filename root@169.254.10.0:/media/bin
