#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    int fds[2];
    if (pipe(fds) < 0) { perror("pipe"); return 1; }

    pid_t rc = fork();
    if (rc < 0) { perror("fork"); return 1; }

    if (rc == 0) {
        // Child: read end
        close(fds[1]);
        char buf[128] = {0};
        ssize_t n = read(fds[0], buf, sizeof(buf)-1);
        if (n < 0) perror("read");
        printf("child read: \"%s\"\n", buf);
        return 0;
    } else {
        // Parent: write end
        close(fds[0]);
        const char *msg = "hello via pipe";
        if (write(fds[1], msg, strlen(msg)) < 0) perror("write");
        close(fds[1]);
        wait(NULL);
        return 0;
    }
}
