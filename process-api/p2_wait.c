#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    pid_t rc = fork();
    if (rc < 0) { perror("fork"); return 1; }

    if (rc == 0) {
        printf("child (pid=%d)\n", getpid());
    } else {
        int status=0;
        pid_t wc = waitpid(rc, &status, 0);
        printf("parent (pid=%d) waited for child %d, status=%d\n",
               getpid(), (int)wc, status);
    }
    return 0;
}
