#include <stdio.h>
#include <stdlib.h>

int main(){

    int N;
    scanf("%d", &N); // Reading array size from console
    int *ptr = malloc(N * sizeof(int)); // Allocate memory for our array
    for(int i = 0; i < N; i++){ // Filling array
        *(ptr + i) = i;
    }
    for(int i = 0; i < N; i++){ // Printing array
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    free(ptr);
}