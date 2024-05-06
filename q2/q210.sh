function contains_only_123 {
    local number=$1
    local pattern="^[123]+$"
    if [[ $number =~ $pattern ]]; then
        return 0 # Number contains only 1, 2, and 3
    else
        return 1 # Number contains other digits
    fi
}

# Loop through all 3-digit numbers
for (( i=100; i<=999; i++ )); do
    if contains_only_123 "$i"; then
        printf "$i   "
    fi
done