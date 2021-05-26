#!/bin/bash
while true; do
	DANE=$(cat dane.txt)
	if [ ! -z $DANE ]; then
		echo "" > dane.txt
		WYNIK=$(((DANE * DANE)*2))
		echo $WYNIK > wynik.txt
	fi
done
