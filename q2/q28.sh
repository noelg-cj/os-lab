#!/bin/bash

read password

if [[ "$password" == *_* ]]
then
	if [[ "$password" =~ [A-Z] && "$password" =~ [a-z] ]]
	then
		if [[ "$password" =~ [0-9] ]]
		then
			if [[ ${#password} -ge 8 ]]
			then
				echo "Valid password"
			else
				echo "Length of password should be greather than 8."
			fi
		else
			echo "Invalid password - should contain atleast one digit."
		fi
	else
		echo "Invalid password - should contain atleast one small letter and one capital letter"
	fi

else
	echo "Invalid password - should contain an underscore"
fi
