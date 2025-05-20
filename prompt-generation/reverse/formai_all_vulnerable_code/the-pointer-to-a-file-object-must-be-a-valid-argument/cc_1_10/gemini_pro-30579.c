//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// Define the refresh rate in seconds
#define REFRESH_RATE 1

// Define the maximum number of CPU cores
#define MAX_CPU_CORES 8

// Define the colors for the output
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_MAGENTA "\033[0;35m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_WHITE "\033[0;37m"
#define COLOR_RESET "\033[0;0m"

// Define the symbols for the output
#define SYMBOL_UP "\u25B2"
#define SYMBOL_DOWN "\u25BC"
#define SYMBOL_EQUAL "\u25C0"

// Get the CPU usage
double get_cpu_usage() {
    // Get the current time
    struct timeval start;
    gettimeofday(&start, NULL);

    // Get the initial CPU usage
    FILE *file = fopen("/proc/stat", "r");
    char line[1024];
    fgets(line, sizeof(line), file);
    fclose(file);

    // Parse the CPU usage
    char *token = strtok(line, " ");
    double idle_time = 0;
    while (token != NULL) {
        if (strcmp(token, "idle") == 0) {
            idle_time = atof(strtok(NULL, " "));
        }
        token = strtok(NULL, " ");
    }

    // Get the final CPU usage
    gettimeofday(&start, NULL);
    file = fopen("/proc/stat", "r");
    fgets(line, sizeof(line), file);
    fclose(file);

    // Parse the CPU usage
    token = strtok(line, " ");
    double final_idle_time = 0;
    while (token != NULL) {
        if (strcmp(token, "idle") == 0) {
            final_idle_time = atof(strtok(NULL, " "));
        }
        token = strtok(NULL, " ");
    }

    // Calculate the CPU usage
    return (100 * (idle_time - final_idle_time) / (start.tv_sec - start.tv_sec));
}

// Print the CPU usage
void print_cpu_usage(double cpu_usage) {
    // Print the CPU usage bar
    printf("[");
    for (int i = 0; i < (int)cpu_usage; i++) {
        printf("%s%s%s", COLOR_GREEN, SYMBOL_UP, COLOR_RESET);
    }
    for (int i = 0; i < (int)(100 - cpu_usage); i++) {
        printf("%s%s%s", COLOR_RED, SYMBOL_DOWN, COLOR_RESET);
    }
    printf("]");

    // Print the CPU usage percentage
    printf(" %.2f%%", cpu_usage);
}

// Main function
int main() {
    // Get the number of CPU cores
    int num_cpu_cores = sysconf(_SC_NPROCESSORS_CONF);
    if (num_cpu_cores > MAX_CPU_CORES) {
        num_cpu_cores = MAX_CPU_CORES;
    }

    // Create an array to store the CPU usage
    double cpu_usage[num_cpu_cores];

    // Main loop
    while (1) {
        // Get the CPU usage
        for (int i = 0; i < num_cpu_cores; i++) {
            cpu_usage[i] = get_cpu_usage();
        }

        // Print the CPU usage
        for (int i = 0; i < num_cpu_cores; i++) {
            printf("CPU %d: ", i);
            print_cpu_usage(cpu_usage[i]);
            printf("\n");
        }

        // Sleep for the refresh rate
        sleep(REFRESH_RATE);
    }

    return 0;
}