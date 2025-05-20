//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>

struct rusage usage;

// Function to get the current CPU usage
double get_cpu_usage() {
    double cpu_usage = 0.0;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        cpu_usage = ((double) usage.ru_utime.tv_sec + (double) usage.ru_utime.tv_usec / 1000000) / (double) (usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000 + usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000);
    }
    return cpu_usage;
}

// Function to print the current CPU usage
void print_cpu_usage() {
    double cpu_usage = get_cpu_usage();
    printf("Current CPU usage: %.2f%%\n", cpu_usage * 100);
}

// Function to print the help message
void print_help() {
    printf("Usage:./cpu_monitor [interval]\n");
    printf("    interval: The time interval in seconds between each CPU usage check (default is 1 second)\n");
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments are provided
    if (argc < 2) {
        print_help();
        return 1;
    }

    // Set the time interval
    int interval = 1;
    if (argc > 2) {
        interval = atoi(argv[2]);
    }

    // Print the initial CPU usage
    print_cpu_usage();

    while (1) {
        // Sleep for the specified interval
        sleep(interval);

        // Print the current CPU usage
        print_cpu_usage();
    }

    return 0;
}