//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME 256

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME];
    int status;
} PROCESS;

int main() {
    int num_processes = 0;
    PROCESS processes[MAX_PROCESSES];

    FILE *fp;
    char line[1024];
    char *token;
    char proc_file[20] = "/proc/";

    sprintf(proc_file, "/proc/%d", getpid());
    fp = fopen(proc_file, "r");

    if (fp == NULL) {
        printf("Error opening /proc/%d\n", getpid());
        exit(1);
    }

    // Read the first line to get the process name
    fgets(line, 1024, fp);
    token = strtok(line, " ");
    strcpy(processes[num_processes].name, token);

    while (fgets(line, 1024, fp)!= NULL) {
        token = strtok(line, " ");
        int pid = atoi(token);

        if (num_processes >= MAX_PROCESSES) {
            printf("Maximum number of processes reached\n");
            break;
        }

        processes[num_processes].pid = pid;
        strcpy(processes[num_processes].name, token);
        num_processes++;
    }

    fclose(fp);

    printf("Processes running on the system:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d %s\n", processes[i].pid, processes[i].name);
    }

    return 0;
}