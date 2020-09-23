#include <stdio.h>
#include <stdlib.h>

//P.s. I have assumed that processes are already sorted by arrival time, as in life.

int main(){
    // Input
    printf("Write down number of processes:\n");
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * 2 * sizeof(int)); // Create 2d array. i-th j-th element is *(arr + i*2 + j)
    for(int i = 0; i < n; i++){ // Input processes' data
        printf("%d-th process:\n", i);
        int at, bt;
        scanf("%d %d", &at, &bt);
        *(arr + i * 2 + 0) = at;
        *(arr + i * 2 + 1) = bt;
    }

    // Create simulation by running processes one-by-one
    int CT = 0, TAT = 0, WT = 0;
    for(int proc = 0; proc < n; proc++){
        if(*(arr + proc * 2 + 0) > CT){
            CT = *(arr + proc * 2 + 0); // Adding time between i-th proc arrive time and curr. time, if it has not arrived yet.
            // It should be CT += *(arr + proc * 2 + 0) - CT, which is equal to CT = *(arr + proc * 2 + 0);
        }
        CT += *(arr + proc * 2 + 1);
        TAT += CT - *(arr + proc * 2 + 0);
        WT += CT - *(arr + proc * 2 + 0)/*arrival time*/ - *(arr + proc * 2 + 1)/*burst time*/;
    }

    // Output
    printf("CT: %d\nTAT: %d\nWT: %d\nAverage TAT: %f\nAverage WT:%f\n", CT, TAT, WT, (float)TAT/n, (float)WT/n);
}