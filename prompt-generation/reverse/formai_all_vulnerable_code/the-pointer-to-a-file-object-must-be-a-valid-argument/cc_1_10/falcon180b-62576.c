//Falcon-180B DATASET v1.0 Category: System administration ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LINE_SIZE 1024

volatile sig_atomic_t interrupted = 0;

void sighandler(int signo) {
    interrupted = 1;
}

int main(int argc, char **argv) {
    int fd[2];
    pid_t childpid;
    int status;
    char buffer[MAX_LINE_SIZE];

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    childpid = fork();

    if (childpid == -1) {
        perror("fork");
        exit(1);
    } else if (childpid == 0) {
        // Child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(1);
    } else {
        // Parent process
        close(fd[1]);
        FILE *fp = fdopen(fd[0], "r");

        while (fgets(buffer, MAX_LINE_SIZE, fp)!= NULL) {
            printf("%s", buffer);
        }

        if (ferror(fp)) {
            perror("fgets");
        } else {
            status = 0;
        }

        if (waitpid(childpid, &status, 0) == -1) {
            perror("waitpid");
        }
    }

    return 0;
}