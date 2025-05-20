//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    int pid;
    char *cmd;
    char *envp[] = { "PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin", NULL };
    int status;
    int i;
    struct rusage usage;

    // Get the command line input
    cmd = (char *) malloc(1024);
    printf("Enter the command to execute: ");
    scanf("%s", cmd);

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        execlp(cmd, cmd, NULL);
        perror("execlp");
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);

        // Get the CPU usage of the child process
        if (getrusage(RUSAGE_CHILDREN, &usage)!= -1) {
            printf("CPU usage: %d%%\n", usage.ru_utime.tv_sec * 100 / usage.ru_utime.tv_usec);
        } else {
            perror("getrusage");
        }

        free(cmd);
    }

    return 0;
}