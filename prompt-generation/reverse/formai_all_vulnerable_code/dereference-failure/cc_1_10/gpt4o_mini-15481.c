//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME 256

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME];
} Process;

void listProcesses(Process *processes, int *count) {
    DIR *dir;
    struct dirent *entry;
    char path[256];
    FILE *fp;

    dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Check if the directory name is a number (PID)
            if (isdigit(entry->d_name[0])) {
                processes[*count].pid = atoi(entry->d_name);
                snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
                fp = fopen(path, "r");
                if (fp) {
                    fscanf(fp, "%*d %s", processes[*count].name);
                    processes[*count].name[0] = '\0';  // reset the name
                    fscanf(fp, "%s", processes[*count].name); // Read name
                    fclose(fp);
                    (*count)++;
                }
            }
        }
        if (*count >= MAX_PROCESSES) {
            break;
        }
    }
    closedir(dir);
}

void printProcesses(Process *processes, int count) {
    printf("%-10s %-30s\n", "PID", "Name");
    printf("%-10s %-30s\n", "---", "------------------------------");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s\n", processes[i].pid, processes[i].name);
    }
}

void viewProcessDetails(int pid) {
    char path[256];
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    FILE *fp = fopen(path, "r");
    if (!fp) {
        printf("Error opening process details for PID: %d\n", pid);
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

int main() {
    Process processes[MAX_PROCESSES];
    int count = 0;
    char filter[MAX_PROCESS_NAME];
    char choice[10];

    printf("Enter process name to filter (leave empty for all): ");
    fgets(filter, sizeof(filter), stdin);
    filter[strcspn(filter, "\n")] = 0; // Remove the newline character

    listProcesses(processes, &count);
    
    printf("Listing processes:\n");
    printProcesses(processes, count);

    while (1) {
        printf("\nEnter PID to see details (0 to exit): ");
        fgets(choice, sizeof(choice), stdin);
        int pid = atoi(choice);

        if (pid == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < count; i++) {
            if (processes[i].pid == pid) {
                found = 1;
                viewProcessDetails(pid);
                break;
            }
        }

        if (!found) {
            printf("No process found with PID: %d\n", pid);
        }
    }

    return 0;
}