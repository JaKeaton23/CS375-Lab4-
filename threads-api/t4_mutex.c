#include <stdio.h>
#include <pthread.h>

long counter = 0;
int loops = 200000;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* add(void* a){
    for (int i = 0; i < loops; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
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
