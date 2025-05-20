//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int process_id;
    int status;
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;
int next_process_id = 1;

void print_processes() {
    printf("Process ID | Command\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d | %s\n", processes[i].process_id, processes[i].command);
    }
}

int find_process_by_id(int process_id) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].process_id == process_id) {
            return i;
        }
    }
    return -1;
}

void remove_process(int index) {
    for (int i = index; i < num_processes - 1; i++) {
        processes[i] = processes[i + 1];
    }
    num_processes--;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter a command to run or type 'list' to view running processes:\n");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        if (strcmp(input, "list") == 0) {
            print_processes();
        } else {
            int background = 0;
            if (strcmp(input + strlen(input) - 1, " &") == 0) {
                background = 1;
                input[strlen(input) - 1] = '\0';
            }
            if (num_processes >= MAX_PROCESSES) {
                printf("Error: Maximum number of processes reached.\n");
            } else {
                int pid = fork();
                if (pid == -1) {
                    printf("Error: Failed to fork process.\n");
                } else if (pid == 0) {
                    if (background) {
                        setsid();
                    }
                    execlp(input, input, NULL);
                    exit(1);
                } else {
                    processes[num_processes].process_id = next_process_id;
                    processes[num_processes].status = 0;
                    strcpy(processes[num_processes].command, input);
                    num_processes++;
                    next_process_id++;
                    if (!background) {
                        waitpid(pid, NULL, 0);
                    }
                }
            }
        }
    }
    return 0;
}