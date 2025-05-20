//Falcon-180B DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_BACKGROUND_PROCESSES 10

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

process_t processes[MAX_BACKGROUND_PROCESSES];
int num_processes = 0;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].pid == -1) {
                processes[i].pid = 0;
                break;
            }
        }
        num_processes--;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    signal(SIGCHLD, sigchld_handler);

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    pid_t pid = fork();

    if (pid == -1) {
        printf("Error forking process\n");
        return 1;
    } else if (pid == 0) {
        if (num_processes >= MAX_BACKGROUND_PROCESSES) {
            printf("Maximum number of background processes reached\n");
            return 1;
        }

        processes[num_processes].pid = getpid();
        strcpy(processes[num_processes].command, command);
        num_processes++;

        execlp("/bin/sh", "sh", "-c", command, NULL);

        printf("Error executing command\n");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].pid == pid) {
                processes[i].pid = -1;
                break;
            }
        }

        num_processes--;

        if (WIFEXITED(status)) {
            printf("Command exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Command terminated by signal %d\n", WTERMSIG(status));
        } else {
            printf("Command terminated abnormally\n");
        }
    }

    return 0;
}