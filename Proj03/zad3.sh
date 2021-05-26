#!/bin/bash
if [ "$#" -lt 2 ]; then
	echo "Usage: zad3.sh SEARCH_FILE START_DIRECTORY"
	exit
else
	SEARCH_FILE=$1
	DIRECTORY=$2
	IS_CHILD_PROCESS=$3
fi

PID_LIST=
for dir in $(find "$DIRECTORY" -maxdepth 1 -mindepth 1 -type d )
do
	./zad3.sh $SEARCH_FILE $dir "TRUE" &
	PID_LIST+=("$!")
done

FILES_FOUND=0
for file in $(find "$DIRECTORY" -maxdepth 1 -mindepth 1 -type f -printf "%f\n")
do
	if [ "$file" == "$SEARCH_FILE" ]; then
		echo "$DIRECTORY/$file"
		FILES_FOUND=$((FILES_FOUND+1))
	fi
done

for pid in "${PID_LIST[@]}"
do
	if [ "$pid" ]; then
	    wait "$pid"
	    FILES_FOUND=$((FILES_FOUND+$?))
	fi
done

if [ -z "$IS_CHILD_PROCESS" ]
then
	if [ "$FILES_FOUND" -eq 0 ]; then
	    echo "Plikow o nazwie "$SEARCH_FILE" nie znaleziono."
	 else
		echo "Total: $FILES_FOUND"
	fi
fi

exit "$FILES_FOUND"
