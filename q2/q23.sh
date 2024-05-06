#!/bin/sh
if [ $1 -lt 1500 ]
then
	HRA=$(( 10*$1/100 ))
	DA=$(( 90*$1/100 ))
	TOTAL=$(( HRA+DA+$1 ))
	echo "$TOTAL"
fi 

if [ $1 -ge 1500 ] 
then 
	HRA=500
	DA=$(( 98*$1/100 ))
	TOTAL=$(( HRA+DA+$1 ))
	echo "$TOTAL"
fi