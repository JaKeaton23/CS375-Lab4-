#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    pid_t rc = fork();
    if (rc < 0) { perror("fork"); return 1; }

    if (rc == 0) {
        // child replaces its program with /bin/ls
        char *argv[] = {"ls", "-l", NULL};
        execv("/bin/ls", argv);
        perror("execv"); // only runs if exec fails
    } else {
        // parent waits for child to finish
        wait(NULL);
        printf("parent (pid=%d) after child finished\n", getpid());
    }
    return 0;
}
