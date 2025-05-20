//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

struct process_info {
    int pid;
    char name[BUFFER_SIZE];
    int cpu_usage;
    int memory_usage;
};

void get_process_info(struct process_info *info, int pid) {
    char path[20];
    sprintf(path, "/proc/%d", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        strcpy(info->name, "Unknown");
        info->pid = 0;
        info->cpu_usage = 0;
        info->memory_usage = 0;
        return;
    }
    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        if (strstr(line, "name:")!= NULL) {
            char *token = strtok(line, ":");
            strcpy(info->name, token);
        } else if (strstr(line, "state:")!= NULL) {
            char *token = strtok(line, ":");
            int state = atoi(token);
            if (state == 0) {
                strcpy(info->name, "Zombie");
            } else if (state == 1) {
                strcpy(info->name, "Sleeping");
            } else if (state == 2) {
                strcpy(info->name, "Running");
            } else if (state == 3) {
                strcpy(info->name, "Stopped");
            } else if (state == 4) {
                strcpy(info->name, "Traced");
            }
        } else if (strstr(line, "cpu_usage:")!= NULL) {
            char *token = strtok(line, ":");
            info->cpu_usage = atoi(token);
        } else if (strstr(line, "memory_usage:")!= NULL) {
            char *token = strtok(line, ":");
            info->memory_usage = atoi(token);
        }
    }
    fclose(fp);
}

void print_process_info(struct process_info *info) {
    printf("PID: %d\n", info->pid);
    printf("Name: %s\n", info->name);
    printf("CPU Usage: %d%%\n", info->cpu_usage);
    printf("Memory Usage: %d KB\n", info->memory_usage);
    printf("\n");
}

void print_header() {
    printf("PID\tName\tCPU Usage\tMemory Usage\n");
}

int main() {
    DIR *dp;
    struct dirent *dir;
    dp = opendir("/proc");
    if (dp == NULL) {
        printf("Error opening /proc directory\n");
        return 1;
    }
    print_header();
    while ((dir = readdir(dp))!= NULL) {
        int pid = atoi(dir->d_name);
        struct process_info info;
        get_process_info(&info, pid);
        print_process_info(&info);
    }
    closedir(dp);
    return 0;
}