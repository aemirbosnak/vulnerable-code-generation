//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>

typedef struct cpu_stat {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
    unsigned long long guest;
    unsigned long long guest_nice;
} cpu_stat_t;

int main() {
    int fd = open("/proc/stat", O_RDONLY);
    if (fd < 0) {
        printf("Failed to open /proc/stat\n");
        return 1;
    }

    cpu_stat_t cpu_stat;
    if (read(fd, &cpu_stat, sizeof(cpu_stat))!= sizeof(cpu_stat)) {
        printf("Failed to read from /proc/stat\n");
        return 1;
    }

    close(fd);

    unsigned long long total_time = 0;
    unsigned long long prev_total = 0;
    while (1) {
        usleep(1000000); // Sleep for 1 second

        int fd = open("/proc/stat", O_RDONLY);
        if (fd < 0) {
            printf("Failed to open /proc/stat\n");
            return 1;
        }

        cpu_stat_t new_cpu_stat;
        if (read(fd, &new_cpu_stat, sizeof(cpu_stat))!= sizeof(cpu_stat)) {
            printf("Failed to read from /proc/stat\n");
            return 1;
        }

        unsigned long long new_total_time = new_cpu_stat.user + new_cpu_stat.nice + new_cpu_stat.system + new_cpu_stat.idle + new_cpu_stat.iowait + new_cpu_stat.irq + new_cpu_stat.softirq + new_cpu_stat.steal + new_cpu_stat.guest + new_cpu_stat.guest_nice;
        unsigned long long cpu_usage = (new_total_time - prev_total) / (new_total_time + prev_total) * 100;

        printf("CPU usage: %llu%%\n", cpu_usage);

        prev_total = new_total_time;

        close(fd);
    }

    return 0;
}