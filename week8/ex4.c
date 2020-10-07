#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main(){
    void *ptr[10];
    for(int i = 0; i < 10; i++){
        ptr[i] = malloc(10 * 1024 * 1024);
        memset(ptr[i], 0, 10*1024*1024);

        // Use of getrusage
        int rusge = RUSAGE_SELF;
        struct rusage r;
        int resources = getrusage(rusge, &r);
        printf("%ld\n", r.ru_maxrss);
        sleep(1);
    }
    return 0;
}
/*
The program outputed the amount of memory, we used. By this we can check, if we allocate right amout of memory.
*/