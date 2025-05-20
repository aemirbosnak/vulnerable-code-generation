//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/sysinfo.h>

#define MAX_PROCESSES 1024

struct process {
    int pid;
    char name[32];
    int cpu_usage;
};

void get_process_info(struct process *processes, int num_processes) {
    FILE *fp;
    char line[1024];
    char *token;
    int i;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/stat\n");
        exit(1);
    }

    fgets(line, sizeof(line), fp); // Skip first line (header)

    for (i = 0; i < num_processes; i++) {
        sprintf(line, "/proc/%d/stat", processes[i].pid);
        fp = fopen(line, "r");
        if (fp == NULL) {
            printf("Error: Could not open /proc/%d/stat\n", processes[i].pid);
            exit(1);
        }

        while (fgets(line, sizeof(line), fp)!= NULL) {
            token = strtok(line, " ");
            if (token == NULL)
                break;

            if (strcmp(token, "utime") == 0) {
                token = strtok(NULL, " ");
                processes[i].cpu_usage = atoi(token);
                break;
            }
        }

        fclose(fp);
    }

    fclose(fp);
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes;

    num_processes = get_nprocs();

    printf("Number of processes: %d\n", num_processes);

    if (num_processes > MAX_PROCESSES) {
        printf("Error: Too many processes\n");
        exit(1);
    }

    get_process_info(processes, num_processes);

    printf("PID\tName\tCPU Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
    }

    return 0;
}