#include <stdio.h>
#include <pthread.h>

int ready = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

void* producer(void* a){
    pthread_mutex_lock(&m);
    puts("producer: work done");
    ready = 1;
    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&m);
    return NULL;
}

void* consumer(void* a){
    pthread_mutex_lock(&m);
    while (!ready) {
        pthread_cond_wait(&cv, &m);
    }
    puts("consumer: observed ready=1");
    pthread_mutex_unlock(&m);
    return NULL;
}

int main(void){
    pthread_t p, c;
    pthread_create(&c, NULL, consumer, NULL);
    pthread_create(&p, NULL, producer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    return 0;
}
