#include <stdio.h>
#include <pthread.h>

long counter = 0;
int loops = 200000;

void* add(void* a){
    for (int i = 0; i < loops; i++) {
        counter++;  // race condition
    }
    return NULL;
}

int main(void){
    pthread_t t1, t2;
    pthread_create(&t1, NULL, add, NULL);
    pthread_create(&t2, NULL, add, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("counter=%ld (expected %d)\n", counter, 2*loops);
    return 0;
}
