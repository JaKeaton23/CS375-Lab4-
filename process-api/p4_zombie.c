#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
    pid_t rc = fork();
    if (rc < 0) { perror("fork"); return 1; }

    if (rc == 0) {
        // Child exits immediately -> becomes zombie until parent reaps or exits
        printf("child exiting (pid=%d)\n", getpid());
        _exit(0);
    } else {
        // Parent sleeps so you can observe the zombie with ps
        printf("parent sleeping (pid=%d); child is a zombie for a few seconds\n", getpid());
        sleep(8);  // gives you time to run 'ps' in another terminal
        // Note: we purposefully do NOT call wait() here to show zombie state briefly
        return 0;
    }
}
