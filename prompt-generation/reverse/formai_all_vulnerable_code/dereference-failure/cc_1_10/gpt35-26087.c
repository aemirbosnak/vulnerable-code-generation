//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the constants
#define MAX_LEN 25
#define UNUSED_MEMORY_PERCENTAGE 20

// Define the structure to store the data for each process
typedef struct {
    char pid[MAX_LEN];
    int memory_usage;
} Process;

// Function to calculate the memory usage percentage for each process
int memory_usage_percentage(int total_memory, int memory_used) {
    return (memory_used * 100) / total_memory;
}

int main() {
    // Get the total amount of available memory
    FILE* fp_mem_info = fopen("/proc/meminfo", "r");
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int total_memory = 0;

    while ((read = getline(&line, &len, fp_mem_info)) != -1) {
        char* token = strtok(line, " ");
        if (strcmp(token, "MemTotal:") == 0) {
            token = strtok(NULL, " ");
            total_memory = atoi(token) / 1024; // convert to MB
            break;
        }
    }

    fclose(fp_mem_info);

    // Check the memory usage of each process
    FILE* fp_mem_stat = fopen("/proc/meminfo", "r");
    FILE* fp_mem_pid = fopen("/proc/meminfo", "r");
    Process processes[MAX_LEN];
    int process_count = 0;

    while ((read = getline(&line, &len, fp_mem_pid)) != -1) {
        char* token = strtok(line, " ");
        if (strstr(token, "pid") && strstr(token, "smaps")) {
            Process p;
            char* pid_token = strtok(token, "/");
            pid_token = strtok(NULL, "/");
            strcpy(p.pid, pid_token);            

            int memory_used = 0;
            while ((read = getline(&line, &len, fp_mem_stat)) != -1) {
                if (strstr(line, "VmHWM") && strstr(line, pid_token)) {
                    char* memory_token = strtok(line, " ");
                    memory_token = strtok(NULL, " ");
                    memory_used = atoi(memory_token) / 1024; // convert to MB
                    break;
                }
            }

            p.memory_usage = memory_usage_percentage(total_memory, memory_used);
            processes[process_count] = p;
            process_count++;
        }
    }

    fclose(fp_mem_stat);
    fclose(fp_mem_pid);

    // Print the results
    printf("Total available memory: %d MB\n\n", total_memory);
    for (int i = 0; i < process_count; i++) {
        Process p = processes[i];
        if (p.memory_usage > UNUSED_MEMORY_PERCENTAGE) {
            printf("PID: %s\nMemory usage: %d%%\n\n", p.pid, p.memory_usage);
        }
    }

    return 0;
}