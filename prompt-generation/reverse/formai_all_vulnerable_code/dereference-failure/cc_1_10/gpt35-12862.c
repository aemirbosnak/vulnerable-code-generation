//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>       // for printf
#include <fcntl.h>       // for open
#include <unistd.h>      // for close
#include <stdlib.h>      // for atoi
#include <string.h>      // for strlen, memset

#define STAT_PATH "/proc/stat"  // Path to the system statistics file

// Struct to store CPU statistics
typedef struct cpu_stats {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
} cpu_stats_t;

// Function to parse CPU statistics from a line in the system statistics file
void parse_cpu_stats(char* line, cpu_stats_t* stats) {
    sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu",
        &stats->user, &stats->nice, &stats->system, &stats->idle,
        &stats->iowait, &stats->irq, &stats->softirq, &stats->steal);
}

// Function to get the current CPU statistics
void get_cpu_stats(cpu_stats_t* stats) {
    int fd = open(STAT_PATH, O_RDONLY);   // Open the system statistics file
    char buffer[1024];                    // Buffer to read the file into
    read(fd, buffer, sizeof(buffer));     // Read the file into the buffer
    close(fd);                            // Close the file

    char* line = strtok(buffer, "\n");    // Tokenize the buffer into lines
    parse_cpu_stats(line, stats);         // Parse the first line as the total CPU statistics
}

// Function to calculate the CPU usage percentage
float calculate_cpu_usage(cpu_stats_t* stats1, cpu_stats_t* stats2) {
    unsigned long long total1, total2, idle1, idle2;
    total1 = stats1->user + stats1->nice + stats1->system + stats1->idle
           + stats1->iowait + stats1->irq + stats1->softirq + stats1->steal;
    total2 = stats2->user + stats2->nice + stats2->system + stats2->idle
           + stats2->iowait + stats2->irq + stats2->softirq + stats2->steal;
    idle1 = stats1->idle;
    idle2 = stats2->idle;
    float usage = (float)(total2 - total1 - (idle2 - idle1)) / (float)(total2 - total1) * 100.0f;
    return usage;
}

int main(int argc, char** argv) {
    cpu_stats_t stats1, stats2;           // Variables to store two sets of CPU statistics
    memset(&stats1, 0, sizeof(cpu_stats_t));
    memset(&stats2, 0, sizeof(cpu_stats_t));

    int interval = 1;                     // Sampling interval in seconds
    if (argc > 1) interval = atoi(argv[1]);

    while (1) {
        get_cpu_stats(&stats1);           // Get the first set of CPU statistics
        sleep(interval);                 // Sleep for the specified interval
        get_cpu_stats(&stats2);           // Get the second set of CPU statistics
        float usage = calculate_cpu_usage(&stats1, &stats2);  // Calculate the CPU usage percentage
        printf("CPU usage: %.2f%%\n", usage);                // Print the usage percentage
    }

    return 0;
}