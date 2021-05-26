#!/bin/bash
trap "" SIGHUP SIGTERM SIGCHLD
trap "exit 0" SIGUSR1

SerwerFIFO="$HOME/serwerFIFO"

if [ -p $SerwerFIFO ]; then
    rm $SerwerFIFO
fi

mkfifo $SerwerFIFO
chmod 777 $SerwerFIFO

function actual_request {
    local KlientFIFO=$1
    local RequestARG=$2
    echo $((($RequestARG*$RequestARG)-10)) > $KlientFIFO
}

while true; do
    read Request < $SerwerFIFO
    if [ -n "$Request" ]; then
        RequestARG=($Request)
        KlientFIFO=${RequestARG[0]}
        NumberARG=${RequestARG[1]}
        actual_request $KlientFIFO $NumberARG &
    fi
done
exit 0
