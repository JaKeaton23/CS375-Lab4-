#include <stdio.h>
#include <pthread.h>

void* work(void* a){
    puts("child work done");
    return NULL;
}

int main(void){
    pthread_t t;
    pthread_create(&t, NULL, work, NULL);
    pthread_join(t, NULL);
    puts("main after join");
    return 0;
}
