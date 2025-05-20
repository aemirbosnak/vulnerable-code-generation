//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define PROC_PATH "/proc/"
#define CMDLINE_PATH "cmdline"
#define STAT_PATH "stat"

typedef struct {
    int pid;
    char cmdline[256];
    float cpu_usage;
} Process;

void get_process_info(const char *pid_str, Process *process) {
    char path[256];
    snprintf(path, sizeof(path), "%s%s/%s", PROC_PATH, pid_str, CMDLINE_PATH);

    FILE *cmdline_file = fopen(path, "r");
    if (cmdline_file) {
        fread(process->cmdline, sizeof(char), sizeof(process->cmdline) - 1, cmdline_file);
        process->cmdline[sizeof(process->cmdline) - 1] = '\0'; // Ensure null-termination
        fclose(cmdline_file);
    } else {
        strcpy(process->cmdline, "N/A");
    }

    process->pid = atoi(pid_str);
    
    snprintf(path, sizeof(path), "%s%s/%s", PROC_PATH, pid_str, STAT_PATH);
    FILE *stat_file = fopen(path, "r");
    if (stat_file) {
        int utime, stime, cutime, cstime, starttime, total_time;
        fscanf(stat_file, "%*d %*s %*s %*s %*s %*s %*s %*s %d %d %d %d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %d", 
               &utime, &stime, &cutime, &cstime, &starttime);
        total_time = utime + stime + cutime + cstime;

        process->cpu_usage = (float)total_time / sysconf(_SC_CLK_TCK);
        fclose(stat_file);
    } else {
        process->cpu_usage = 0.0;
    }
}

int is_digit_str(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);
    Process processes[MAX_PROCESSES];
    int process_count = 0;

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        if (is_digit_str(entry->d_name)) {
            get_process_info(entry->d_name, &processes[process_count]);
            process_count++;
            if (process_count >= MAX_PROCESSES) break;
        }
    }

    closedir(dp);

    printf("%-6s %-25s %-12s\n", "PID", "Command", "CPU Usage(s)");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < process_count; i++) {
        printf("%-6d %-25s %-12.2f\n", processes[i].pid, processes[i].cmdline, processes[i].cpu_usage);
    }
}

int main() {
    while (1) {
        printf("\033[H\033[J"); // Clear screen
        list_processes();
        sleep(2); // Refresh every 2 seconds
    }
    return 0;
}