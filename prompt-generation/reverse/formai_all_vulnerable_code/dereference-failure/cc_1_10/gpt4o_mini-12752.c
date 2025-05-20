//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUF 256
#define MAX_PROC 1024

typedef struct {
    pid_t pid;
    char cmd[MAX_BUF];
    float cpu_usage;
    long memory_usage;
} ProcessInfo;

void strip_newline(char *str) {
    char *new_line = strchr(str, '\n');
    if (new_line) {
        *new_line = '\0';
    }
}

float get_cpu_usage(pid_t pid) {
    char stat_file[MAX_BUF], line[MAX_BUF];
    snprintf(stat_file, sizeof(stat_file), "/proc/%d/stat", pid);
    
    FILE *fp = fopen(stat_file, "r");
    if (!fp) return -1;

    for (int i = 0; i < 13; i++) {
        if (!fgets(line, sizeof(line), fp)) break;
    }
    
    // Get utime and stime from the stat file
    long utime, stime;
    sscanf(line, "%*d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %ld %ld", &utime, &stime);
    fclose(fp);
    return (utime + stime) / (float)sysconf(_SC_CLK_TCK); 
}

long get_memory_usage(pid_t pid) {
    char status_file[MAX_BUF];
    snprintf(status_file, sizeof(status_file), "/proc/%d/status", pid);
    
    FILE *fp = fopen(status_file, "r");
    if (!fp) return -1;

    char line[MAX_BUF];
    long mem_usage = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "VmSize:", 7) == 0) {
            sscanf(line + 7, "%ld", &mem_usage);
            break;
        }
    }
    fclose(fp);
    return mem_usage;
}

void list_processes() {
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;
    ProcessInfo processes[MAX_PROC];
    int count = 0;

    if (!proc_dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            pid_t pid = atoi(entry->d_name);
            processes[count].pid = pid;

            char cmdline_file[MAX_BUF];
            snprintf(cmdline_file, sizeof(cmdline_file), "/proc/%d/cmdline", pid);
            
            FILE *cmd_fp = fopen(cmdline_file, "r");
            if (cmd_fp) {
                fgets(processes[count].cmd, sizeof(processes[count].cmd), cmd_fp);
                fclose(cmd_fp);
                strip_newline(processes[count].cmd);
            } else {
                strcpy(processes[count].cmd, "(unknown)");
            }

            processes[count].cpu_usage = get_cpu_usage(pid);
            processes[count].memory_usage = get_memory_usage(pid);
            count++;

            if (count >= MAX_PROC) break;
        }
    }
    closedir(proc_dir);

    // Output the gathered processes
    printf("%-10s %-20s %-15s %-15s\n", "PID", "COMMAND", "CPU (%)", "MEMORY (kB)");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-15.2f %-15ld\n", processes[i].pid, processes[i].cmd, processes[i].cpu_usage, processes[i].memory_usage);
    }
}

int main() {
    while (1) {
        printf("\nProcess Viewer\n");
        printf("Press Ctrl+C to exit.\n");
        list_processes();
        sleep(2);  // Refresh every 2 seconds
    }
    return 0;
}