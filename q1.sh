
if [ "$#" -eq 0 ]; then
    echo "No arguments found"
    exit 1
fi

for file in "$@"; do
    if [ -e "$file" ]; then
        awk '{print toupper($0)}' "$file" > "${file%.txt}.uppercase.txt"
    else
        echo "File does not exist!"
    fi
done
