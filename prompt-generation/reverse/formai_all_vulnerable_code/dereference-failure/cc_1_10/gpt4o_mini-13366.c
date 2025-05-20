//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define BUF_SIZE 256

// Function to get current RAM usage in MB
void getRAMUsage(double *total, double *free, double *used) {
    struct sysinfo sys_info;

    if (sysinfo(&sys_info) == -1) {
        perror("sysinfo");
        exit(EXIT_FAILURE);
    }

    *total = sys_info.totalram / (1024.0 * 1024.0);
    *free = sys_info.freeram / (1024.0 * 1024.0);
    *used = *total - *free;
}

// Function to format the output
void formatOutput(double total, double free, double used) {
    printf("------------------------------------------------------\n");
    printf("                 RAM Usage Monitor                     \n");
    printf("------------------------------------------------------\n");
    printf("Total RAM: %.2f MB\n", total);
    printf("Free RAM: %.2f MB\n", free);
    printf("Used RAM: %.2f MB\n", used);
    printf("------------------------------------------------------\n");
}

// Function to log RAM usage to a file
void logRAMUsage(double total, double free, double used) {
    FILE *logFile = fopen("ram_usage.log", "a");
    if (logFile == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }

    fprintf(logFile, "Total RAM: %.2f MB, Free RAM: %.2f MB, Used RAM: %.2f MB\n", total, free, used);
    fclose(logFile);
}

// Function to display memory usage over time
void monitorRAMUsage(int interval, int count) {
    double total, free, used;

    for (int i = 0; i < count; i++) {
        getRAMUsage(&total, &free, &used);
        formatOutput(total, free, used);
        logRAMUsage(total, free, used);
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 5;  // Default interval in seconds
    int count = 10;    // Default number of samples

    // Check for command line arguments
    if (argc > 1) {
        interval = atoi(argv[1]);
    }
    if (argc > 2) {
        count = atoi(argv[2]);
    }

    printf("Monitoring RAM usage every %d seconds for %d intervals.\n", interval, count);
    monitorRAMUsage(interval, count);

    return 0;
}