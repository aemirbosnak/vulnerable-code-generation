//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>

#define BUF_SIZE 128
#define INTERVAL 1

volatile sig_atomic_t stop;

void handle_sigint(int sig) {
    stop = 1;
}

void *cpu_usage_monitor(void *arg) {
    FILE *fp;
    char line[BUF_SIZE];
    unsigned long long idle, total, prev_total = 0, prev_idle = 0;

    while (!stop) {
        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            fprintf(stderr, "Failed to open /proc/stat\n");
            return NULL;
        }

        if (fgets(line, sizeof(line), fp)) {
            unsigned long long user, nice, system, irq, softirq, steal;
            sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &irq, &softirq, &steal);
            total = user + nice + system + irq + softirq + steal;
            idle = atol(strstr(line, " ") + 1) + atol(strstr(line + strlen("cpu "), " ") + 1) + irq;

            if (prev_total && prev_idle) {
                unsigned long long total_delta = total - prev_total;
                unsigned long long idle_delta = idle - prev_idle;
                double usage = (double)(total_delta - idle_delta) / total_delta * 100.0;

                printf("CPU Usage: %.2f%%\n", usage);
            }

            prev_total = total;
            prev_idle = idle;
        }

        fclose(fp);
        sleep(INTERVAL);
    }

    return NULL;
}

int main() {
    pthread_t monitor_thread;

    // Handle Ctrl+C
    signal(SIGINT, handle_sigint);

    // Create a thread for monitoring CPU usage
    if (pthread_create(&monitor_thread, NULL, cpu_usage_monitor, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Wait for the monitor thread to finish
    pthread_join(monitor_thread, NULL);
    printf("Exiting CPU usage monitor...\n");
    return 0;
}