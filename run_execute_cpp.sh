#!/bin/bash
IFS=$'\n'
cpp_executable=a.out #the anme of cpp executable file
cpp_source=$1 #the name of the source code file
#check if there is an input for cpp_source
source_not_empty=1 #if this is 1, there is an input source code file
source_code_exists=0 #if this is 1, the source code file exists
if [ -z "$cpp_source" ]
then
	source_not_empty=0
fi
#check that the source code file exists
if [ $source_not_empty -eq 1 ] && ls | grep -x $cpp_source > /dev/null
then
	source_code_exists=1
fi
#alert - warn that the source code input is empty
if [ $source_not_empty -eq 0 ]
then
	echo "----------"
	echo "Error: there is no input source code file"
	echo "----------"
fi
#alert - warn that the source code input does not exist
if [ $source_not_empty -eq 1 ] && [ $source_code_exists -eq 0 ] 
then
	echo "----------"
	echo "Error: the source code file |$cpp_source| does not exist"
	echo "----------"
fi
#compile the source code
g++ -pthread $cpp_source
if [ $source_code_exists -eq 1 ] && [ $source_not_empty -eq 1 ] && ls | grep -x $cpp_executable > /dev/null
then
	./$cpp_executable
	echo "----------"
	echo "deleting executable a.out"
	rm -rvf $cpp_executable
	echo "----------"
else
	echo "----------"
	echo "Error: cannot compile source code"
	echo "----------"
fi
