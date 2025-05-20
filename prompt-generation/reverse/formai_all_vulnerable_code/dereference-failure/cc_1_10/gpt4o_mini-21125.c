//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char user[BUFFER_SIZE];
    char state[BUFFER_SIZE];
    long mem;
    char command[BUFFER_SIZE];
} ProcessInfo;

void get_process_info(ProcessInfo *process) {
    char path[BUFFER_SIZE], buffer[BUFFER_SIZE], *token;
    FILE *status_file;

    snprintf(path, sizeof(path), "/proc/%d/status", process->pid);
    status_file = fopen(path, "r");
    if (status_file == NULL) {
        perror("fopen");
        return;
    }

    while (fgets(buffer, sizeof(buffer), status_file)) {
        if (strncmp(buffer, "State:", 6) == 0) {
            strcpy(process->state, strtok(buffer + 7, " \n"));
        } else if (strncmp(buffer, "Uid:", 4) == 0) {
            int uid = atoi(strtok(buffer + 5, " \n"));
            struct passwd *pw = getpwuid(uid);
            if (pw) {
                strcpy(process->user, pw->pw_name);
            }
        }
    }
    fclose(status_file);

    snprintf(path, sizeof(path), "/proc/%d/statm", process->pid);
    status_file = fopen(path, "r");
    if (status_file) {
        fscanf(status_file, "%*s %ld", &process->mem);
        fclose(status_file);
    }

    snprintf(path, sizeof(path), "/proc/%d/comm", process->pid);
    status_file = fopen(path, "r");
    if (status_file) {
        fgets(process->command, sizeof(process->command), status_file);
        fclose(status_file);
    }
}

void list_processes(ProcessInfo *processes, int *count) {
    DIR *proc_dir;
    struct dirent *entry;

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("opendir");
        return;
    }

    *count = 0;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            processes[*count].pid = atoi(entry->d_name);
            get_process_info(&processes[*count]);
            if (strlen(processes[*count].command) > 0) {
                (*count)++;
            }
        }
    }
    closedir(proc_dir);
}

void display_processes(ProcessInfo *processes, int count) {
    printf("%-10s %-20s %-10s %-10s %s\n", "PID", "USER", "STATE", "MEMORY", "COMMAND");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10s %-10ld %s", 
                processes[i].pid, 
                processes[i].user, 
                processes[i].state, 
                processes[i].mem * getpagesize() / 1024, // Convert to KB
                processes[i].command);
    }
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int process_count;

    list_processes(processes, &process_count);
    display_processes(processes, process_count);

    return 0;
}