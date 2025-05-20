//FormAI DATASET v1.0 Category: System process viewer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PID_LENGTH 6
#define MAX_CMDLINE_LENGTH 1024

typedef struct process_info {
    char pid[MAX_PID_LENGTH];
    char cmdline[MAX_CMDLINE_LENGTH];
} ProcessInfo;

int read_proc_dir(ProcessInfo **processes) {
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error: Could not open /proc directory");
        return -1;
    }
    struct dirent *entry;
    int num_processes = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int is_pid = 1;
            for (int i = 0; i < strlen(entry->d_name); i++) {
                if (entry->d_name[i] < '0' || entry->d_name[i] > '9') {
                    is_pid = 0;
                    break;
                }
            }
            if (is_pid) {
                char status_path[strlen("/proc/")+strlen(entry->d_name)+strlen("/status")+1];
                sprintf(status_path, "/proc/%s/status", entry->d_name);
                FILE *status_file = fopen(status_path, "r");
                if (status_file == NULL) {
                    printf("Warning: Could not open %s\n", status_path);
                    continue;
                }
                char pid[MAX_PID_LENGTH];
                char cmdline[MAX_CMDLINE_LENGTH];
                int pid_found = 0, cmdline_found = 0;
                while (fgets(cmdline, MAX_CMDLINE_LENGTH, status_file) != NULL) {
                    if (strncmp(cmdline, "Pid:", 4) == 0) {
                        sscanf(cmdline, "%*s %s", pid);
                        pid_found = 1;
                    }
                    if (strncmp(cmdline, "Name:", 5) == 0) {
                        sscanf(cmdline, "%*s %s", cmdline);
                        cmdline_found = 1;
                    }
                    if (pid_found && cmdline_found) {
                        ProcessInfo *new_process = malloc(sizeof(ProcessInfo));
                        if (new_process == NULL) {
                            perror("Error: Could not allocate memory for process");
                            return -1;
                        }
                        strcpy(new_process->pid, pid);
                        strcpy(new_process->cmdline, cmdline);
                        processes[num_processes] = new_process;
                        num_processes++;
                        break;
                    }
                }
                fclose(status_file);
            }
        }
    }
    closedir(dir);
    return num_processes;
}

void print_processes(ProcessInfo **processes, int num_processes) {
    printf("%-6s %-20s\n", "PID", "CMDLINE");
    printf("----------------------------------------\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%-6s %-20s\n", processes[i]->pid, processes[i]->cmdline);
        free(processes[i]);
    }
}

int main() {
    ProcessInfo *processes[512] = {0};
    int num_processes = read_proc_dir(processes);
    if (num_processes == -1) {
        return 1;
    }
    print_processes(processes, num_processes);
    return 0;
}