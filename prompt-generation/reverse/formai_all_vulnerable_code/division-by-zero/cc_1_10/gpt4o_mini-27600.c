//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define UPDATE_INTERVAL 1 // Update interval in seconds

volatile sig_atomic_t keep_running = 1;

void handle_signal(int signal) {
    keep_running = 0;
}

void print_cpu_usage() {
    FILE *file;
    char buffer[256];
    unsigned long long idle_time, total_time;
    unsigned long long user_time, nice_time, system_time, idle_time_temp, iowait_time;
    unsigned long long total_usage;

    // Reading CPU times from /proc/stat
    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line which contains aggregate CPU times
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu %llu",
            &user_time, &nice_time, &system_time, &idle_time_temp, 
            &iowait_time, &idle_time, &total_time);
            
        // Calculate total_time and idle_time
        total_time = user_time + nice_time + system_time + idle_time_temp + iowait_time + idle_time;
        idle_time = idle_time + idle_time_temp;
    } else {
        perror("Failed to read CPU stats");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);

    // Compute CPU usage percentage
    unsigned long long cpu_usage = 100 * (total_time - idle_time) / total_time;

    printf("CPU Usage: %llu%%\n", cpu_usage);
}

void monitor_cpu_usage() {
    while (keep_running) {
        print_cpu_usage();
        sleep(UPDATE_INTERVAL);
    }
}

int main() {
    signal(SIGINT, handle_signal); // Handle Ctrl+C interrupt

    printf("Starting CPU Usage Monitor...\n");
    printf("Press Ctrl+C to stop monitoring.\n");

    // Start monitoring CPU usage
    monitor_cpu_usage();

    printf("CPU Usage Monitor stopped.\n");
    return 0;
}