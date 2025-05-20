//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CPUS 128

void read_cpu_info(long long *user, long long *nice, long long *system, long long *idle, long long *iowait, long long *irq, long long *softirq, long long *steal, long long *guest, long long *guest_nice) {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[256];
    if (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "cpu %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
               user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice);
    }
    fclose(fp);
}

double calculate_cpu_usage(long long *prev, long long *curr) {
    long long total_prev = prev[0] + prev[1] + prev[2] + prev[3] + prev[4] + prev[5] + prev[6] + prev[7] + prev[8] + prev[9];
    long long total_curr = curr[0] + curr[1] + curr[2] + curr[3] + curr[4] + curr[5] + curr[6] + curr[7] + curr[8] + curr[9];

    long long total_idle_prev = prev[3]; // idle
    long long total_idle_curr = curr[3]; // idle

    long long total_diff = total_curr - total_prev;
    long long idle_diff = total_idle_curr - total_idle_prev;

    return (1.0 - ((double) idle_diff / (double) total_diff)) * 100.0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interval in seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int interval = atoi(argv[1]);
    if (interval < 1) {
        fprintf(stderr, "Interval must be greater than 0.\n");
        return EXIT_FAILURE;
    }

    long long prev_cpu[10] = {0}, curr_cpu[10] = {0};

    while (true) {
        read_cpu_info(&prev_cpu[0], &prev_cpu[1], &prev_cpu[2], &prev_cpu[3], &prev_cpu[4], &prev_cpu[5], &prev_cpu[6], &prev_cpu[7], &prev_cpu[8], &prev_cpu[9]);

        sleep(interval);

        read_cpu_info(&curr_cpu[0], &curr_cpu[1], &curr_cpu[2], &curr_cpu[3], &curr_cpu[4], &curr_cpu[5], &curr_cpu[6], &curr_cpu[7], &curr_cpu[8], &curr_cpu[9]);

        double cpu_usage = calculate_cpu_usage(prev_cpu, curr_cpu);
        printf("CPU usage over the last %d second(s): %.2f%%\n", interval, cpu_usage);
    }

    return EXIT_SUCCESS;
}