//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

volatile sig_atomic_t keep_running = 1;

void handle_sigint(int sig) {
    keep_running = 0;
}

void display_usage(const char *name) {
    printf("Usage: %s [interval]\n", name);
    printf("Monitor CPU usage every <interval> seconds (default is 1 second).\n");
    printf("Press Ctrl+C to stop.\n");
}

double get_cpu_usage() {
    FILE *fp;
    long unsigned int idle_time, total_time;
    char buffer[128]; 

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to read CPU stats");
        return -1;
    }

    fgets(buffer, sizeof(buffer), fp);
    char *token = strtok(buffer, " ");
    
    // Skip the first token which is 'cpu'
    token = strtok(NULL, " ");  // user
    total_time = atoi(token);
    token = strtok(NULL, " ");  // nice
    total_time += atoi(token);
    token = strtok(NULL, " ");  // system
    total_time += atoi(token);
    token = strtok(NULL, " ");  // idle
    idle_time = atoi(token);
    token = strtok(NULL, " ");  // iowait
    total_time += atoi(token);
    token = strtok(NULL, " ");  // irq
    total_time += atoi(token);
    token = strtok(NULL, " ");  // softirq
    total_time += atoi(token);
    
    fclose(fp);

    double usage = 1.0 - ((double)idle_time / (double)total_time);
    return usage * 100.0; // Convert to percentage
}

int main(int argc, char *argv[]) {
    // Signal handling
    signal(SIGINT, handle_sigint);

    // Determine interval
    int interval = 1;
    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Interval must be a positive integer.\n");
            return EXIT_FAILURE;
        }
    }

    printf("Welcome to the CPU Usage Monitor!\n");
    printf("Monitoring CPU usage every %d second(s)...\n\n", interval);
    printf("Press Ctrl+C to exit.\n");

    while (keep_running) {
        double usage = get_cpu_usage();
        if (usage < 0) {
            return EXIT_FAILURE;
        }
        printf("Current CPU Usage: %.2f%%\n", usage);
        sleep(interval);
    }

    printf("\nCPU Usage Monitor stopped. Goodbye!\n");
    return EXIT_SUCCESS;
}