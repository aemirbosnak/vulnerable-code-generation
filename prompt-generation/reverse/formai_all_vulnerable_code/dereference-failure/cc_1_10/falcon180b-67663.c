//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[30];
    int pid;
    int ram_usage;
} Process;

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];

    // Read in list of processes
    FILE *fp = fopen("processes.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int pos = 0;
        char *delim = " ";
        char *token = strtok_r(line, delim, &pos);
        strcpy(processes[num_processes].name, token);
        processes[num_processes].pid = atoi(strtok_r(NULL, delim, &pos));
        processes[num_processes].ram_usage = atoi(strtok_r(NULL, delim, &pos));
        num_processes++;
        if (num_processes >= MAX_PROCESSES) {
            break;
        }
    }
    fclose(fp);

    // Sort processes by RAM usage
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[j].ram_usage > processes[i].ram_usage) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Print top 10 processes by RAM usage
    printf("Top 10 processes by RAM usage:\n");
    for (int i = 0; i < 10 && i < num_processes; i++) {
        printf("%s (%d) - %d MB\n", processes[i].name, processes[i].pid, processes[i].ram_usage / 1024);
    }

    return 0;
}