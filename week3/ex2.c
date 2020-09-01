#include <stdio.h>

//Just swap func
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int* array, int size){
    char sorted = 0; // 0 - not sorted, 1 - sorted
    while(sorted != 1){ // Do while not sorted
        sorted = 1;
        for(int i = 0; i < size - 1; i++){
            if(array[i] > array[i + 1]){
                swap(&(array[i]), &(array[i + 1])); // Swap if wrong order
                sorted = 0; // Make it to go through the array at least one more time
            }
        }
    }
}

int main(){
    const int size = 5;
    int a[size] = {3, 2, 5, 6, 1}; // Create an array of size 5
    bubble_sort(a, size); // Sort it
    for(int i = 0; i < size; i++){ // Output the sorted version of the array
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}