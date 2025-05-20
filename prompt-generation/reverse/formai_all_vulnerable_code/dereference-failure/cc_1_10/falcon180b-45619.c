//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 1024

typedef struct process {
    char name[64];
    int pid;
    int ppid;
    int status;
    int cpu_time;
    int memory_usage;
} Process;

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting...\n");
        exit(0);
    }
}

int get_process_info(int pid, Process *process) {
    char filename[32];
    sprintf(filename, "/proc/%d/stat", pid);
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read = read(fd, buffer, BUFFER_SIZE);
    close(fd);

    if (bytes_read <= 0) {
        return -1;
    }

    char *token = strtok(buffer, " ");
    strcpy(process->name, token);
    process->pid = atoi(token);
    token = strtok(NULL, " ");
    process->ppid = atoi(token);
    token = strtok(NULL, " ");
    process->status = atoi(token);
    token = strtok(NULL, " ");
    process->cpu_time = atoi(token);
    token = strtok(NULL, " ");
    process->memory_usage = atoi(token);

    return 0;
}

void print_process_info(Process *process) {
    printf("%-16s %-6d %-6d %-8s %-8d %-10d\n", process->name, process->pid, process->ppid, "", process->status, process->cpu_time);
}

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];

    signal(SIGINT, signal_handler);

    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error opening /proc directory.\n");
        return 1;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (isdigit(ent->d_name[0])) {
            int pid = atoi(ent->d_name);
            if (get_process_info(pid, &processes[num_processes]) == 0) {
                num_processes++;
            }
        }
    }

    closedir(dir);

    printf("PID\tPPID\tSTATUS\tCPU TIME\tMEMORY USAGE\n");
    for (int i = 0; i < num_processes; i++) {
        print_process_info(&processes[i]);
    }

    return 0;
}