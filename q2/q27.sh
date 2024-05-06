#!/bin/bash

echo "Enter n: "
read n

for (( i = 0; i <= n; i++ )); do
	for (( j = 0; j < i; j++ )); do
		printf "$i "
	done
	printf "\n"
done
