//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 128

// Function to read CPU information from /proc/stat
void read_cpu_usage(long *user, long *nice, long *system, long *idle, long *iowait, long *irq,
                    long *softirq, long *steal, long *guest, long *guest_nice) {
    FILE *fp;
    char buffer[BUFFER_SIZE];

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }

    fgets(buffer, BUFFER_SIZE, fp);
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
           user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice);

    fclose(fp);
}

// Function to calculate total CPU time
long total_cpu_time(long user, long nice, long system, long idle,
                    long iowait, long irq, long softirq, long steal,
                    long guest, long guest_nice) {
    return user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;
}

// Function to monitor CPU usage
void monitor_cpu_usage(int interval) {
    long prev_user = 0, prev_nice = 0, prev_system = 0, prev_idle = 0;
    long prev_total = 0;

    while (1) {
        long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
        read_cpu_usage(&user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
        
        long total = total_cpu_time(user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice);
        if (prev_total != 0) {
            // Calculate CPU usage in percentage
            long total_diff = total - prev_total;
            long idle_diff = idle - prev_idle;
            double cpu_usage = 100.0 * (total_diff - idle_diff) / total_diff;

            printf("CPU Usage: %.2f%%\n", cpu_usage);
        }

        // Update previous values
        prev_user = user;
        prev_nice = nice;
        prev_system = system;
        prev_idle = idle;
        prev_total = total;

        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 1; // Default interval is 1 second

    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Invalid interval specified. Using default 1 second.\n");
            interval = 1;
        }
    }

    printf("Monitoring CPU usage every %d second(s)...\n", interval);
    monitor_cpu_usage(interval);

    return 0;
}