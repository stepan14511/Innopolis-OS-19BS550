#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    void *ptr[10];
    for(int i = 0; i < 10; i++){
        ptr[i] = malloc(10 * 1024 * 1024);
        memset(ptr[i], 0, 10*1024*1024);
        sleep(1);
    }
    return 0;
}

/* EX2:
    Si and So fields are remaining 0s for the whole time, because I have 8Gb of RAM and this is more than enough for all running processes.
    If there is enough RAM, OS does not need to use swap.
*/

/* EX3:
    Top output is in ex3.txt
    There we can see, that we allocate right amount of memory.
    Also we can see some other useful information about ex2 and other processes, like run time, user, etc.
*/