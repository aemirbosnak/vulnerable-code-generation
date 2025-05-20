//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_CMD_LENGTH 256
#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char cmd[MAX_CMD_LENGTH];
    float cpu_usage;
} ProcessInfo;

void get_process_info(ProcessInfo* processes, int* count) {
    struct dirent *entry;
    DIR *dp = opendir("/proc");
    *count = 0;

    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            char stat_file[MAX_CMD_LENGTH];
            snprintf(stat_file, sizeof(stat_file), "/proc/%d/stat", pid);
            FILE *stat_fp = fopen(stat_file, "r");

            if (stat_fp) {
                ProcessInfo process;
                process.pid = pid;

                fscanf(stat_fp, "%d %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %lf", &process.cpu_usage);
                fgets(process.cmd, sizeof(process.cmd), stat_fp);
                char *token = strtok(process.cmd, " ");
                if (token != NULL) {
                    strcpy(process.cmd, token);
                }
                
                processes[(*count)++] = process;
                fclose(stat_fp);
            }
        }
    }

    closedir(dp);
}

void display_processes(ProcessInfo* processes, int count) {
    printf("%-10s %-20s %-10s\n", "PID", "COMMAND", "CPU USAGE");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%-10d %-20s %.2f\n", processes[i].pid, processes[i].cmd, processes[i].cpu_usage);
    }
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int count;

    get_process_info(processes, &count);

    char filter[MAX_CMD_LENGTH];
    printf("Enter command name to filter processes (or press ENTER to show all): ");
    fgets(filter, sizeof(filter), stdin);
    
    // Remove newline character
    size_t len = strlen(filter);
    if (len > 0 && filter[len - 1] == '\n') {
        filter[len - 1] = '\0';
    }

    printf("\nFiltered Process List:\n");
    display_processes(processes, count);

    if (strlen(filter) > 0) {
        printf("\nProcesses matching '%s':\n", filter);
        for (int i = 0; i < count; i++) {
            if (strstr(processes[i].cmd, filter) != NULL) {
                printf("%-10d %-20s %.2f\n", processes[i].pid, processes[i].cmd, processes[i].cpu_usage);
            }
        }
    }

    return 0;
}