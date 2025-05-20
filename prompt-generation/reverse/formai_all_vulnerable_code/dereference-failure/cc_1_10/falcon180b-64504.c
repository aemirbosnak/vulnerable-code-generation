//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define MAX_COMMAND_LINE_LENGTH 4096

typedef struct process_info {
    int pid;
    char name[64];
    int status;
    int ppid;
    int cpu_usage;
    int mem_usage;
} process_info_t;

void print_process_info(process_info_t *proc_info, int num_processes) {
    printf("PID\tName\tStatus\tPPID\tCPU Usage\tMemory Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", proc_info[i].pid, proc_info[i].name, proc_info[i].status, proc_info[i].ppid, proc_info[i].cpu_usage, proc_info[i].mem_usage);
    }
}

int get_process_info(process_info_t *proc_info, int num_processes) {
    FILE *fp;
    char line[MAX_COMMAND_LINE_LENGTH];
    char *token;
    int count = 0;

    fp = popen("ps -ef", "r");
    if (fp == NULL) {
        perror("popen");
        return -1;
    }

    while (fgets(line, MAX_COMMAND_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");
        if (token == NULL)
            continue;
        if (count >= num_processes)
            break;
        proc_info[count].pid = atoi(token);
        token = strtok(NULL, " ");
        strcpy(proc_info[count].name, token);
        token = strtok(NULL, " ");
        proc_info[count].status = atoi(token);
        token = strtok(NULL, " ");
        proc_info[count].ppid = atoi(token);
        token = strtok(NULL, " ");
        proc_info[count].cpu_usage = atoi(token);
        token = strtok(NULL, " ");
        proc_info[count].mem_usage = atoi(token);
        count++;
    }

    pclose(fp);
    return 0;
}

int main() {
    int num_processes = 10;
    process_info_t proc_info[num_processes];

    get_process_info(proc_info, num_processes);
    print_process_info(proc_info, num_processes);

    return 0;
}