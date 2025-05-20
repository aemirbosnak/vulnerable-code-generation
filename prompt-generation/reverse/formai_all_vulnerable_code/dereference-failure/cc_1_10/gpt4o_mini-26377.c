//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PROCESS_LIST 1024
#define BUFFER_SIZE 256

typedef struct Process {
    int pid;
    char name[BUFFER_SIZE];
    long unsigned int memory;
} Process;

void get_processes(Process *processes, int *count) {
    DIR *dir;
    struct dirent *entry;
    char path[BUFFER_SIZE];
    FILE *fp;
    char comm[BUFFER_SIZE];
    int pid;

    *count = 0;
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a directory and digits only (which means it's a PID)
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
            pid = atoi(entry->d_name);
            snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
            fp = fopen(path, "r");
            if (fp) {
                fscanf(fp, "%d %s", &pid, comm);
                fclose(fp);

                snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);
                fp = fopen(path, "r");
                if (fp) {
                    char line[BUFFER_SIZE];
                    while (fgets(line, sizeof(line), fp)) {
                        if (strncmp(line, "VmSize:", 7) == 0) {
                            long unsigned int memory;
                            sscanf(line + 7, "%lu", &memory);
                            processes[*count].pid = pid;
                            strcpy(processes[*count].name, comm);
                            processes[*count].memory = memory;
                            (*count)++;
                        }
                    }
                    fclose(fp);
                }
            }
        }
    }
    closedir(dir);
}

void display_processes(Process *processes, int count) {
    printf("%-10s %-25s %-10s\n", "PID", "Process Name", "Memory (KB)");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10lu\n", processes[i].pid, processes[i].name, processes[i].memory);
    }
}

int main() {
    Process processes[MAX_PROCESS_LIST];
    int process_count;

    printf("Fetching process information...\n");
    get_processes(processes, &process_count);
    
    if (process_count > 0) {
        display_processes(processes, process_count);
    } else {
        printf("No processes found.\n");
    }

    return 0;
}