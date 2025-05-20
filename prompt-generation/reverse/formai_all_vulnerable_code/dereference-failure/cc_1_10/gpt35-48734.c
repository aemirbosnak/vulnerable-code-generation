//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROC_FILENAME_LENGTH 256
#define LINE_BUFFER_SIZE 512
#define CPU_USAGE_REFRESH_INTERVAL 1

typedef struct cpu_stats {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
} cpu_stats;

void get_cpu_stats(cpu_stats *stats) {
    char line_buffer[LINE_BUFFER_SIZE];
    FILE *proc_file = fopen("/proc/stat", "r");

    if (proc_file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    if (fgets(line_buffer, LINE_BUFFER_SIZE, proc_file) == NULL) {
        perror("Failed to read line from /proc/stat");
        exit(EXIT_FAILURE);
    }

    if (strncmp(line_buffer, "cpu ", 4) != 0) {
        perror("/proc/stat does not start with \"cpu \"");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line_buffer + 4, " ");
    stats->user = strtoull(token, NULL, 0);

    token = strtok(NULL, " ");
    stats->nice = strtoull(token, NULL, 0);

    token = strtok(NULL, " ");
    stats->system = strtoull(token, NULL, 0);

    token = strtok(NULL, " ");
    stats->idle = strtoull(token, NULL, 0);

    token = strtok(NULL, " ");
    stats->iowait = strtoull(token, NULL, 0);

    token = strtok(NULL, " ");
    stats->irq = strtoull(token, NULL, 0);

    token = strtok(NULL, " ");
    stats->softirq = strtoull(token, NULL, 0);

    fclose(proc_file);
}

int main() {
    cpu_stats prev_stats = { 0, 0, 0, 0, 0, 0, 0 };
    cpu_stats curr_stats;

    while (1) {
        get_cpu_stats(&curr_stats);

        unsigned long long prev_idle_time = prev_stats.idle + prev_stats.iowait;
        unsigned long long curr_idle_time = curr_stats.idle + curr_stats.iowait;

        unsigned long long prev_total_time = prev_stats.user + prev_stats.nice + prev_stats.system + prev_stats.idle + prev_stats.iowait + prev_stats.irq + prev_stats.softirq;
        unsigned long long curr_total_time = curr_stats.user + curr_stats.nice + curr_stats.system + curr_stats.idle + curr_stats.iowait + curr_stats.irq + curr_stats.softirq;

        unsigned long long total_time_diff = curr_total_time - prev_total_time;
        unsigned long long idle_time_diff = curr_idle_time - prev_idle_time;

        float cpu_usage = 100.0f * ((float)(total_time_diff - idle_time_diff) / (float)total_time_diff);

        printf("CPU Usage: %.2f%%\n", cpu_usage);

        prev_stats = curr_stats;

        sleep(CPU_USAGE_REFRESH_INTERVAL);
    }

    return 0;
}