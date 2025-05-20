//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024
#define USAGE "Usage: %s [PID]\n"

// Function to print the processes in a fancy way
void print_processes(int num_processes, char processes[][MAX_COMMAND_LENGTH]) {
    printf("+-------------------------------+\n");
    printf("| %-10s | %s\n", "PID", "COMMAND");
    printf("+-------------------------------+\n");
    for (int i = 0; i < num_processes; i++) {
        printf("| %-10d | %-30s |\n", processes[i][0], processes[i]);
    }
    printf("+-------------------------------+\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, USAGE, argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    char command[MAX_COMMAND_LENGTH] = {0};
    snprintf(command, MAX_COMMAND_LENGTH, "ps -p %d -o pid= -o comm=", pid);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to execute command.\n");
        return 1;
    }

    char processes[MAX_PROCESSES][MAX_COMMAND_LENGTH] = {0};
    int num_processes = 0;

    while (fscanf(fp, "%[^\n]", processes[num_processes])!= EOF) {
        num_processes++;
    }

    pclose(fp);

    print_processes(num_processes, processes);

    return 0;
}