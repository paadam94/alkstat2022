#!/bin/bash

DIR=`pwd`
TMP=/tmp/alkstattest

function run {
    echo "NUM;INPUT;RESULT;SOLUTION;DIFF" > $TMP
    IODIR=../problems/$1/io/
    for FILE in `ls $IODIR | sort -n`
    do
	NUM=${FILE%.in}
	FULLPATH=$IODIR$FILE
	if [[ $FULLPATH == *.in ]]
	then
	    INFILE=$FULLPATH
	    OUTFILE=${INFILE%.in}.out
	    BIN=release/$1.bin
	    echo -ne $NUM ";" >> $TMP
	    cat $INFILE | tr '\n' ';' >> $TMP
	    RESULT=`$BIN < $INFILE` >> $TMP
	    echo -n $RESULT >> $TMP
	    echo -n ";" >> $TMP
	    SOLUTION=`cat $OUTFILE`
	    echo -n $SOLUTION >> $TMP
	    echo -n ";" >> $TMP
	    echo $RESULT - $SOLUTION | bc >> $TMP
	    
	    echo >> $TMP
	fi
    done
    column --table --separator ";" $TMP
}

if [ -z $1 ]
then
   echo "Give the name of the program (w/o extension). exiting..."
else run $1
fi


