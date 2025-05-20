//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME 16

typedef struct {
    char name[MAX_PROCESS_NAME];
    int pid;
    int status;
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

void add_process(char* name, int pid) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME);
    processes[num_processes].pid = pid;
    processes[num_processes].status = 0;

    num_processes++;
}

void remove_process(int pid) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = 1;
            break;
        }
    }
}

void print_processes() {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].status == 0) {
            printf("%s (%d)\n", processes[i].name, processes[i].pid);
        }
    }
}

int main() {
    char command[1024];
    char* args[16];
    int num_args;
    int status;
    int pid;

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        num_args = 0;
        args[num_args] = strtok(command, " ");
        while (args[num_args]!= NULL) {
            num_args++;
            args[num_args] = strtok(NULL, " ");
        }

        if (strcmp(args[0], "add") == 0) {
            if (num_args < 3) {
                printf("Usage: add <process name> <pid>\n");
            } else {
                add_process(args[1], atoi(args[2]));
            }
        } else if (strcmp(args[0], "remove") == 0) {
            if (num_args < 3) {
                printf("Usage: remove <pid>\n");
            } else {
                remove_process(atoi(args[1]));
            }
        } else if (strcmp(args[0], "list") == 0) {
            print_processes();
        } else {
            pid = fork();

            if (pid == 0) {
                execvp(args[0], args);
            } else {
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}