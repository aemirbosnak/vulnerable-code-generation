//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LINE_LENGTH 256

void get_cpu_info(long long *user, long long *nice, long long *system, long long *idle, long long *iowait) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Unable to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    if (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "cpu %lld %lld %lld %lld %lld", user, nice, system, idle, iowait);
    }

    fclose(fp);
}

double calculate_cpu_usage(long long prev_total, long long prev_idle, long long curr_total, long long curr_idle) {
    long long total_diff = curr_total - prev_total;
    long long idle_diff = curr_idle - prev_idle;

    return 100.0 * (total_diff - idle_diff) / total_diff; // Calculate percentage
}

void monitor_cpu_usage(int interval, int duration) {
    long long user1, nice1, system1, idle1, iowait1;
    long long user2, nice2, system2, idle2, iowait2;

    printf("Monitoring CPU usage for %d seconds at intervals of %d seconds...\n", duration, interval);
    for (int i = 0; i < duration / interval; i++) {
        get_cpu_info(&user1, &nice1, &system1, &idle1, &iowait1);
        sleep(interval);
        get_cpu_info(&user2, &nice2, &system2, &idle2, &iowait2);

        long long prev_total = user1 + nice1 + system1 + idle1 + iowait1;
        long long curr_total = user2 + nice2 + system2 + idle2 + iowait2;

        double cpu_usage = calculate_cpu_usage(prev_total, idle1, curr_total, idle2);
        printf("CPU Usage: %.2f%%\n", cpu_usage);
    }
}

int main(int argc, char *argv[]) {
    int interval = 1; // default to 1 second
    int duration = 10; // default to 10 seconds

    if (argc > 1) {
        interval = atoi(argv[1]);
    }
    if (argc > 2) {
        duration = atoi(argv[2]);
    }

    if (interval <= 0 || duration <= 0) {
        fprintf(stderr, "Invalid interval or duration. Both must be positive integers.\n");
        return EXIT_FAILURE;
    }

    monitor_cpu_usage(interval, duration);
    return EXIT_SUCCESS;
}