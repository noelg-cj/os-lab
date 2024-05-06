#!/bin/bash
bin_number="$1"
hex_number=$(printf "%x" "$((2#$bin_number))")
dec_number=$(printf "%d" "$((2#$bin_number))")
echo "Binary Number: $bin_number"
echo "Hex Number: $hex_number"
echo "Decimal Number: $dec_number"