//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_LINE_LENGTH 80
#define MAX_NUM_PROCESSES 100

typedef struct Process {
    int pid;
    char name[MAX_LINE_LENGTH];
    int ram_usage;
} Process;

void get_processes(Process* processes, int num_processes) {
    FILE* file = fopen("/proc/self/status", "r");
    char line[MAX_LINE_LENGTH];
    char* token;
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (strncmp(line, "VmSize:", 7) == 0) {
            processes[i].ram_usage = atoi(line + 7);
        } else if (strncmp(line, "Name:", 5) == 0) {
            strncpy(processes[i].name, line + 6, MAX_LINE_LENGTH - 1);
            processes[i].name[MAX_LINE_LENGTH - 1] = '\0';
        }
    }
    fclose(file);
}

int compare_processes(const void* a, const void* b) {
    const Process* process_a = (const Process*) a;
    const Process* process_b = (const Process*) b;
    return process_b->ram_usage - process_a->ram_usage;
}

void print_processes(Process* processes, int num_processes) {
    qsort(processes, num_processes, sizeof(Process), compare_processes);
    for (int i = 0; i < num_processes; i++) {
        printf("%d: %s (%d KB)\n", processes[i].pid, processes[i].name, processes[i].ram_usage / 1024);
    }
}

int main() {
    Process processes[MAX_NUM_PROCESSES];
    int num_processes = 0;
    get_processes(processes, MAX_NUM_PROCESSES);
    num_processes = sizeof(processes) / sizeof(Process);
    print_processes(processes, num_processes);
    return 0;
}