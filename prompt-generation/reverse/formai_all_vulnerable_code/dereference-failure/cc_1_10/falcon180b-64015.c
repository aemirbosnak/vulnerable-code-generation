//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100

struct process {
    char name[20];
    int pid;
    int status;
};

int get_processes(struct process *processes) {
    FILE *fp;
    char line[100];
    char *token;
    int count = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        token = strtok(line, " ");
        strcpy(processes[count].name, token);
        processes[count].pid = atoi(token);
        count++;
    }

    fclose(fp);
    return count;
}

void print_processes(struct process *processes, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%d - %s\n", processes[i].pid, processes[i].name);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int count;

    count = get_processes(processes);
    print_processes(processes, count);

    return 0;
}