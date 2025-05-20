//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 256
#define SLEEP_SECONDS 1

void print_header() {
    printf("%-10s %-10s %-10s\n", "PID", "C-RAM", "COMMAND");
}

void print_process_info(int pid, char* command) {
    char filename[BUF_SIZE];
    sprintf(filename, "/proc/%d/status", pid);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("ERROR: Could not open file for process %d\n", pid);
        return;
    }

    char line[BUF_SIZE];
    char* c_ram_str = "";
    while (fgets(line, BUF_SIZE, file)) {
        if (strncmp(line, "VmRSS:", 6) == 0) {
            char* value = strchr(line, ':') + 1;
            int length = strlen(value);
            while (value[length-1] == '\n' || value[length-1] == ' ') {
                length--;
            }
            value[length] = '\0';
            c_ram_str = value;
            break;
        }
    }
    fclose(file);

    int c_ram = atoi(c_ram_str);
    printf("%-10d %-10d %-10s\n", pid, c_ram, command);
}

void monitor_ram_usage() {
    int prev_num_processes = 0;
    int* prev_pids = malloc(0);

    while (1) {
        // Get current list of pids
        int num_processes = 0;
        int* pids = malloc(0);

        char command[BUF_SIZE];
        FILE* cmd_file = popen("ps -eo pid,cmd --no-headers", "r");
        if (cmd_file == NULL) {
            printf("ERROR: Could not run 'ps' command\n");
            return;
        }

        char line[BUF_SIZE];
        while (fgets(line, BUF_SIZE, cmd_file)) {
            int pid;
            sscanf(line, "%d %[^\n]", &pid, command);
            pids[num_processes] = pid;
            num_processes++;
            pids = realloc(pids, num_processes * sizeof(int));
        }
        fclose(cmd_file);

        // Print header and process info if there are new processes
        if (num_processes != prev_num_processes) {
            printf("\n");
            print_header();
            for (int i = 0; i < num_processes; i++) {
                int j = 0;
                while (j < prev_num_processes && prev_pids[j] != pids[i]) {
                    j++;
                }
                if (j == prev_num_processes) {
                    print_process_info(pids[i], command);
                }
            }
        }

        // Print process info for all processes
        for (int i = 0; i < num_processes; i++) {
            print_process_info(pids[i], command);
        }

        // Update previous list of pids
        prev_num_processes = num_processes;
        free(prev_pids);
        prev_pids = pids;

        // Sleep for specified amount of time
        sleep(SLEEP_SECONDS);
    }
}

int main() {
    monitor_ram_usage();
    return 0;
}