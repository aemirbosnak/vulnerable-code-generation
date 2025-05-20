//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_PROCESSES 50
#define MAX_COMMAND_LEN 100

typedef struct process {
    pid_t pid;
    char command[MAX_COMMAND_LEN];
    int status;
} Process;

Process processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(pid_t pid, char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].command, command, MAX_COMMAND_LEN);
    num_processes++;
}

void remove_process(pid_t pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            memmove(&processes[i], &processes[i + 1], sizeof(Process) * (num_processes - i - 1));
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
    char input[MAX_COMMAND_LEN];
    while (1) {
        printf("Enter command to execute or type 'exit' to quit: ");
        fgets(input, MAX_COMMAND_LEN, stdin);

        char* token = strtok(input, " ");
        if (strcmp(token, "exit") == 0) {
            break;
        }

        pid_t pid = fork();
        if (pid == -1) {
            printf("Error: Fork failed.\n");
            continue;
        } else if (pid == 0) {
            execlp(token, token, NULL);
            printf("Error: Execlp failed.\n");
            exit(1);
        } else {
            add_process(pid, input);
        }
    }

    return 0;
}