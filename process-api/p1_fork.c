#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
    printf("before fork (pid=%d)\n", getpid());
    pid_t rc = fork();
    if (rc < 0) { perror("fork"); return 1; }
    if (rc == 0) printf("child  (pid=%d)\n", getpid());
    else         printf("parent (pid=%d)\n", getpid());
    return 0;
}
