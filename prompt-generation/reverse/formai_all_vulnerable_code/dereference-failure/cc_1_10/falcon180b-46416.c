//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[16];
    int ram_usage;
} Process;

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];
    FILE *fp;
    char line[1024];
    char *token;
    int i;

    // Open the process list file
    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open process list file.\n");
        return 1;
    }

    // Read the process list file
    while (fgets(line, sizeof(line), fp)!= NULL) {
        // Parse the process name
        token = strtok(line, " ");
        strcpy(processes[num_processes].name, token);

        // Parse the process ID
        token = strtok(NULL, " ");
        processes[num_processes].pid = atoi(token);

        // Parse the RAM usage
        token = strtok(NULL, " ");
        processes[num_processes].ram_usage = atoi(token);

        num_processes++;
    }

    // Close the process list file
    fclose(fp);

    // Print the process list
    printf("Processes:\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d %s %d\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
    }

    return 0;
}