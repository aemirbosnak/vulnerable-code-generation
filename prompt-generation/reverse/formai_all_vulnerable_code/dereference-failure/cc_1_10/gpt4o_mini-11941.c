//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void get_cpu_usage(double *cpu_usage) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    unsigned long long total_user, total_user_nice, total_system, total_idle, total_iowait, total_steal;
    unsigned long long total;
    
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Unable to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, BUFFER_SIZE, fp);
    sscanf(buffer, "cpu  %llu %llu %llu %llu %llu %llu %llu",
        &total_user, &total_user_nice, &total_system, 
        &total_idle, &total_iowait, &total_steal);

    total = total_user + total_user_nice + total_system + total_idle + total_iowait + total_steal;

    unsigned long long idle = total_idle + total_iowait;
    *cpu_usage = 100.0 * (1 - (double) idle / total);
    
    fclose(fp);
}

void display_usage(double cpu_usage) {
    printf("\rCPU Usage: %.2f%%", cpu_usage);
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    int delay = 1;

    // Process command line arguments
    if (argc > 1) {
        delay = atoi(argv[1]);
        if (delay <= 0) {
            fprintf(stderr, "Delay must be a positive integer!\n");
            return EXIT_FAILURE;
        }
    }

    printf("Starting CPU Usage Monitor... (Refresh every %d seconds)\n", delay);
    
    while (1) {
        double cpu_usage;
        get_cpu_usage(&cpu_usage);
        display_usage(cpu_usage);
        sleep(delay);
    }

    return 0;
}