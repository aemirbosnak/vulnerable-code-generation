//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PROCESSES 50

typedef struct {
    char name[20];
    int pid;
    int ppid;
    int state;
    int cpu_time;
    int memory;
} process_t;

void get_processes(process_t *processes) {
    char path[100];
    sprintf(path, "/proc/%d/status", 1);
    int fd = open(path, O_RDONLY);
    char line[100];
    int count = 0;
    while (fgets(line, 100, fd)) {
        if (count == MAX_PROCESSES) {
            break;
        }
        if (strncmp(line, "Name:", 5) == 0) {
            strncpy(processes[count].name, line+6, 19);
            processes[count].name[19] = '\0';
        } else if (strncmp(line, "Pid:", 4) == 0) {
            processes[count].pid = atoi(line+5);
        } else if (strncmp(line, "PPid:", 5) == 0) {
            processes[count].ppid = atoi(line+6);
        } else if (strncmp(line, "State:", 6) == 0) {
            processes[count].state = atoi(line+7);
        } else if (strncmp(line, "CPU(s):", 8) == 0) {
            processes[count].cpu_time = atoi(line+9);
        } else if (strncmp(line, "VmSize:", 7) == 0) {
            processes[count].memory = atoi(line+9);
        }
        count++;
    }
    close(fd);
}

void print_processes(process_t *processes, int count) {
    printf("Name\tPID\tPPID\tState\tCPU\tMemory\n");
    for (int i=0; i<count; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].ppid, processes[i].state, processes[i].cpu_time, processes[i].memory);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int count = 0;
    get_processes(processes);
    print_processes(processes, count);
    return 0;
}