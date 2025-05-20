//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 1024

typedef struct {
    char *name;
    int pid;
    int ppid;
} Process;

void print_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%s\tPID: %d\tPPID: %d\n", processes[i].name, processes[i].pid, processes[i].ppid);
    }
}

int read_processes(char *proc_file, Process *processes, int max_processes) {
    FILE *fp;
    char line[BUFF_SIZE];
    int num_processes = 0;

    fp = fopen(proc_file, "r");
    if (fp == NULL) {
        printf("Error opening %s\n", proc_file);
        return -1;
    }

    while (fgets(line, BUFF_SIZE, fp)!= NULL) {
        if (num_processes >= max_processes) {
            printf("Reached maximum number of processes\n");
            break;
        }

        char *token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }

        Process process;
        process.name = malloc(strlen(token) + 1);
        strcpy(process.name, token);

        token = strtok(NULL, " ");
        process.pid = atoi(token);

        token = strtok(NULL, " ");
        process.ppid = atoi(token);

        processes[num_processes++] = process;
    }

    fclose(fp);
    return num_processes;
}

int main() {
    char proc_file[BUFF_SIZE];
    sprintf(proc_file, "/proc/%d/task", getpid());

    int max_processes = 100;
    Process processes[max_processes];
    int num_processes = read_processes(proc_file, processes, max_processes);

    if (num_processes > 0) {
        print_processes(processes, num_processes);
    } else {
        printf("No processes found\n");
    }

    return 0;
}