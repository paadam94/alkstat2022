#!/bin/bash

DIR=`pwd`

pushd .. > /dev/null
python checker.py sol=$DIR/release/$1.bin lang=binary problem=$1
popd > /dev/null
