# 6. Write a shell script that accepts a file name, starting and ending line numbers as arguments and displays all the lines between the given line numbers

#!/bin/sh

if [ $# -ne 3 ]
then 
	printf "enter a file name, starting and ending line numbers" 
else
	if [ -f $1 ]
	then
		sed -n "$2, $3p" $1
		
	else
		printf "file not exists\n"
	fi
fi



