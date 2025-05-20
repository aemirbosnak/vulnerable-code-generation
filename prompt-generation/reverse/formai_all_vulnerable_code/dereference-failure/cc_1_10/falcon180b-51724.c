//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 80

struct process {
    int pid;
    char name[MAX_PROCESS_NAME];
    int cpu_usage;
    int memory_usage;
};

void get_process_info(int pid, char *name, int *cpu_usage, int *memory_usage) {
    FILE *fp;
    char path[20];
    sprintf(path, "/proc/%d/stat", pid);

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", path);
        exit(1);
    }

    fscanf(fp, "%*s %*s %*s %*s %*s %d %*s %*s %*s %*s %*s", cpu_usage, memory_usage);
    fclose(fp);

    fp = fopen("/proc/self/cwd", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file /proc/self/cwd\n");
        exit(1);
    }

    fgets(name, MAX_PROCESS_NAME, fp);
    fclose(fp);
}

void print_processes(struct process processes[], int num_processes) {
    printf("PID\tName\tCPU Usage\tMemory Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t\t%d\n", processes[i].pid, processes[i].name, processes[i].cpu_usage, processes[i].memory_usage);
    }
}

int main() {
    int num_processes = 0;
    struct process processes[MAX_PROCESSES];
    DIR *dp;
    struct dirent *dirp;

    dp = opendir("/proc");
    if (dp == NULL) {
        printf("Error: Unable to open directory /proc\n");
        exit(1);
    }

    while ((dirp = readdir(dp))!= NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) {
            continue;
        }

        int pid = atoi(dirp->d_name);
        char name[MAX_PROCESS_NAME];
        int cpu_usage, memory_usage;

        get_process_info(pid, name, &cpu_usage, &memory_usage);

        if (num_processes >= MAX_PROCESSES) {
            break;
        }

        processes[num_processes].pid = pid;
        strcpy(processes[num_processes].name, name);
        processes[num_processes].cpu_usage = cpu_usage;
        processes[num_processes].memory_usage = memory_usage;
        num_processes++;
    }

    closedir(dp);

    print_processes(processes, num_processes);

    return 0;
}