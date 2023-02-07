#!/bin/bash

PROBLEMS_PATH="../../problems"

find $PROBLEMS_PATH/*/io -type d | cut -d '/' -f 4 > problems.txt
for f in $(cat problems.txt);
do
    paste <(cat \
		`ls $PROBLEMS_PATH/$f/io/*.in | sort --field-separator="/" --key=6n` \
	   ) \
	  <(cat \
		`ls $PROBLEMS_PATH/$f/io/*.out | sort --field-separator="/" --key=6n` \
	   ) \
	| nl -v 0 \
	     > $f.io
done;
rm problems.txt

