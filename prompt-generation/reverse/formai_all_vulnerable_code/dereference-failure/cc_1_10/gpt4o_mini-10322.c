//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

void print_usage() {
    printf("Usage: ram_monitor [options]\n");
    printf("Options:\n");
    printf("  -p <process_id>  Monitor a specific process by ID\n");
    printf("  -t <interval>    Set the monitoring interval in seconds (default: 1)\n");
    printf("  -h               Display this help message\n");
}

void parse_arguments(int argc, char *argv[], int *pid, int *interval) {
    *pid = -1;
    *interval = 1;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-p") == 0 && i + 1 < argc) {
            *pid = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-t") == 0 && i + 1 < argc) {
            *interval = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-h") == 0) {
            print_usage();
            exit(0);
        }
    }
}

void get_ram_usage(int pid, float *memory_usage) {
    char filename[BUFFER_SIZE];
    sprintf(filename, "/proc/%d/statm", pid);
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("Error opening file");
        *memory_usage = -1;
        return;
    }

    int total_pages;
    fscanf(file, "%d", &total_pages);
    fclose(file);

    long page_size = sysconf(_SC_PAGESIZE);
    *memory_usage = total_pages * page_size / (1024.0 * 1024.0); // Convert to MB
}

void monitor_process(int pid, int interval) {
    float memory_usage;

    while (1) {
        get_ram_usage(pid, &memory_usage);

        if (memory_usage < 0) {
            printf("Process with PID %d not found.\n", pid);
            break;
        }

        printf("Current RAM Usage of PID %d: %.2f MB\n", pid, memory_usage);
        sleep(interval);
    }
}

void monitor_all_processes(int interval) {
    FILE *file = fopen("/proc/meminfo", "r");
    char buffer[BUFFER_SIZE];

    if (file == NULL) {
        perror("Error opening /proc/meminfo");
        return;
    }

    while (1) {
        rewind(file);
        printf("\nMemory Information:\n");
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }

        sleep(interval);
        printf("\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    int pid, interval;

    // Parse command line arguments
    parse_arguments(argc, argv, &pid, &interval);

    if (pid > -1) {
        monitor_process(pid, interval);
    } else {
        monitor_all_processes(interval);
    }

    return 0;
}