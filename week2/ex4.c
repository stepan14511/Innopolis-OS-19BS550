#include <stdio.h>

void swap_ints(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int *a = malloc(sizeof(int)), *b = malloc(sizeof(int));
    scanf("%d", a);
    scanf("%d", b);
    swap_ints(a, b);
    printf("a: %d, b: %d\n", *a, *b);
    free(a);
    free(b);
    return 0;
}