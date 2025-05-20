//FormAI DATASET v1.0 Category: System process viewer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

// Function to get virtual memory size of process given its PID
long long get_virt_mem_size(int pid) {
    char path[100];
    sprintf(path, "/proc/%d/statm", pid);
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
    long long size;
    fscanf(fp, "%lld", &size);
    fclose(fp);
    return size;
}

// Function to get resident memory size of process given its PID
long long get_rss_mem_size(int pid) {
    char path[100];
    sprintf(path, "/proc/%d/stat", pid);
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }
    char line[1000];
    fgets(line, 1000, fp);
    fclose(fp);
    char* token = strtok(line, " ");
    for (int i=0; i<22; i++) {
        token = strtok(NULL, " ");
    }
    long long rss_size = strtoll(token, NULL, 10);
    long page_size = sysconf(_SC_PAGE_SIZE);
    rss_size *= page_size;
    return rss_size;
}

// Function to get command line arguments of process given its PID
void get_cmd_args(int pid, char* cmd_args) {
    char path[100];
    sprintf(path, "/proc/%d/cmdline", pid);
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    fscanf(fp, "%[^\n]", cmd_args);
    fclose(fp);
}

int main() {
    DIR* proc_dir = opendir("/proc");
    struct dirent* entry;
    printf("PID     VIRT     RSS     CMD_ARGS\n");
    while ((entry = readdir(proc_dir)) != NULL) {
        if (entry->d_name[0] < '0' || entry->d_name[0] > '9') {
            continue;
        }
        int pid = atoi(entry->d_name);
        long long virt_size = get_virt_mem_size(pid);
        long long rss_size = get_rss_mem_size(pid);
        if (virt_size == -1 || rss_size == -1) {
            continue;
        }
        char cmd_args[1000];
        get_cmd_args(pid, cmd_args);
        printf("%d      %lld     %lld     %s\n", pid, virt_size, rss_size, cmd_args);
    }
    return 0;
}