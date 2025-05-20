//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_CPU 8
#define SAMPLE_INTERVAL 1 // in seconds

// Function to read the CPU usage from /proc/stat
void get_cpu_usage(double *cpu_usage) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return;
    }

    char line[256];
    // Reading the first line which contains CPU statistics
    fgets(line, sizeof(line), fp);
    fclose(fp);

    // Calculate total and idle times
    long long user, nice, system, idle, iowait, irq, softirq, steal, total;
    sscanf(line, "cpu %lld %lld %lld %lld %lld %lld %lld %lld", 
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
    
    total = user + nice + system + idle + iowait + irq + softirq + steal;

    // Calculate CPU usage as a percentage
    *cpu_usage = 100.0 * (1.0 - ((double)idle / total));
}

// Function to display CPU usage over time
void display_cpu_usage(int duration) {
    printf("Monitoring CPU usage for %d seconds...\n", duration);
    for (int i = 0; i < duration; i++) {
        double cpu_usage;
        get_cpu_usage(&cpu_usage);
        printf("CPU Usage at %02d:%02d: %.2f%%\n", (int)time(NULL)/3600 % 24,
               (int)(time(NULL)/60) % 60, cpu_usage);
        sleep(SAMPLE_INTERVAL);
    }
}

// Entry point of the program
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <duration_in_seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int duration = atoi(argv[1]);
    if (duration <= 0) {
        fprintf(stderr, "Duration must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    display_cpu_usage(duration);

    return EXIT_SUCCESS;
}