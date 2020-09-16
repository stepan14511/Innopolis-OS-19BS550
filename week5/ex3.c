#include <stdio.h>
#include <pthread.h>

#define BUFFER_MAX 10000

int buffer = 0;
int producer_state = 1;
int consumer_state = 0;

void* producer(void *arg){
    int i = 0;
    while(1){
        buffer++;
        i++;
        if(i % 50 == 0){
            printf("Producer still produces.");
            i = i % 50;
        }

        if(buffer == BUFFER_MAX){
            producer_state = 0;
        }
        if(buffer == 1){
            consumer_state = 1;
        }

        while(producer_state == 0);
    }
}

void* consumer(void *arg){
    int i = 0; // In order to not print thousands of messages per second. Only some of them.
    while(1){
        if(buffer == 0){
            consumer_state = 0;
        }
        while(consumer_state == 0);

        buffer--;
        i++;
        if(i % 50 == 0){
            printf("Consumer still consumes.");
            i = i % 50;
        }
        if(buffer + 1 == BUFFER_MAX){
            producer_state = 1;
        }
    }
}

// We do not use any sycronization, so it end up in the fact, that consumer wakes up producer, which sleep itself before checking the wake up message.
// So, both threads just go to sleep for a infinite time.

int main(){
    pthread_t thread_cons, thread_prod;
    pthread_create(&thread_cons, NULL, consumer, NULL);
    pthread_create(&thread_prod, NULL, producer, NULL);
    pthread_join(thread_prod, NULL);
    return 0;
}