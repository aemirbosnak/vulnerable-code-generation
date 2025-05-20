//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[20];
    float usage;
} process;

void get_processes(process* processes, int* num_processes) {
    FILE* file = fopen("/proc/self/status", "r");
    char line[BUFFER_SIZE];
    int i = 0;
    while (fgets(line, BUFFER_SIZE, file)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strncpy(processes[i].name, line + 6, 20);
        } else if (strncmp(line, "VmSize:", 8) == 0) {
            processes[i].usage = atof(line + 8);
        }
        i++;
    }
    *num_processes = i;
    fclose(file);
}

void sort_processes(process* processes, int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[j].usage < processes[i].usage) {
                process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void print_processes(process* processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%-20s %.2f%%\n", processes[i].name, processes[i].usage * 100);
    }
}

int main() {
    process processes[100];
    int num_processes = 0;
    get_processes(processes, &num_processes);
    sort_processes(processes, num_processes);
    print_processes(processes, num_processes);
    return 0;
}