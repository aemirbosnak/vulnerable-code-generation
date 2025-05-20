//Falcon-180B DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>

#define MAX_PROCESSES 1000

int num_processes = 0;
int process_id[MAX_PROCESSES];
int status;
char **argv;

void sigchld_handler(int signum) {
    while (waitpid(-1, &status, WNOHANG) > 0) {
        int i;
        for (i = 0; i < num_processes; i++) {
            if (process_id[i] == status) {
                process_id[i] = 0;
                break;
            }
        }
    }
}

int launch_process(char *command) {
    pid_t pid;
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }
    switch (pid = fork()) {
        case -1:
            perror("fork");
            return 1;
        case 0:
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
            close(fd[1]);
            execlp("sh", "sh", "-c", command, (char *)0);
            perror("execlp");
            _exit(1);
        default:
            close(fd[1]);
            process_id[num_processes] = pid;
            num_processes++;
            break;
    }
    return 0;
}

int main(int argc, char **argv) {
    int i;
    signal(SIGCHLD, sigchld_handler);
    printf("Enter commands to launch processes:\n");
    while (1) {
        fgets(argv[0], sizeof(argv[0]), stdin);
        if (strlen(argv[0]) == 0) {
            break;
        }
        argv[0][strcspn(argv[0], "\n")] = '\0';
        if (launch_process(argv[0]) == -1) {
            exit(1);
        }
    }
    for (i = 0; i < num_processes; i++) {
        if (process_id[i]!= 0) {
            kill(process_id[i], SIGKILL);
        }
    }
    return 0;
}