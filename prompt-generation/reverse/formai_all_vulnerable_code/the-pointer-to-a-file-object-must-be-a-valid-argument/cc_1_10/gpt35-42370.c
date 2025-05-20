//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS_COUNT 100
#define MAX_PROCESS_NAME_LENGTH 25

// Structure to hold process info
typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int ram_usage;
    int parent_pid;
} Process;

// Function to recursively calculate RAM usage of a given process and its child processes
int calculate_ram_usage(Process processes[], int count, int pid) {
    int ram_usage = 0;
    for (int i = 0; i < count; i++) {
        if (processes[i].parent_pid == pid) {
            ram_usage += processes[i].ram_usage + calculate_ram_usage(processes, count, processes[i].pid);
        }
    }
    return ram_usage;
}

int main() {
    Process processes[MAX_PROCESS_COUNT];
    int count = 0;

    FILE *fp = fopen("/proc/meminfo", "r");
    char line[100];
    while (fgets(line, 100, fp)) {
        if (strncmp(line, "Pid:", 4) == 0) {
            int pid;
            sscanf(line, "Pid: %d", &pid);

            char cmd_line[100];
            sprintf(cmd_line, "/proc/%d/cmdline", pid);
            FILE *cmd_fp = fopen(cmd_line, "r");
            char name[MAX_PROCESS_NAME_LENGTH];
            fgets(name, MAX_PROCESS_NAME_LENGTH, cmd_fp);
            fclose(cmd_fp);

            int ram_usage;
            sscanf(line, "Ram usage: %d KB", &ram_usage);

            int parent_pid;
            sscanf(line, "Parent PID: %d", &parent_pid);

            Process p = {pid, name, ram_usage, parent_pid};
            processes[count++] = p;
        }
    }
    fclose(fp);

    int total_ram_usage = calculate_ram_usage(processes, count, 0);
    printf("Total RAM usage (including child processes): %d KB\n", total_ram_usage);

    return 0;
}