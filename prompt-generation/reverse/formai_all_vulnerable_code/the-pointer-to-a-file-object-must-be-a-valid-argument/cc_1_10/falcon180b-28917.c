//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024

typedef struct {
    int pid;
    char name[16];
    int memory;
} Process;

void get_processes(Process* processes) {
    char filename[64];
    sprintf(filename, "/proc/%d/status", getpid());

    FILE* file = fopen(filename, "r");

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strncpy(processes->name, line + 6, sizeof(processes->name));
        } else if (strncmp(line, "VmSize:", 8) == 0) {
            sscanf(line, "VmSize: %d kB", &processes->memory);
        }
    }

    fclose(file);
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        get_processes(&processes[num_processes]);

        if (num_processes == MAX_PROCESSES) {
            break;
        }

        num_processes++;
    }

    printf("Process Name\t\tMemory Usage (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%-16s\t%d\n", processes[i].name, processes[i].memory);
    }

    return 0;
}