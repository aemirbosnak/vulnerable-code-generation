//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100 // Maximum number of processes to monitor

// Structure to hold process information
typedef struct {
    char process_name[50]; // Name of the process
    int process_id; // Process ID
    int ram_usage; // RAM usage in KB
} Process;

// Function to get the RAM usage of a process
int get_ram_usage(int process_id) {
    FILE *file = fopen("/proc/self/status", "r");
    char line[100];
    int ram_usage = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, "VmSize:")!= NULL) {
            sscanf(line, "VmSize: %d kB", &ram_usage);
            break;
        }
    }

    fclose(file);
    return ram_usage;
}

// Function to print the RAM usage of all processes
void print_ram_usage() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    FILE *file = fopen("/proc/self/status", "r");
    char line[100];
    int process_id = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, "Name:")!= NULL) {
            sscanf(line, "Name: %s", processes[num_processes].process_name);
        } else if (strstr(line, "Pid:")!= NULL) {
            sscanf(line, "Pid: %d", &processes[num_processes].process_id);
            processes[num_processes].ram_usage = get_ram_usage(processes[num_processes].process_id);
            num_processes++;
        }
    }

    fclose(file);

    printf("Process Name\tProcess ID\tRAM Usage (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%d\t%d\n", processes[i].process_name, processes[i].process_id, processes[i].ram_usage);
    }
}

int main() {
    print_ram_usage();
    return 0;
}