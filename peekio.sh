if [ $# -lt 2 ]
then
    echo "./peekio.sh <problem> <number>"
    echo "e.g. ./peekio.sh die3 25"
else
    echo "-- IN  --"
    cat ../problems/$1/io/$2.in
    echo "-- OUT --"
    cat ../problems/$1/io/$2.out
fi
