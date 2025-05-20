//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <sample_period_in_seconds>\n", argv[0]);
        return -1;
    }

    int sample_period = atoi(argv[1]);
    if (sample_period <= 0) {
        printf("Sample period should be greater than 0.\n");
        return -1;
    }

    struct timeval cur_time;
    struct timeval prev_time;

    while (1) {
        gettimeofday(&prev_time, NULL);
        FILE* fp = fopen("/proc/stat", "r");
        if (!fp) {
            printf("Failed to open /proc/stat.\n");
            return -1;
        }

        char buffer[256];
        if (!fgets(buffer, sizeof(buffer), fp)) {
            printf("Failed to read /proc/stat.\n");
            return -1;
        }

        fclose(fp);

        unsigned long long int user, nice, sys, idle, iowait, irq, sirq;
        sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu",
               &user, &nice, &sys, &idle, &iowait, &irq, &sirq);
        unsigned long long int prev_idle = idle + iowait;

        sleep(sample_period);

        gettimeofday(&cur_time, NULL);
        fp = fopen("/proc/stat", "r");
        if (!fp) {
            printf("Failed to open /proc/stat.\n");
            return -1;
        }

        if (!fgets(buffer, sizeof(buffer), fp)) {
            printf("Failed to read /proc/stat.\n");
            return -1;
        }

        fclose(fp);

        sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu",
               &user, &nice, &sys, &idle, &iowait, &irq, &sirq);
        unsigned long long int cur_idle = idle + iowait;

        unsigned long long int prev_total = prev_idle + user + nice + sys + irq + sirq;
        unsigned long long int cur_total = cur_idle + user + nice + sys + irq + sirq;

        float cpu_usage = (float)(1 - (cur_idle - prev_idle) / (float)(cur_total - prev_total)) * 100;
        printf("%.2f%% CPU usage.\n", cpu_usage);

        prev_time = cur_time;
    }

    return 0;
}