//FormAI DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATH 1024

struct ProcInfo {
    char name[256];
    int pid;
    char state[256];
    long int vmem;
};

int is_numeric(const char *str){
    while (*str){
        if (!isdigit(*str++)) return 0;
    }
    return 1;
}

void print_header() {
    printf("%-20s %-10s %10s %10s\n", "NAME", "PID", "STATE", "VMEM(KB)");
}

void print_process_info(struct ProcInfo process) {
    printf("%-20s %-10d %10s %10ld\n", process.name, process.pid, process.state, process.vmem);
}

void parse_proc_line(char* line, struct ProcInfo *process) {
    char name[256];
    sscanf(line, "%d %s %s %ld", &process->pid, name, process->state, &process->vmem);
    strncpy(process->name, name, sizeof(process->name));
}

void get_proc_info(int pid, struct ProcInfo *process) {
    char path[MAX_PATH];
    sprintf(path, "/proc/%d/stat", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return;
    }
    char buf[MAX_PATH];
    fgets(buf, MAX_PATH, fp);
    fclose(fp);
    parse_proc_line(buf, process);
}

int main() {
    printf("SYSTEM PROCESS VIEWER\n");
    struct dirent *entry;
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        perror("Couldn't open /proc directory");
        return 1;
    }
    print_header();
    while ((entry = readdir(dir)) != NULL) {
        if (is_numeric(entry->d_name)) {
            int pid = atoi(entry->d_name);
            struct ProcInfo process;
            get_proc_info(pid, &process);
            if (strlen(process.name) > 0) {
                print_process_info(process);
            }
        }
    }
    closedir(dir);
    return 0;
}