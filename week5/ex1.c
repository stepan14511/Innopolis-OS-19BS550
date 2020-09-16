#include <stdio.h>
#include <pthread.h>

void *new_print(void *arg){
    printf("INSIDE thread\n");
    return 0;
}

int main(){
    pthread_t variable;
	for (int i = 1; i <= 5; ++i) {
		printf("START %d\n", i);
		pthread_create(&variable, NULL, new_print, NULL);
		printf("END %d\n", i);
        pthread_join(variable, NULL); // Fixes the order
	}
}