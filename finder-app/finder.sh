#!/bin/bash

#################################################
#Accept runtime arguments
#1. filesdir : Path to a directory
#2. searchstr :Text string to search for

#ret -1 : Parameter missing

#ret -1 : Directory doesn't exist

#Print "The number of files are X and the number of matching lines are Y"
# - X : number of files in the directory and subdirectories
# - Y : number of matching lines found in the files


# ex. finder.sh /tmp/aesd/assigment1 linux
##################################################



# Check number of parameters received
if [ $# -ne 2 ]; then
	echo "Parameter missing"
	exit 1
fi

# Assign variables
filesdir=$1  #assign first argument
searchstr=$2 #assign second argument

# Check if directory exists with -d
if [ ! -d "$filesdir" ]; then
	echo "Directory does not exist"
	exit 1
fi

# Search for the string in the files inside the directory
file_count=$0
match_count=$0

# Finds files -type f , and counts the number of files wc -l
file_count=$(find "$filesdir" -type f | wc -l)
# grep searches for a pattern, -r recursively
match_count=$(grep -r "$searchstr" "$filesdir" | wc -l)

if [ $? -ne 0 ]; then
	echo "String was not found in any file"
else
	echo "The number of files are $file_count and the number of matching lines are $match_count"
fi
