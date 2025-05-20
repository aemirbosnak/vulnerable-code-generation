//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>

#define PROC_DIR "/proc"
#define MAX_PROCESSES 1024
#define MAX_NAME_LEN 256

typedef struct {
    pid_t pid;
    char name[MAX_NAME_LEN];
    char state;
} ProcessInfo;

void fetch_processes(ProcessInfo processes[], int *count) {
    struct dirent *entry;
    DIR *dp = opendir(PROC_DIR);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            char proc_path[MAX_NAME_LEN];
            snprintf(proc_path, sizeof(proc_path), "%s/%s/stat", PROC_DIR, entry->d_name);

            FILE *stat_file = fopen(proc_path, "r");
            if (stat_file) {
                ProcessInfo p_info;
                fscanf(stat_file, "%d %s %c", &p_info.pid, p_info.name, &p_info.state);
                processes[(*count)++] = p_info;
                fclose(stat_file);
            }
        }
    }
    closedir(dp);
}

void display_processes(ProcessInfo processes[], int count) {
    printf("%-8s %-25s %s\n", "PID", "COMMAND", "STATE");
    printf("%-8s %-25s %s\n", "---", "-------", "-----");
    
    for (int i = 0; i < count; i++) {
        printf("%-8d %-25s %c\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

void sort_processes(ProcessInfo processes[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (processes[j].pid > processes[j + 1].pid) {
                ProcessInfo temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int count = 0;

    fetch_processes(processes, &count);
    
    printf("Fetched %d processes\n", count);
    
    sort_processes(processes, count);
    display_processes(processes, count);
    
    return 0;
}