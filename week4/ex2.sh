#!/bin/bash
gcc -o ex2 ex2.c
./ex2 &
for i in {1..5}
do
    sleep 5
    pstree
done

# When n was 3, we got in total 8 threads(2^3).
# When n became 5, we got in total 32 threads(2^5).

# n == 5:

# |     \-+= 04944 stepankuznetsov bash ex2.sh
# |       |-+- 04948 stepankuznetsov ./ex2
# |       | |-+- 04950 stepankuznetsov ./ex2
# |       | | |-+- 04956 stepankuznetsov ./ex2
# |       | | | |-+- 04962 stepankuznetsov ./ex2
# |       | | | | |-+- 04970 stepankuznetsov ./ex2
# |       | | | | | \--- 04986 stepankuznetsov ./ex2
# |       | | | | \--- 04982 stepankuznetsov ./ex2
# |       | | | |-+- 04969 stepankuznetsov ./ex2
# |       | | | | \--- 04984 stepankuznetsov ./ex2
# |       | | | \--- 04980 stepankuznetsov ./ex2
# |       | | |-+- 04961 stepankuznetsov ./ex2
# |       | | | |-+- 04971 stepankuznetsov ./ex2
# |       | | | | \--- 04985 stepankuznetsov ./ex2
# |       | | | \--- 04983 stepankuznetsov ./ex2
# |       | | |-+- 04968 stepankuznetsov ./ex2
# |       | | | \--- 04981 stepankuznetsov ./ex2
# |       | | \--- 04979 stepankuznetsov ./ex2
# |       | |-+- 04957 stepankuznetsov ./ex2
# |       | | |-+- 04963 stepankuznetsov ./ex2
# |       | | | |-+- 04973 stepankuznetsov ./ex2
# |       | | | | \--- 04990 stepankuznetsov ./ex2
# |       | | | \--- 04988 stepankuznetsov ./ex2
# |       | | |-+- 04972 stepankuznetsov ./ex2
# |       | | | \--- 04989 stepankuznetsov ./ex2
# |       | | \--- 04987 stepankuznetsov ./ex2
# |       | |-+- 04964 stepankuznetsov ./ex2
# |       | | |-+- 04974 stepankuznetsov ./ex2
# |       | | | \--- 04991 stepankuznetsov ./ex2
# |       | | \--- 04992 stepankuznetsov ./ex2
# |       | |-+- 04975 stepankuznetsov ./ex2
# |       | | \--- 04993 stepankuznetsov ./ex2
# |       | \--- 04994 stepankuznetsov ./ex2
# |       \-+- 04995 stepankuznetsov pstree
