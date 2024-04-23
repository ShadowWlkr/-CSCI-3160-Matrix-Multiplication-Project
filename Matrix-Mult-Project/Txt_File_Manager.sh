#!/bin/bash

# Check if directories exist and delete them
for num in 128 256 512
do
    if [[ -d "$num" ]]; then
        rm -r "$num"
    fi
done

# Create directories if they don't exist
mkdir -p {128,256,512}/{int,float}

# Loop over txt files in the current directory
for file in *.txt
do
    # Check if file name contains 128, 256 or 512
    for num in 128 256 512
    do
        if [[ $file == *"$num"* ]]; then
            # Check if file name contains 'int' or 'float'
            if [[ $file == *"int"* ]]; then
                mv "$file" "$num/int/"
            elif [[ $file == *"float"* ]]; then
                mv "$file" "$num/float/"
            fi
        fi
    done
done

