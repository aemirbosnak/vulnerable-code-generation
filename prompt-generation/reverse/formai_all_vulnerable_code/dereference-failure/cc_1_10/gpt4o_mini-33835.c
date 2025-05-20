//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    long ram_usage;
} Process;

void parse_memory_info(char *line, Process *process) {
    char *token = strtok(line, " ");
    if (token != NULL) {
        process->pid = atoi(token);
        token = strtok(NULL, " ");  // Skip the process name
        if (token != NULL) {
            strncpy(process->name, token, BUFFER_SIZE);
            process->name[BUFFER_SIZE - 1] = '\0';  // Ensure null-termination
            token = strtok(NULL, " ");  // Get the Vsz memory info
            if (token != NULL) {
                process->ram_usage = atol(token) / 1024; // Convert to MB
            }
        }
    }
}

void get_memory_usage(Process *processes, int *count) {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to read /proc/stat");
        return;
    }

    char line[BUFFER_SIZE];
    *count = 0;

    while (fgets(line, sizeof(line), fp) && *count < MAX_PROCESSES) {
        if (strncmp(line, "vmstat", 6) == 0) {
            continue; // Skip header line
        }
        parse_memory_info(line, &processes[*count]);
        (*count)++;
    }

    fclose(fp);
}

void display_memory_usage(Process *processes, int count) {
    printf("+------+---------------------------+-----------+\n");
    printf("| PID  | Name                      | RAM (MB)  |\n");
    printf("+------+---------------------------+-----------+\n");
    for (int i = 0; i < count; i++) {
        printf("| %4d | %-25s | %9ld |\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
    }
    printf("+------+---------------------------+-----------+\n");
}

void monitor_memory_usage(int interval) {
    Process processes[MAX_PROCESSES];
    int count;

    while (1) {
        printf("\nMonitoring RAM usage...\n");
        get_memory_usage(processes, &count);
        display_memory_usage(processes, count);
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 5;  // Default monitoring interval

    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            printf("Invalid interval. Using default value of 5 seconds.\n");
            interval = 5;
        }
    }

    monitor_memory_usage(interval);
    return 0;
}