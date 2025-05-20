//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <signal.h>

volatile sig_atomic_t stop_signal = 0;

void signal_handler(int signo) {
    if (signo == SIGINT) {
        stop_signal = 1;
    }
}

void display_memory_usage() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    long totalPhysMemory = memInfo.totalram;
    totalPhysMemory += memInfo.totalswap;
    totalPhysMemory *= memInfo.mem_unit;

    long physMemUsed = memInfo.totalram - memInfo.freeram;
    physMemUsed += memInfo.bufferram;

    double memUsage = (double)physMemUsed / totalPhysMemory * 100;

    printf("Total Memory: %.2lf GB\n", (double)totalPhysMemory / (1024 * 1024 * 1024));
    printf("Used Memory: %.2lf GB (%.2lf%%)\n", (double)physMemUsed / (1024 * 1024 * 1024), memUsage);
}

void monitor_memory_usage(int interval) {
    while (!stop_signal) {
        display_memory_usage();
        sleep(interval);
        printf("\n");
    }
    printf("Memory monitoring stopped.\n");
}

void display_usage_instructions() {
    printf("Usage: ./memory_monitor [interval_in_seconds]\n");
    printf("Example: ./memory_monitor 5\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage_instructions();
        return EXIT_FAILURE;
    }

    int interval = atoi(argv[1]);
    if (interval <= 0) {
        fprintf(stderr, "Interval must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Set up signal handling for cleanup
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    printf("Starting memory usage monitor with an interval of %d seconds...\n", interval);
    monitor_memory_usage(interval);

    return EXIT_SUCCESS;
}