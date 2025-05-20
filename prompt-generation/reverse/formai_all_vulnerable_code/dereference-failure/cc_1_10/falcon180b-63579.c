//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_PROCESSES 1024
#define MAX_LINE_SIZE 1024

typedef struct {
    pid_t pid;
    char name[MAX_LINE_SIZE];
} Process;

int main() {
    int i, num_processes, max_processes;
    Process *processes;
    char line[MAX_LINE_SIZE];
    FILE *file;
    char *token;

    // Read the maximum number of processes to display
    printf("Enter the maximum number of processes to display: ");
    if (fgets(line, MAX_LINE_SIZE, stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        exit(1);
    }
    max_processes = atoi(line);

    // Get the list of processes
    printf("Reading process list...\n");
    file = popen("ps -e", "r");
    if (file == NULL) {
        printf("Error: Failed to execute ps command.\n");
        exit(1);
    }
    num_processes = 0;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (num_processes >= max_processes) {
            break;
        }
        token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }
        processes[num_processes].pid = atoi(token);
        strcpy(processes[num_processes].name, token);
        num_processes++;
    }
    pclose(file);

    // Sort the processes by PID
    for (i = 0; i < num_processes - 1; i++) {
        if (processes[i].pid > processes[i + 1].pid) {
            Process temp = processes[i];
            processes[i] = processes[i + 1];
            processes[i + 1] = temp;
        }
    }

    // Print the process list
    printf("Process list:\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d: %s\n", processes[i].pid, processes[i].name);
    }

    // Free memory
    free(processes);

    return 0;
}