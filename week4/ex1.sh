#!/bin/bash
gcc -o ex1 ex1.c
for i in {1..10}
do
    ./ex1
done
rm ex1

# Output:
#Hello from parent 2924
#Hello from child 2925
#Hello from parent 2926
#Hello from child 2927
#Hello from parent 2928
#Hello from child 2929
#Hello from parent 2930
#Hello from child 2931
#Hello from parent 2932
#Hello from child 2933
#Hello from parent 2934
#Hello from child 2935
#Hello from parent 2936
#Hello from child 2937
#Hello from parent 2938
#Hello from child 2939
#Hello from parent 2940
#Hello from child 2941
#Hello from parent 2942
#Hello from child 2943

# Each time we run a program, we create a new fork from the initial one, so we get new PID.
# When we create a new child by fork(), we give it new PID, which is in this case parentPID + 1.
# PID is always unique
# Also if fork() returns 0, we are in the initial(in our program) fork,
# while in the other case we are in the cild fork.