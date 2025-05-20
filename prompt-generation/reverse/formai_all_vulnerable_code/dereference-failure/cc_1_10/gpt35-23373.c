//FormAI DATASET v1.0 Category: System process viewer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

typedef struct {
    char name[20];
    int pid;
    char status[20];
} Process;

void display_processes(Process* proc_array, int count);

int main() {
    DIR* dir_ptr;
    FILE* file_ptr;
    struct dirent* entry_ptr;
    char path[50], name[20], status[20];
    int pid, count = 0;
    Process processes[50];

    // Open /proc directory
    dir_ptr = opendir("/proc");
    if (dir_ptr == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    // Read all entries in /proc directory
    while ((entry_ptr = readdir(dir_ptr)) != NULL) {
        // Check if entry is a directory containing only digits (i.e. Process ID)
        if (entry_ptr->d_type == DT_DIR && atoi(entry_ptr->d_name) != 0) {
            pid = atoi(entry_ptr->d_name);
            sprintf(path, "/proc/%d/status", pid);

            // Open status file for process
            file_ptr = fopen(path, "r");
            if (file_ptr == NULL) {
                printf("Error opening status file for process %d\n", pid);
                continue;
            }

            // Read process name and status from status file
            while (fscanf(file_ptr, "%s", name) != EOF) {
                if (strcmp(name, "Name:") == 0) {
                    fscanf(file_ptr, "%s", name);
                    strcpy(processes[count].name, name);
                    processes[count].pid = pid;
                } else if (strcmp(name, "State:") == 0) {
                    fscanf(file_ptr, "%s", status);
                    strcpy(processes[count].status, status);
                }
            }
            count++;
            fclose(file_ptr);
        }
    }
    closedir(dir_ptr);

    display_processes(processes, count);

    return 0;
}

void display_processes(Process* proc_array, int count) {
    printf("---------------------------------------------------------------\n");
    printf(" %-20s | %-10s | %-20s\n", "Name", "PID", "Status");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf(" %-20s | %-10d | %-20s\n", proc_array[i].name, proc_array[i].pid, proc_array[i].status);
    }
    printf("---------------------------------------------------------------\n");
}