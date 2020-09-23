#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//P.s. I have assumed that processes are already sorted by arrival time, as in life.

int main(){
    // Input
    printf("Write down number of processes:\n");
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * 3 * sizeof(int)); // Create 2d array. i-th j-th element is *(arr + i*2 + j)
    for(int i = 0; i < n; i++){ // Input processes' data
        printf("%d-th process:\n", i);
        int at, bt;
        scanf("%d %d", &at, &bt);
        *(arr + i * 3 + 0) = at;
        *(arr + i * 3 + 1) = bt;
        *(arr + i * 3 + 2) = 0; // FINISHED flag. 0 - not started, 1 - already finished.
    }

    // Create simulation by running processes one-by-one
    int CT = 0, TAT = 0, WT = 0;
    for(int proc = 0; proc < n; proc++){
        int picked_proc = -1;
        int min_ex_time = INT_MAX;
        for(int i = 0; i < n; i++){ // Search for the shortest process to run.
            if(*(arr + i * 3 + 0) > CT) // Search until we found process, which has not arrived yet.
                break;
            
            if((*(arr + i * 3 + 2) == 0/*check if process is not finished yet*/) && (*(arr + i * 3 + 1) < min_ex_time)){
                picked_proc = i;
                min_ex_time = *(arr + i * 3 + 1);
            }
        }
        if(picked_proc == -1){ // There is no arrived processes left yet.
            CT += 1;
            proc--;
            continue;
        }

        CT += *(arr + picked_proc * 3 + 1);
        TAT += CT - *(arr + picked_proc * 3 + 0);
        WT += CT - *(arr + picked_proc * 3 + 0)/*arrival time*/ - *(arr + picked_proc * 3 + 1)/*burst time*/;
        *(arr + picked_proc * 3 + 2) = 1;
        printf("%d-th ran process index: %d. CT: %d\n", proc, picked_proc, CT);
    }

    // Output
    printf("CT: %d\nTAT: %d\nWT: %d\nAverage TAT: %f\nAverage WT:%f\n", CT, TAT, WT, (float)TAT/n, (float)WT/n);
}