#!/bin/sh
# Author Haluk Madencioglu
# For ECEA5305 Assignment1
WRITEFILE=$1 
WRITESTR=$2

LASTELEM=""

if [ $# -ne 2 ]
then
echo "Two arguments to be passed: a filename with path and a string"
exit 1
fi

#get the directory - file names as string tokens 
my_array=`echo $WRITEFILE |tr '/' ' '`
#echo $my_array

#the following is just to get the filename as the last token in space sepatated list
for A in $my_array
do
LASTELEM=$A
done


FILENAME=$LASTELEM
#echo $FILENAME

#remove just the filename and the preceding slash
DIRNAME=`echo $WRITEFILE|sed -e "s/\/${FILENAME}//" `

#echo "dir name = $DIRNAME"

# create the directories
mkdir -p $DIRNAME

#put the string in the file under the directory
echo $WRITESTR > "$DIRNAME/$FILENAME" 
exit 0
