#!/bin/bash

echo "Enter n: "
read n

for (( i = 1; i <= 2*n-1; i++ )); do 
	for (( j = 1; j <= 2*n-1; j++ )); do
		if [[ i -le n ]]; then
			if [[ j -ge n-i+1 && j -le n+i-1 ]]; then
				printf "* "
			else
				printf "  "
			fi
		else
			if [[ j -ge i-n+1 && j -le 3*n-i-1 ]]; then
				printf "* "
			else 
				printf "  "
			fi
		fi
	done
	printf "\n"
done
