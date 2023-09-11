#!/bin/sh

FILE=./binary-tree

if [ -f "$FILE" ]; then
    rm $FILE
fi

make
$FILE