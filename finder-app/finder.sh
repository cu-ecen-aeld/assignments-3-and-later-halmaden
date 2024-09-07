#!/bin/sh
# Author Haluk Madencioglu
# For ECEA5305 Assignment1
FILESDIR=$1
SEARCHSTR=$2
ERROR=0
NUMFILES=0
NUMLINES=0




if [ -z $FILESDIR ] 
then
	echo "The first argument is required (a directory name)"
	ERROR=1
fi

if [ -z $SEARCHSTR ] 
then 
	echo "The second argument is required (search string)"
	ERROR=1
fi

if [ ! -d $FILESDIR ] 
then
	echo "The first argument must be a valid directory name"
	ERROR=1
fi

if [ $ERROR -gt 0 ]
then 
exit 1
fi

NUMFILES=`grep -rl $SEARCHSTR $FILESDIR | wc -l`
NUMLINES=`grep -r $SEARCHSTR $FILESDIR | wc -l`
echo  "The number of files are $NUMFILES and the number of matching lines are $NUMLINES"

exit 0
