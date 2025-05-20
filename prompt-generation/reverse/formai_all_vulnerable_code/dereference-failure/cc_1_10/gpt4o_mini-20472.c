//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PROCESS_PATH 256
#define BUFFER_SIZE 1024

typedef struct {
    char pid[6];
    char comm[256];
    char state[10];
} ProcessInfo;

void trim_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

void get_process_info(const char *pid, ProcessInfo *info) {
    char path[MAX_PROCESS_PATH];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    FILE *file = fopen(path, "r");
    if (!file) return;

    fscanf(file, "%s %s %s", info->pid, info->comm, info->state);
    fclose(file);

    // Clean the comm field by removing parentheses
    if (info->comm[0] == '(') {
        char *end = strrchr(info->comm, ')');
        if (end) {
            *end = '\0';
            memmove(info->comm, info->comm + 1, strlen(info->comm)); // Shift left to remove '('
        }
    }
}

int get_process_count() {
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;
    int count = 0;

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            count++;
        }
    }
    closedir(proc_dir);
    return count;
}

void print_processes(ProcessInfo *processes, int count) {
    printf("%-10s %-25s %-10s\n", "PID", "COMMAND", "STATE");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-25s %-10s\n", processes[i].pid, processes[i].comm, processes[i].state);
    }
}

void list_processes() {
    int count = get_process_count();
    ProcessInfo *processes = malloc(count * sizeof(ProcessInfo));

    if (!processes) {
        perror("Failed to allocate memory");
        return;
    }

    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;
    int index = 0;

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            get_process_info(entry->d_name, &processes[index]);
            index++;
        }
    }
    closedir(proc_dir);

    print_processes(processes, count);
    free(processes);
}

int main() {
    while (1) {
        printf("\n=== Linux Process Viewer ===\n");
        list_processes();
        printf("\nPress Ctrl+C to refresh the process list or close terminal to exit...\n");
        sleep(5);
    }
    return 0;
}