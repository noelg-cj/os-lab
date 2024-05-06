#!/bin/bash

echo "Input left and right:"
read left
read right

for (( i = left; i <= right; i++ )); do
	sum=0
	k=i
	len=0
	while (( k > 0 )); do
		len=len+1
		k/=10
	done
	k=i
	while (( k > 0 )); do
		sum=$(( sum+(k%10)**len ))
		k=k/10
	done
	if (( sum == i )); then
		printf $i
	fi
done
