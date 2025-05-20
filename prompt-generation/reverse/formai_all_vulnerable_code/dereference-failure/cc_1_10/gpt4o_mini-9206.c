//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PROC 1024
#define PROC_PATH "/proc/"
#define STATUS_FILE "/status"
#define CMDLINE_FILE "/cmdline"

typedef struct {
    int pid;
    char name[256];
    char state[16];
} ProcessInfo;

void fetch_process_info(ProcessInfo *proc_info, int pid) {
    char path[256];
    snprintf(path, sizeof(path), "%s%d%s", PROC_PATH, pid, STATUS_FILE);
    
    FILE *file = fopen(path, "r");
    if (file) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file)) {
            if (strncmp(buffer, "Name:", 5) == 0) {
                sscanf(buffer, "Name:\t%s", proc_info->name);
            } else if (strncmp(buffer, "State:", 6) == 0) {
                sscanf(buffer, "State:\t%s", proc_info->state);
            }
        }
        fclose(file);
    }

    proc_info->pid = pid;
}

void print_process_info(ProcessInfo *proc_info) {
    printf("PID: %d, Name: %s, State: %s\n", proc_info->pid, proc_info->name, proc_info->state);
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    ProcessInfo proc_info[MAX_PROC];
    int count = 0;

    while ((entry = readdir(dp))) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            if (count < MAX_PROC) {
                fetch_process_info(&proc_info[count], pid);
                count++;
            }
        }
    }
    closedir(dp);
    
    // Sort processes by PID
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (proc_info[i].pid > proc_info[j].pid) {
                ProcessInfo temp = proc_info[i];
                proc_info[i] = proc_info[j];
                proc_info[j] = temp;
            }
        }
    }

    // Print processes
    printf("\nProcess List:\n");
    for (int i = 0; i < count; i++) {
        print_process_info(&proc_info[i]);
    }
}

void filter_processes_by_name(const char *name) {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    ProcessInfo proc_info;
    
    printf("\nFiltered Process List (containing: %s):\n", name);
    while ((entry = readdir(dp))) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            fetch_process_info(&proc_info, pid);
            if (strstr(proc_info.name, name)) {
                print_process_info(&proc_info);
            }
        }
    }
    closedir(dp);
}

void wait_for_exit() {
    printf("\nPress Enter to exit...");
    getchar();
}

int main() {
    printf("Welcome to the Irregular Process Viewer!\n");
    list_processes();
    
    char filter[256];
    printf("\nEnter a process name to filter the list (or press Enter to skip): ");
    fgets(filter, sizeof(filter), stdin);
    filter[strcspn(filter, "\n")] = 0; // Remove newline character

    if (strlen(filter) > 0) {
        filter_processes_by_name(filter);
    }

    wait_for_exit();
    return 0;
}