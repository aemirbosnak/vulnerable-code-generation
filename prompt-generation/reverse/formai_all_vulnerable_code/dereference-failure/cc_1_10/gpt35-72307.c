//FormAI DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_MEM_USAGE 80 // Maximum memory usage percentage
#define MIN_FREE_MEM 1024 // Minimum free memory in MB
#define MAX_CPU_USAGE 75 // Maximum CPU usage percentage
#define SLEEP_TIME 5 // Sleep time in seconds between checks

double get_cpu_usage() {
    FILE* file = fopen("/proc/stat", "r");
    if (file == NULL) {
        return -1.0;
    }
    char line[256];
    fgets(line, sizeof(line), file);
    fclose(file);
    char* cpu = strtok(line, " ");
    unsigned long long user = strtoull(strtok(NULL, " "), NULL, 0);
    unsigned long long nice = strtoull(strtok(NULL, " "), NULL, 0);
    unsigned long long system = strtoull(strtok(NULL, " "), NULL, 0);
    unsigned long long idle = strtoull(strtok(NULL, " "), NULL, 0);
    unsigned long long iowait = strtoull(strtok(NULL, " "), NULL, 0);
    unsigned long long irq = strtoull(strtok(NULL, " "), NULL, 0);
    unsigned long long softirq = strtoull(strtok(NULL, " "), NULL, 0);
    unsigned long long steal = strtoull(strtok(NULL, " "), NULL, 0);
    unsigned long long total = user + nice + system + idle + iowait + irq + softirq + steal;
    return (double)(total - idle) / (double)total * 100.0;
}

bool send_notification(const char* message) {
    // Stub function to send notification via email, SMS, or other means
    return true;
}

int main(int argc, char** argv) {
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    while (true) {
        // Check memory usage
        FILE* file = fopen("/proc/meminfo", "r");
        if (file == NULL) {
            fprintf(stderr, "Error opening /proc/meminfo\n");
            exit(1);
        }
        char line[256];
        unsigned long mem_total = 0, mem_free = 0, buffers = 0, cached = 0;
        while (fgets(line, sizeof(line), file)) {
            char* name = strtok(line, ":");
            unsigned long value = strtoul(strtok(NULL, " "), NULL, 0);
            if (strcmp(name, "MemTotal") == 0) {
                mem_total = value;
            } else if (strcmp(name, "MemFree") == 0) {
                mem_free = value;
            } else if (strcmp(name, "Buffers") == 0) {
                buffers = value;
            } else if (strcmp(name, "Cached") == 0) {
                cached = value;
            }
        }
        fclose(file);
        unsigned long total_used = mem_total - mem_free - buffers - cached;
        double usage_percentage = (double)total_used / (double)mem_total * 100.0;
        if (usage_percentage >= MAX_MEM_USAGE || mem_free <= MIN_FREE_MEM) {
            char message[256];
            snprintf(message, sizeof(message), "Memory usage is at %.2f%% (%lu MB free)", usage_percentage, mem_free);
            if (!send_notification(message)) {
                fprintf(stderr, "Error sending notification\n");
            }
        }
        // Check CPU usage
        double cpu_usage = get_cpu_usage();
        if (cpu_usage >= MAX_CPU_USAGE) {
            char message[256];
            snprintf(message, sizeof(message), "CPU usage is at %.2f%%", cpu_usage);
            if (!send_notification(message)) {
                fprintf(stderr, "Error sending notification\n");
            }
        }
        // Sleep for a while
        gettimeofday(&end_time, NULL);
        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        if (elapsed_time < SLEEP_TIME) {
            usleep((SLEEP_TIME - elapsed_time) * 1000000);
        }
        gettimeofday(&start_time, NULL);
    }
    return 0;
}