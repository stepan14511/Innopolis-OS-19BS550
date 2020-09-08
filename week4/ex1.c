#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 

int main(){
    if(fork() == 0){
        printf("Hello from child %d\n", getpid()); 
    }
    else{
        printf("Hello from parent %d\n", getpid());
    }
    return 0;
}