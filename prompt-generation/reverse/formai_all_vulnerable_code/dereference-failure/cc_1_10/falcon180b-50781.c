//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LEN 1024

typedef struct {
    char command[MAX_COMMAND_LEN];
    int pid;
    int status;
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(char *command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Too many processes\n");
        return;
    }

    process_t *process = &processes[num_processes];
    strcpy(process->command, command);
    process->pid = fork();

    if (process->pid == 0) {
        execlp("/bin/sh", "sh", "-c", command, NULL);
        exit(1);
    }

    num_processes++;
}

void wait_for_processes() {
    while (num_processes > 0) {
        int status;
        waitpid(processes[0].pid, &status, WNOHANG);

        if (WIFEXITED(status)) {
            printf("Process %d exited with status %d\n", processes[0].pid, WEXITSTATUS(status));
            num_processes--;
            memmove(processes, processes + 1, sizeof(process_t) * (MAX_PROCESSES - 1));
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    add_process(argv[1]);

    wait_for_processes();

    return 0;
}