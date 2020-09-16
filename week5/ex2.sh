#!bin/bash
echo 0 > num.txt


if ln num.txt num.txt.lock #Fix
    then
    while true
    do
        num=$(tail -n 1 num.txt)
        echo "$((num+1))" >> num.txt
    done

    rm numbers.lock
fi

#Race condition crashed one of processes in a few seconds after the staring the second time.
#Critical region is num.txt.

