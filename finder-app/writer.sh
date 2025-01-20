#!/bin/bash

#################################################
#Accept runtime arguments
#1. writefile : Full path to a file
#2. writestr : Text string to write in the file

#ret -1 : Parameter missing


#Create or overwrite a file


# ex. writer.sh /tmp/aesd/assigment1/sample ios
##################################################

# Check number of parameters received
if [ $# -ne 2 ]; then
	echo "Parameter missing"
	exit 1
fi

# Get input parameters
writefile=$1
writestr=$2

# Check if directory exists
dir_name=$(dirname "$writefile")
if [ ! -d "$dir_name" ]; then
	#echo "Directory '$dir_name' does not exist."
	mkdir -p "$dir_name"
	
	if [ $? -ne 0 ]; then
		echo "Failed to create directory"
		exit 1
	fi
fi

# Create/overwrite the file with the content
echo "$writestr" > "$writefile"

# end
