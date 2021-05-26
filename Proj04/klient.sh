#!/bin/bash
SerwerAddress=$1
Argument=$2
KlientFIFO="$HOME/klientFIFO"
SerwerFIFO="/home/$SerwerAddress/serwerFIFO"

if [ -p $KlientFIFO ]; then
    rm $KlientFIFO
fi

mkfifo $KlientFIFO
chmod 777 $KlientFIFO

echo $KlientFIFO $Argument > $SerwerFIFO

read Responce < $KlientFIFO
echo $Responce
rm $KlientFIFO
exit 0
