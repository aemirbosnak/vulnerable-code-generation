//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256
#define PROCESS_INFO_SIZE 64

typedef struct {
    int pid;
    char name[PROCESS_INFO_SIZE];
    long rss; // Resident Set Size
} Process;

void get_running_processes(Process processes[], int *count) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    *count = 0;

    // Open the /proc directory which contains process information
    for (int pid = 1; pid < MAX_PROCESSES; pid++) {
        snprintf(buffer, sizeof(buffer), "/proc/%d/stat", pid);
        file = fopen(buffer, "r");
        if (file) {
            Process p;
            // Read process information
            fscanf(file, "%d %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %ld", &p.pid, p.name, &p.rss);
            fclose(file);
            snprintf(p.name, sizeof(p.name), "%s", p.name); // Clean name
            processes[(*count)++] = p;
        }
    }
}

void display_memory_usage(Process processes[], int count) {
    long total_rss = 0;
    printf("%-10s %-30s %-10s\n", "PID", "Process Name", "Memory (KB)");
    printf("-------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-10ld\n", processes[i].pid, processes[i].name, processes[i].rss);
        total_rss += processes[i].rss;
    }
    
    printf("-------------------------------------------------------------\n");
    printf("Total Memory Usage: %ld KB\n", total_rss);
}

void monitor_memory_usage(int interval) {
    while (1) {
        Process processes[MAX_PROCESSES];
        int count = 0;

        get_running_processes(processes, &count);
        display_memory_usage(processes, count);
        
        printf("\nMonitoring memory usage... Press Ctrl+C to exit.\n\n");
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 5; // Default interval of 5 seconds

    // Check for command line argument for custom interval
    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Invalid interval. Using default (5 seconds).\n");
            interval = 5;
        }
    }

    printf("Starting memory usage monitor (Polling every %d seconds)...\n", interval);
    
    monitor_memory_usage(interval);
    
    return 0;
}