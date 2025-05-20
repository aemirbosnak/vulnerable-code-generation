//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_PROCESSES 100

typedef struct {
    char name[16];
    int pid;
    int ram_usage;
} process_t;

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *token;
    int num_processes = 0;
    process_t *processes = malloc(MAX_NUM_PROCESSES * sizeof(process_t));

    if (processes == NULL) {
        printf("Error: Could not allocate memory for processes.\n");
        return 1;
    }

    fp = popen("ps axo pid,rss,comm", "r");
    if (fp == NULL) {
        printf("Error: Could not run ps command.\n");
        free(processes);
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }

        if (num_processes >= MAX_NUM_PROCESSES) {
            printf("Error: Reached maximum number of processes.\n");
            fclose(fp);
            free(processes);
            return 1;
        }

        processes[num_processes].pid = atoi(token);
        token = strtok(NULL, " ");
        strncpy(processes[num_processes].name, token, 15);
        processes[num_processes].ram_usage = atoi(strtok(NULL, " "));
        num_processes++;
    }

    fclose(fp);

    printf("Process Name\tPID\tRAM Usage (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%-15s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].ram_usage);
    }

    free(processes);
    return 0;
}