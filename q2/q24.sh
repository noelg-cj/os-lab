#!/bin/bash

if [ $1 -lt $2 -a $1 -lt $3 ]
then
	echo "$1 is the smallest number"

elif [ $2 -lt $3 ] 
then
	echo "$2 is the smallest number"

else 
	echo "$3 is the smallest number"
fi