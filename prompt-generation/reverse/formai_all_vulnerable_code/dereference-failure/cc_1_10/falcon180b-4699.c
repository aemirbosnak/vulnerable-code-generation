//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_PROCESSES 1024

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

int num_processes = 0;
process_t *processes = NULL;

void add_process(int pid, char *command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    process_t *new_process = malloc(sizeof(process_t));
    new_process->pid = pid;
    strncpy(new_process->command, command, MAX_COMMAND_LENGTH);
    processes = realloc(processes, sizeof(process_t) * ++num_processes);
    processes[num_processes - 1] = *new_process;
}

void remove_process(int pid) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            free(processes[i].command);
            memmove(&processes[i], &processes[i+1], sizeof(process_t) * --num_processes);
            break;
        }
    }
}

void print_processes() {
    printf("PID\tCOMMAND\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *command = strtok(input, " ");
        if (command == NULL) {
            continue;
        }

        switch (command[0]) {
            case 'a': // add process
                add_process(atoi(strtok(NULL, " ")), strtok(NULL, " "));
                break;
            case 'r': // remove process
                remove_process(atoi(strtok(NULL, " ")));
                break;
            case 'p': // print processes
                print_processes();
                break;
            case 'q': // quit
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}