//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct process {
    int pid;
    char name[20];
    int status;
} Process;

void print_processes(Process *processes, int count) {
    printf("Process ID\tProcess Name\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    char command[BUFFER_SIZE];
    char *tokens[3];
    int status;
    int count = 0;
    Process processes[100];

    while (1) {
        printf("Enter command: ");
        fgets(command, BUFFER_SIZE, stdin);

        tokens[0] = strtok(command, " ");
        if (strcmp(tokens[0], "list") == 0) {
            printf("Listing processes:\n");
            print_processes(processes, count);
        } else if (strcmp(tokens[0], "kill") == 0) {
            tokens[1] = strtok(NULL, " ");
            int pid = atoi(tokens[1]);
            kill(pid, SIGKILL);
            printf("Process %d killed.\n", pid);
        } else if (strcmp(tokens[0], "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}