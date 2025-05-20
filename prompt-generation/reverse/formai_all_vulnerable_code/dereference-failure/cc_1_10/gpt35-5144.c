//FormAI DATASET v1.0 Category: System process viewer ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

#define MAX_PID 65535
#define MAX_CMD_LEN 100

typedef struct {
    char cmd[MAX_CMD_LEN];
    pid_t pid;
    uid_t uid;
    double cpu_usage;
} process_info;

process_info processes[MAX_PID];

int count_processes() {
    int count = 0;
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type != DT_DIR) {
            continue;
        }
        char *endptr;
        long pid = strtol(entry->d_name, &endptr, 10);
        if (*endptr != '\0') {
            continue;
        }                
        char stat_file[50];
        sprintf(stat_file, "/proc/%d/stat", pid);
        FILE *stat_fp = fopen(stat_file, "r");
        if (stat_fp == NULL) {
            continue;
        }
        fscanf(stat_fp, "%ld %*s %*c %ld %*d %*d "
            "%*d %*d %*d %*d %*d %*d %lf", &pid, &processes[count].uid, &processes[count].cpu_usage);
        fclose(stat_fp);
        char cmdline_file[50];
        sprintf(cmdline_file, "/proc/%d/cmdline", pid);
        FILE *cmdline_fp = fopen(cmdline_file, "r");
        if (cmdline_fp == NULL) {
            continue;
        }
        fgets(processes[count].cmd, MAX_CMD_LEN, cmdline_fp);
        fclose(cmdline_fp);
        processes[count].pid = pid;               
        count++;                
    }
    closedir(dir);
    return count;
}

int main() {
    int process_count = count_processes();
    printf("The Cyberpunk-style C System Process Viewer\n\n");
    printf("Total processes: %d\n\n", process_count);
    printf("PID\tUID\tCPU\tCOMMAND\n");
    for (int i = 0; i < process_count; i++) {
        printf("%d\t%d\t%.2f\t%s\n", processes[i].pid, processes[i].uid, processes[i].cpu_usage, processes[i].cmd);
    }   
    return 0;
}