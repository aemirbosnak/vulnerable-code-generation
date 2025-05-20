//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

// Function to calculate CPU usage
float calculate_cpu_usage() {
    // Reading /proc/stat to get CPU usage statistics
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    unsigned long int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    fscanf(file, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu", 
        &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    fclose(file);

    // Calculating total and active time
    unsigned long int total_time = user + nice + system + idle + iowait + irq + softirq + steal;
    unsigned long int active_time = total_time - idle;

    // Percentage of CPU usage
    return ((float)active_time / total_time) * 100.0;
}

// Function to log CPU usage data to a file
void log_cpu_usage(const char *filename, float cpu_usage) {
    FILE *log_file = fopen(filename, "a");
    if (!log_file) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }

    time_t current_time;
    time(&current_time);
    fprintf(log_file, "Time: %sCPU Usage: %.2f%%\n", ctime(&current_time), cpu_usage);
    
    fclose(log_file);
}

// Function to monitor CPU usage continuously
void monitor_cpu_usage(const char *filename, int duration, int interval) {
    for (int i = 0; i < duration; i++) {
        float cpu_usage = calculate_cpu_usage();
        log_cpu_usage(filename, cpu_usage);
        sleep(interval);
    }
}

// Main function to initiate the CPU usage monitor
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <output_file> <duration_in_seconds> <interval_in_seconds>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *output_file = argv[1];
    int duration = atoi(argv[2]);
    int interval = atoi(argv[3]);

    if (duration <= 0 || interval <= 0) {
        fprintf(stderr, "Duration and interval should be positive integers.\n");
        exit(EXIT_FAILURE);
    }

    printf("Starting CPU usage monitor...\n");
    printf("Logging to: %s\n", output_file);
    printf("Duration: %d seconds, Interval: %d seconds\n", duration, interval);

    monitor_cpu_usage(output_file, duration, interval);

    printf("Monitoring finished.\n");
    return 0;
}