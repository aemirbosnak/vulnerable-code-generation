//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

void add_process(int pid, char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);
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
            printf("%d: %s\n", processes[i].pid, processes[i].command);
        }
    }
}

int main(int argc, char* argv[]) {
    int i;

    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    strncpy(processes[num_processes - 1].command, argv[1], MAX_COMMAND_LENGTH);

    for (i = 0; i < num_processes; i++) {
        if (processes[i].status == 0) {
            int pid = fork();

            if (pid == -1) {
                printf("Error: Fork failed.\n");
                return 1;
            } else if (pid == 0) {
                execlp(processes[i].command, processes[i].command, NULL);
                printf("Error: Execlp failed.\n");
                return 1;
            }

            add_process(pid, processes[i].command);
        }
    }

    while (1) {
        sleep(1);
        print_processes();
    }

    return 0;
}