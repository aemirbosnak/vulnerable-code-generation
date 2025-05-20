//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1000

typedef struct {
    char name[16];
    int pid;
    int ram_usage;
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void update_ram_usage() {
    FILE *file;
    char line[100];
    char *token;
    int i;

    file = fopen("/proc/self/status", "r");
    if (file == NULL) {
        printf("Error: Failed to open /proc/self/status\n");
        return;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, ": ");
        if (strcmp(token, "VmSize") == 0) {
            token = strtok(NULL, ": ");
            processes[num_processes].ram_usage = atoi(token) / 1024;
        }
    }

    fclose(file);
}

void print_processes() {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%-16s %-6d %-10d KB\n", processes[i].name, processes[i].pid, processes[i].ram_usage);
    }
}

int main() {
    FILE *file;
    char line[100];
    char *token;

    file = fopen("/proc/self/cmdline", "r");
    if (file == NULL) {
        printf("Error: Failed to open /proc/self/cmdline\n");
        return 1;
    }

    fgets(line, sizeof(line), file);
    token = strtok(line, " ");
    strcpy(processes[num_processes].name, token);
    processes[num_processes].pid = getpid();
    num_processes++;

    fclose(file);

    while (1) {
        update_ram_usage();
        print_processes();
        sleep(5);
    }

    return 0;
}