
if [ "$#" -eq 0 ]; then
    echo "No arguments found"
    exit 1
fi

args=("$@")

for ((i=${#args[@]}-1; i>=0; i--)); do
    echo "${args[i]}"
done