//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define TOTAL_MEMORY ((long int)sysconf(_SC_PHYS_PAGES) * (long int)sysconf(_SC_PAGE_SIZE))
#define TOTAL_CPU ((long int)sysconf(_SC_NPROCESSORS_ONLN))

void cpu_usage_monitor(int interval, int core_id) {
    struct rusage usage;
    int i = 0;
    while (1) {
        getrusage(RUSAGE_SELF, &usage);
        printf("Core %d CPU usage: %ld%%\n", core_id, usage.ru_utime.tv_sec * 100);
        fflush(stdout);
        sleep(interval);
        i++;
        if (i == 10) {
            printf("Total CPU usage: %ld%%\n", usage.ru_utime.tv_sec * 100);
            fflush(stdout);
            i = 0;
        }
    }
}

void memory_usage_monitor(int interval) {
    struct rusage usage;
    while (1) {
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory usage: %ld%%\n", usage.ru_maxrss * 100 / TOTAL_MEMORY);
        fflush(stdout);
        sleep(interval);
    }
}

int main(int argc, char **argv) {
    int interval = 5;
    int core_id = 0;
    int memory_interval = 10;

    if (argc > 1) {
        interval = atoi(argv[1]);
    }

    if (argc > 2) {
        core_id = atoi(argv[2]);
    }

    cpu_usage_monitor(interval, core_id);
    memory_usage_monitor(memory_interval);

    return 0;
}