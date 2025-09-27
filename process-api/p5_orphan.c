#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
    pid_t rc = fork();
    if (rc < 0) { perror("fork"); return 1; }

    if (rc == 0) {
        // Sleep so parent can exit first, then our PPID should change
        sleep(2);
        printf("child (pid=%d) now has new parent ppid=%d\n", getpid(), getppid());
        return 0;
    } else {
        printf("parent exiting quickly (pid=%d); child will become orphan\n", getpid());
        _exit(0);
    }
}
