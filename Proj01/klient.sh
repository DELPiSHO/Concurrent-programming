#!/bin/bash
echo "Podaj liczbe:"
read LICZBA
echo $LICZBA > dane.txt
while true; do
	WYNIK=$(cat wynik.txt)
	if [ ! -z "$WYNIK" ]; then
		echo "" > wynik.txt
		echo "Wynik: $WYNIK"
		break
	fi
done
