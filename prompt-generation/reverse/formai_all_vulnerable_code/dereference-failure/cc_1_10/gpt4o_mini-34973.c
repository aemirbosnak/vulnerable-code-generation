//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    char state[BUFFER_SIZE];
} Process;

void read_process_info(Process *process, const char *proc_dir) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "%s/stat", proc_dir);

    FILE *file = fopen(path, "r");
    if (file) {
        fscanf(file, "%d %s %s", &process->pid, process->name, process->state);
        fclose(file);
    }
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;
    Process processes[MAX_PROCESSES];
    int count = 0;

    if ((dir = opendir("/proc")) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {  // Check if the directory name is a number (PID)
            char proc_dir[BUFFER_SIZE];
            snprintf(proc_dir, sizeof(proc_dir), "/proc/%s", entry->d_name);
            read_process_info(&processes[count], proc_dir);
            count++;
            if (count >= MAX_PROCESSES) break;
        }
    }
    closedir(dir);

    printf("%-10s %-25s %-10s\n", "PID", "NAME", "STATE");
    printf("%-10s %-25s %-10s\n", "---", "-------------------------", "----------");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10s\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

void filter_by_state(const char *state_filter) {
    // Convert to lowercase to allow case insensitive matching
    char filter[BUFFER_SIZE];
    for (int i = 0; state_filter[i]; i++) {
        filter[i] = tolower(state_filter[i]);
    }
    filter[strlen(state_filter)] = '\0';  // Null-terminate

    DIR *dir;
    struct dirent *entry;
    Process processes[MAX_PROCESSES];
    int count = 0;

    if ((dir = opendir("/proc")) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            char proc_dir[BUFFER_SIZE];
            snprintf(proc_dir, sizeof(proc_dir), "/proc/%s/stat", entry->d_name);
            FILE *file = fopen(proc_dir, "r");
            if (file) {
                fscanf(file, "%d %s %s", &processes[count].pid, processes[count].name, processes[count].state);
                fclose(file);
                // Compare process state to filter
                if (strstr(processes[count].state, filter) != NULL) {
                    count++;
                }
            }
            if (count >= MAX_PROCESSES) break;
        }
    }
    closedir(dir);

    printf("%-10s %-25s %-10s\n", "PID", "NAME", "STATE");
    printf("%-10s %-25s %-10s\n", "---", "-------------------------", "----------");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10s\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Listing all processes:\n");
        list_processes();
    } else if (argc == 2) {
        printf("Filtering processes by state: %s\n", argv[1]);
        filter_by_state(argv[1]);
    } else {
        printf("Usage: %s [state]\n", argv[0]);
        printf("Example: %s S\n", argv[0]);
        printf("This will filter processes by state (S for sleeping, R for running, etc.)\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}