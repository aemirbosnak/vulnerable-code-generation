//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/sysinfo.h>

#define MAX_CPU 4
#define SLEEP_DURATION 1

typedef struct {
    int user;
    int nice;
    int system;
    int idle;
} CPUUsage;

void parse_cpu_line(char *line, CPUUsage *usage) {
    sscanf(line, "cpu %d %d %d %d", &usage->user, &usage->nice, &usage->system, &usage->idle);
}

void get_cpu_usage(CPUUsage *usage) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[256];
    fgets(line, sizeof(line), fp);  // Read first line
    fclose(fp);
    
    parse_cpu_line(line, usage);
}

void display_cpu_usage(CPUUsage *prev, CPUUsage *curr) {
    int total_prev = prev->user + prev->nice + prev->system + prev->idle;
    int total_curr = curr->user + curr->nice + curr->system + curr->idle;
    
    int idle_diff = curr->idle - prev->idle;
    int total_diff = total_curr - total_prev;
    int used_diff = total_diff - idle_diff;

    float usage_percentage = (float)used_diff / total_diff * 100;

    printf("CPU Usage: %.2f%%\n", usage_percentage);
}

void monitor_cpu_usage() {
    CPUUsage prev_usage = {0};
    CPUUsage curr_usage = {0};

    while (1) {
        get_cpu_usage(&curr_usage);
        if (prev_usage.idle != 0) {
            display_cpu_usage(&prev_usage, &curr_usage);
        }
        prev_usage = curr_usage;
        sleep(SLEEP_DURATION);
    }
}

void print_cpu_usage_header() {
    printf("%-10s%-10s%-10s%-10s\n", "User", "Nice", "System", "Idle");
}

void log_cpu_usage(CPUUsage *usage) {
    FILE *log_file = fopen("cpu_usage.log", "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return;
    }
    fprintf(log_file, "User: %d, Nice: %d, System: %d, Idle: %d\n", usage->user, usage->nice, usage->system, usage->idle);
    fclose(log_file);
}

void monitor_cpu_usage_with_logging() {
    CPUUsage prev_usage = {0};
    CPUUsage curr_usage = {0};

    print_cpu_usage_header();
    while (1) {
        get_cpu_usage(&curr_usage);
        if (prev_usage.idle != 0) {
            display_cpu_usage(&prev_usage, &curr_usage);
            log_cpu_usage(&curr_usage);
        }
        prev_usage = curr_usage;
        sleep(SLEEP_DURATION);
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "--log") == 0) {
        monitor_cpu_usage_with_logging();
    } else {
        monitor_cpu_usage();
    }
    return 0;
}