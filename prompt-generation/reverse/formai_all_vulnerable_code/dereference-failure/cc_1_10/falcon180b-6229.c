//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    pid_t pid;
    char name[MAX_COMMAND_LENGTH];
    int status;
} Process;

void print_processes(Process *processes, int count) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <process_name>\n", argv[0]);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, argv[1]);

    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking\n");
        return 1;
    } else if (pid == 0) {
        execlp(command, command, NULL);
        printf("Error executing %s\n", command);
        return 1;
    }

    int status;
    waitpid(pid, &status, 0);

    Process processes[10];
    int count = 0;

    FILE *fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error opening /proc/self/status\n");
        return 1;
    }

    char line[MAX_COMMAND_LENGTH];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strcpy(processes[count].name, line + 6);
        } else if (strncmp(line, "State:", 6) == 0) {
            processes[count].status = atoi(line + 7);
            count++;
        }
    }

    fclose(fp);

    printf("Processes running %s:\n", argv[1]);
    print_processes(processes, count);

    return 0;
}