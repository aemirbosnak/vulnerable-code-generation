//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 1000
#define MAX_COMMAND_LENGTH 1024

typedef struct process_info {
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;
    int status;
} process_info_t;

int num_processes = 0;
process_info_t processes[MAX_PROCESSES];

void add_process(char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    process_info_t* process = &processes[num_processes];
    strcpy(process->command, command);
    process->pid = fork();

    if (process->pid == -1) {
        printf("Error: Failed to fork process.\n");
        return;
    } else if (process->pid == 0) {
        execlp(command, command, NULL);
        exit(1);
    } else {
        waitpid(process->pid, &process->status, 0);
        num_processes++;
    }
}

void remove_process(int pid) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].pid = 0;
            processes[i].status = 0;
            num_processes--;
            break;
        }
    }
}

void print_processes() {
    printf("PID\tCommand\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char* command = strtok(input, "\n");
        add_process(command);
    }

    return 0;
}