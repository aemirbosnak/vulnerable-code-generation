//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define STATUS_PATH "/proc/%d/status"
#define CMDLINE_PATH "/proc/%d/cmdline"

typedef struct {
    pid_t pid;
    char name[256];
    char state[16];
} Process;

void get_process_info(Process *process) {
    char status_file[256];
    char cmdline_file[256];
    FILE *file;
    char line[256];

    // Populate the status file path
    snprintf(status_file, sizeof(status_file), STATUS_PATH, process->pid);
    file = fopen(status_file, "r");
    
    if (file) {
        while (fgets(line, sizeof(line), file)) {
            if (sscanf(line, "Name:\t%s", process->name) == 1) {
                continue;
            }
            if (sscanf(line, "State:\t%s", process->state) == 1) {
                continue;
            }
        }
        fclose(file);
    }

    // Populate the cmdline file path
    snprintf(cmdline_file, sizeof(cmdline_file), CMDLINE_PATH, process->pid);
    file = fopen(cmdline_file, "r");
    
    if (file) {
        if (fgets(line, sizeof(line), file)) {
            strncpy(process->name, line, sizeof(process->name) - 1);
        }
        fclose(file);
    }
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;
    Process processes[MAX_PROCESSES];
    int count = 0;

    printf("%-10s %-25s %-10s\n", "PID", "Process Name", "State");
    printf("-----------------------------------------------------\n");

    dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            Process process;
            process.pid = atoi(entry->d_name);
            get_process_info(&process);
            processes[count++] = process;
        }
    }
    closedir(dir);
    
    // Sort processes (for demonstration, using a simple bubble sort)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (processes[j].pid > processes[j + 1].pid) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10s\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

void print_manual() {
    printf("Process Viewer\n");
    printf("Usage: ./process_viewer [options]\n");
    printf("Options:\n");
    printf("  --help      Show this help message\n");
    printf("  --list      List all running processes\n\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0) {
            print_manual();
            return 0;
        } else if (strcmp(argv[1], "--list") == 0) {
            list_processes();
            return 0;
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[1]);
            return 1;
        }
    }

    // Default behavior
    list_processes();
    return 0;
}