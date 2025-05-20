//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sample size
#define N 1000

// RAM usage in bytes
#define RAM_USAGE_BYTES 1024 * 1024 * 100

// Data structure for RAM usage statistics
typedef struct ram_usage_stats {
    double mean;
    double stddev;
    double min;
    double max;
} ram_usage_stats_t;

// Function to calculate RAM usage statistics
ram_usage_stats_t calculate_ram_usage_stats(double *ram_usage, int n) {
    ram_usage_stats_t stats;

    // Calculate mean
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += ram_usage[i];
    }
    stats.mean = sum / n;

    // Calculate standard deviation
    double sq_diff_sum = 0.0;
    for (int i = 0; i < n; i++) {
        sq_diff_sum += pow(ram_usage[i] - stats.mean, 2);
    }
    stats.stddev = sqrt(sq_diff_sum / (n - 1));

    // Calculate min and max
    stats.min = ram_usage[0];
    stats.max = ram_usage[0];
    for (int i = 1; i < n; i++) {
        if (ram_usage[i] < stats.min) {
            stats.min = ram_usage[i];
        }
        if (ram_usage[i] > stats.max) {
            stats.max = ram_usage[i];
        }
    }

    return stats;
}

// Main function
int main() {
    // Initialize RAM usage array
    double *ram_usage = malloc(N * sizeof(double));

    // Generate random RAM usage data
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        ram_usage[i] = (double) rand() / RAND_MAX * RAM_USAGE_BYTES;
    }

    // Calculate RAM usage statistics
    ram_usage_stats_t stats = calculate_ram_usage_stats(ram_usage, N);

    // Print RAM usage statistics
    printf("RAM usage statistics:\n");
    printf("Mean: %.2f bytes\n", stats.mean);
    printf("Standard deviation: %.2f bytes\n", stats.stddev);
    printf("Min: %.2f bytes\n", stats.min);
    printf("Max: %.2f bytes\n", stats.max);

    // Free RAM usage array
    free(ram_usage);

    return 0;
}