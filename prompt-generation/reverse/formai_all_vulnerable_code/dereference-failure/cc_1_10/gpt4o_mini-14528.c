//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define STAT_BUFFER_SIZE 256

void get_cpu_usage(double* cpu_usage) {
    int fd = open("/proc/stat", O_RDONLY);
    if (fd < 0) {
        perror("Failed to open /proc/stat");
        return;
    }

    char buffer[STAT_BUFFER_SIZE];
    read(fd, buffer, STAT_BUFFER_SIZE);
    close(fd);

    char* token = strtok(buffer, " ");
    token = strtok(NULL, " "); // Skip "cpu"
    
    long unsigned int user = strtoul(token, NULL, 10);
    token = strtok(NULL, " ");
    long unsigned int nice = strtoul(token, NULL, 10);
    token = strtok(NULL, " ");
    long unsigned int system = strtoul(token, NULL, 10);
    token = strtok(NULL, " ");
    long unsigned int idle = strtoul(token, NULL, 10);
    token = strtok(NULL, " ");
    long unsigned int iowait = strtoul(token, NULL, 10);
    token = strtok(NULL, " ");
    long unsigned int irq = strtoul(token, NULL, 10);
    token = strtok(NULL, " ");
    long unsigned int softirq = strtoul(token, NULL, 10);
    
    long unsigned int total_cpu_time = user + nice + system + idle + iowait + irq + softirq;

    *cpu_usage = 100.0 * (total_cpu_time - idle) / total_cpu_time;
}

void display_cpu_usage() {
    double cpu_usage;
    get_cpu_usage(&cpu_usage);

    printf("Current CPU Usage: %.2f%%\n", cpu_usage);
}

void monitor_cpu_usage(int interval) {
    while (1) {
        display_cpu_usage();
        sleep(interval);
    }
}

int main(int argc, char* argv[]) {
    int interval = 1; // Default interval is 1 second

    if (argc > 1) {
        int user_interval = atoi(argv[1]);
        if (user_interval > 0) {
            interval = user_interval;
        } else {
            printf("Invalid interval, using default 1 second.\n");
        }
    }

    printf("Starting CPU Usage Monitor...\n");
    printf("Monitoring every %d seconds.\n", interval);
    monitor_cpu_usage(interval);

    return 0;
}