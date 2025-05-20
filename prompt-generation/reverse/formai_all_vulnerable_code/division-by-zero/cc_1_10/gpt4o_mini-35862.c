//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256
#define CPU_STATS_INDEX 1

void get_cpu_usage(long long *user_time, long long *nice_time, long long *system_time, long long *idle_time) {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "cpu %lld %lld %lld %lld", user_time, nice_time, system_time, idle_time);
    }

    fclose(file);
}

void calculate_cpu_usage(long long prev_total, long long prev_idle, long long *usage) {
    long long total = prev_total - prev_idle; // Total time spent in all states
    long long idle = prev_idle; // Time spent in idle state

    long long used = total - idle; // Time spent in all busy states
    *usage = (used * 100) / total; // CPU usage percentage
}

int main() {
    long long user_time, nice_time, system_time, idle_time;
    long long prev_user_time, prev_nice_time, prev_system_time, prev_idle_time;
    long long prev_total, prev_idle;
    long long cpu_usage;

    printf("Starting CPU usage monitor...\n");
    sleep(1); // Wait for 1 second

    // Get initial CPU stats
    get_cpu_usage(&prev_user_time, &prev_nice_time, &prev_system_time, &prev_idle_time);
    
    prev_total = prev_user_time + prev_nice_time + prev_system_time + prev_idle_time;
    prev_idle = prev_idle_time;

    while (1) {
        sleep(1); // Monitor every second

        // Get new CPU stats
        get_cpu_usage(&user_time, &nice_time, &system_time, &idle_time);
        
        long long total = user_time + nice_time + system_time + idle_time;
        long long current_idle = idle_time;

        calculate_cpu_usage(total, current_idle, &cpu_usage);

        // Output the CPU usage
        printf("CPU Usage: %lld%%\n", cpu_usage);

        // Update previous values for the next round
        prev_user_time = user_time;
        prev_nice_time = nice_time;
        prev_system_time = system_time;
        prev_idle_time = idle_time;

        prev_total = total;
        prev_idle = current_idle;
    }

    return 0;
}