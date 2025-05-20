//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#define MAX_PROCESSES 50
#define MAX_COMMAND_LENGTH 100

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        printf("Child process terminated.\n");
    }
}

int main(int argc, char *argv[]) {
    int i, j;
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;
    int max_processes_reached = 0;

    signal(SIGCHLD, sigchld_handler);

    for (i = 1; i < argc; i++) {
        if (num_processes >= MAX_PROCESSES - 1) {
            printf("Maximum number of processes reached.\n");
            max_processes_reached = 1;
            break;
        }

        processes[num_processes].pid = fork();

        if (processes[num_processes].pid == -1) {
            printf("Fork failed.\n");
            exit(1);
        } else if (processes[num_processes].pid == 0) {
            strncpy(processes[num_processes].command, argv[i], MAX_COMMAND_LENGTH);
            processes[num_processes].command[MAX_COMMAND_LENGTH - 1] = '\0';

            execlp(processes[num_processes].command, processes[num_processes].command, NULL);

            perror("execlp");
            exit(1);
        } else {
            num_processes++;
        }
    }

    if (max_processes_reached) {
        return 0;
    }

    for (i = 0; i < num_processes; i++) {
        waitpid(processes[i].pid, &processes[i].status, 0);
    }

    for (i = 0; i < num_processes; i++) {
        if (WIFEXITED(processes[i].status)) {
            printf("Process %d exited with status %d.\n", processes[i].pid, WEXITSTATUS(processes[i].status));
        } else if (WIFSIGNALED(processes[i].status)) {
            printf("Process %d terminated by signal %d.\n", processes[i].pid, WTERMSIG(processes[i].status));
        } else {
            printf("Process %d terminated abnormally.\n", processes[i].pid);
        }
    }

    return 0;
}