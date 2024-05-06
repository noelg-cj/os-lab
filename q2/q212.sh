#!/bin/bash

function is_prime {
    local num=$1
    if (( num <= 1 )); then
        return 1
    fi
    for (( i=2; i*i <= num; i++ )); do
        if (( num % i == 0 )); then
            return 1
        fi
    done
    return 0
}

function is_palindrome {
    local num=$1
    local reversed=0
    local original=$num
    while (( num > 0 )); do
        local digit=$(( num % 10 ))
        reversed=$(( reversed * 10 + digit ))
        num=$(( num / 10 ))
    done
    if (( original == reversed )); then
        return 0
    else
        return 1
    fi
}

n=$1
next_prime_palindrome=0

if (( n < 2 )); then
    n=2
fi

while true; do
    (( n++ ))
    if is_prime "$n" && is_palindrome "$n"; then
        next_prime_palindrome=$n
        break
    fi
done

echo "The smallest prime palindrome greater than $1 is: $next_prime_palindrome"
