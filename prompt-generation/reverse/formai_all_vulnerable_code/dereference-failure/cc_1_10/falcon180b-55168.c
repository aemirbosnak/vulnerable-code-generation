//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[20];
    int pid;
    int memory_usage;
} process_t;

int main() {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];
    FILE *fp;
    char line[100];
    char *token;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");
        if (strcmp(token, "VmSize:") == 0) {
            processes[num_processes].memory_usage = atoi(strtok(NULL, " ")) * 1024; // Convert to bytes
            strcpy(processes[num_processes].name, "self");
            processes[num_processes].pid = getpid();
            num_processes++;
        }
    }

    fclose(fp);

    while (1) {
        system("clear");
        printf("RAM Usage Monitor\n");

        printf("PID\tName\tMemory Usage (KB)\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].memory_usage);
        }

        fflush(stdout);
        sleep(1);
    }

    return 0;
}