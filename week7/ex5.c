#include <stdio.h>
#include <stdlib.h> // Added to use malloc

int main() {
    char **s = malloc(sizeof(char *)); // There was no memory allocation for s. Now the code is fixed.
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %s\n",s);
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    return(0);
} 