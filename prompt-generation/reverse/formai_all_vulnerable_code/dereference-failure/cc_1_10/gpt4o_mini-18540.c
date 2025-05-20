//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char user[32];
    char command[BUFFER_SIZE];
} Process;

void get_processes(Process *processes, int *count) {
    DIR *dir;
    struct dirent *entry;
    char path[BUFFER_SIZE];
    FILE *status_file;
    char buffer[BUFFER_SIZE];
    
    *count = 0;
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                snprintf(path, sizeof(path), "/proc/%d/status", pid);
                status_file = fopen(path, "r");
                if (status_file) {
                    fgets(buffer, sizeof(buffer), status_file); // Read first line (Name: <command>)
                    sscanf(buffer, "Name:\t%s", processes[*count].command);
                    fgets(buffer, sizeof(buffer), status_file); // Read second line (Uid: <user_id>)
                    sscanf(buffer, "Uid:\t%d", &processes[*count].pid);
                    fclose(status_file);
                    
                    snprintf(path, sizeof(path), "/proc/%d", pid);
                    if (getuid() == processes[*count].pid) {
                        snprintf(processes[*count].user, sizeof(processes[*count].user), "current_user");
                    } else {
                        snprintf(processes[*count].user, sizeof(processes[*count].user), "other_user");
                    }
                    (*count)++;
                }
            }
        }
    }
    closedir(dir);
}

void print_processes(Process *processes, int count) {
    printf("%-10s %-20s %-s\n", "PID", "USER", "COMMAND");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-s\n", processes[i].pid, processes[i].user, processes[i].command);
    }
}

void filter_processes(Process *processes, int count, const char *filter) {
    printf("\nFiltered Processes matching '%s':\n", filter);
    printf("%-10s %-20s %-s\n", "PID", "USER", "COMMAND");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        if (strstr(processes[i].command, filter) != NULL) {
            printf("%-10d %-20s %-s\n", processes[i].pid, processes[i].user, processes[i].command);
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int count;
    
    get_processes(processes, &count);
    
    print_processes(processes, count);
    
    char filter[BUFFER_SIZE];
    printf("\nEnter filter keyword for processes (leave empty to skip): ");
    fgets(filter, sizeof(filter), stdin);
    filter[strcspn(filter, "\n")] = '\0';  // Remove newline character

    if (strlen(filter) > 0) {
        filter_processes(processes, count, filter);
    }

    return 0;
}