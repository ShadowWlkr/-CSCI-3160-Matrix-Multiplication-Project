#!/bin/bash

# Check if directory 128 exists and delete it
if [[ -d "128" ]]; then
    rm -r "128"
fi

# Create directory 128 if it doesn't exist
mkdir -p 128/{int,float}

# Loop over txt files in the current directory
for file in *.txt
do
    # Check if file name contains 128
    if [[ $file == *"128"* ]]; then
        # Check if file name contains 'int' or 'float'
        if [[ $file == *"int"* ]]; then
            mv "$file" "128/int/"
        elif [[ $file == *"float"* ]]; then
            mv "$file" "128/float/"
        fi
    fi
done

