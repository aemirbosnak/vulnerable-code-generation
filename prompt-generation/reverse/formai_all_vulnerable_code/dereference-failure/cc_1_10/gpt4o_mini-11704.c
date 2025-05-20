//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define BUF_SIZE 256

typedef struct {
    int pid;
    char name[BUF_SIZE];
} Process;

void list_process_ids(int *pids, int *count);
void get_process_name(int pid, char *name);
void display_processes(int *pids, int count);
void sort_processes(Process *processes, int count);
void view_process_details(int pid);

int main() {
    int pids[MAX_PROCESSES];
    int count = 0;

    list_process_ids(pids, &count);
    display_processes((int *)pids, count);

    return 0;
}

void list_process_ids(int *pids, int *count) {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                pids[*count] = pid;
                (*count)++;
            }
        }
    }

    closedir(dir);
}

void get_process_name(int pid, char *name) {
    char path[BUF_SIZE];
    snprintf(path, sizeof(path), "/proc/%d/comm", pid);
    FILE *file = fopen(path, "r");
    
    if (file) {
        fgets(name, BUF_SIZE, file);
        // remove newline
        name[strcspn(name, "\n")] = 0;
        fclose(file);
    } else {
        strncpy(name, "Unknown", BUF_SIZE);
    }
}

void display_processes(int *pids, int count) {
    Process processes[MAX_PROCESSES];
    char name[BUF_SIZE];

    for (int i = 0; i < count; i++) {
        processes[i].pid = pids[i];
        get_process_name(pids[i], name);
        strncpy(processes[i].name, name, BUF_SIZE);
    }

    sort_processes(processes, count);

    printf("\n%-10s%-50s\n", "PID", "Process Name");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d%-50s\n", processes[i].pid, processes[i].name);
    }
}

void sort_processes(Process *processes, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (processes[j].pid > processes[j + 1].pid) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void view_process_details(int pid) {
    char path[BUF_SIZE];
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    FILE *file = fopen(path, "r");
    
    if (file) {
        char line[BUF_SIZE];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Cannot view details for PID %d\n", pid);
    }
}