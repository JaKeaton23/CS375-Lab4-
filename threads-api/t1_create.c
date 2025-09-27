#include <stdio.h>
#include <pthread.h>

void* go(void* a){
    puts("hello from thread");
    return NULL;
}

int main(void){
    pthread_t t;
    pthread_create(&t, NULL, go, NULL);
    pthread_join(t, NULL);
    return 0;
}
