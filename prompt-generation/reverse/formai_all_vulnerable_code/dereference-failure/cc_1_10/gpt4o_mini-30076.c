//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PROCESSES 1024
#define PROC_PATH "/proc"

typedef struct {
    pid_t pid;
    char name[256];
    char state[16];
} ProcessInfo;

void get_process_info(ProcessInfo *processes, int *count) {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);
    
    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    
    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            char path[256];
            snprintf(path, sizeof(path), "%s/%s/stat", PROC_PATH, entry->d_name);
            FILE *file = fopen(path, "r");
            if (file) {
                ProcessInfo pinfo;
                fscanf(file, "%d %s %s", &pinfo.pid, pinfo.name, pinfo.state);
                strcpy(pinfo.name, strtok(pinfo.name, "()")); // Remove parentheses
                processes[(*count)++] = pinfo;
                fclose(file);
            }
        }
    }
    closedir(dp);
}

void print_process_info(ProcessInfo *processes, int count) {
    printf("%-10s %-25s %-10s\n", "PID", "NAME", "STATE");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10s\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

void sort_processes(ProcessInfo *processes, int count) {
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(processes[j].pid > processes[j + 1].pid) {
                ProcessInfo temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void filter_processes_by_state(ProcessInfo *processes, int count, const char *state) {
    printf("\nFiltered Processes (State: %s):\n", state);
    printf("%-10s %-25s %-10s\n", "PID", "NAME", "STATE");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(processes[i].state, state) == 0) {
            printf("%-10d %-25s %-10s\n", processes[i].pid, processes[i].name, processes[i].state);
        }
    }
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int count = 0;

    get_process_info(processes, &count);
    sort_processes(processes, count);
    print_process_info(processes, count);

    char state[16];
    printf("\nEnter a state to filter processes (e.g., R, S, D): ");
    scanf("%s", state);
    for (int i = 0; state[i]; i++) state[i] = toupper(state[i]); // Make uppercase
    
    filter_processes_by_state(processes, count, state);

    return 0;
}