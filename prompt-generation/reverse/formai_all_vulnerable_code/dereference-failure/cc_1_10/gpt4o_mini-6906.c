//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

void print_memory_usage() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    long totalRam = memInfo.totalram;
    long freeRam = memInfo.freeram;
    long usedRam = totalRam - freeRam;
    long totalSwap = memInfo.totalswap;
    long freeSwap = memInfo.freeswap;

    // Convert to MB for easier readability
    totalRam /= (1024 * 1024);
    freeRam /= (1024 * 1024);
    usedRam /= (1024 * 1024);
    totalSwap /= (1024 * 1024);
    freeSwap /= (1024 * 1024);

    printf("Total RAM: %ld MB\n", totalRam);
    printf("Used RAM: %ld MB\n", usedRam);
    printf("Free RAM: %ld MB\n", freeRam);
    printf("Total Swap: %ld MB\n", totalSwap);
    printf("Free Swap: %ld MB\n", freeSwap);
}

void monitor_memory_usage(int duration) {
    printf("Monitoring RAM usage for %d seconds...\n", duration);
    for (int i = 0; i < duration; i++) {
        printf("\rTime: %d seconds elapsed... ", i + 1);
        print_memory_usage();
        sleep(1);
    }
    printf("\nMonitoring completed.\n");
}

void memory_usage_statistics() {
    printf("\nMemory Usage Statistics:\n");
    // For a more complex system, you might add graphs or historical tracking logic here.
    // However, since this is a simple introspective program, we will stay basic.

    // Just a simple reminder of importance
    printf("Keep an eye on memory usage to ensure your applications run smoothly.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <duration_in_seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int duration = atoi(argv[1]);
    if (duration <= 0) {
        fprintf(stderr, "Duration must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    monitor_memory_usage(duration);
    memory_usage_statistics();

    return EXIT_SUCCESS;
}