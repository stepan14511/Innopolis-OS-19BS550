#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *realloc(void *ptr, size_t size){
    if(size == 0){
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(size);
    if(ptr == NULL){
        return new_ptr;
    }

    memcpy(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}

int main(){}