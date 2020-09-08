//Same code for both ex3 and ex4
//It contains some warnings, but not an error, so it can be run.
//I don't know how to fix these warnings, but code still works, so...
#include <stdio.h>

int main(){
    while(1){
        char command[1000];
        scanf("%999[^\n]", &command);
        getchar();
        system(command);
    }
    return 0;
}