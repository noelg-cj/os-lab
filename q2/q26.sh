#!/bin/bash

echo "Input left and right:"
read left
read right

for (( i=$left ; i<=$right ; i++ ))
do
	s=0
	a=$i
	l=${#a}
	while [ $a -gt 0 ]
	do
		k=$((a%10))
		s=$((k**l+s))
		a=$((a/10))
	done
	if [ $s -eq $i ]
	then
		echo $i
	fi
done