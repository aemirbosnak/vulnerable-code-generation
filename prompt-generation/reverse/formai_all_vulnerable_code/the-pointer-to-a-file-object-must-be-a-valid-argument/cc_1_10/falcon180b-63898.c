//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PROC_SELF_STAT "/proc/self/stat"
#define PROC_SELF_STATM "/proc/self/statm"
#define PROC_SELF_STATS "/proc/self/stats"
#define PROC_SELF_STATS_FILE "/proc/self/task/self/stats"

// Function to read the value of a given line from a file
int read_value(char* filename, int line, int* value) {
    FILE* fp = fopen(filename, "r");
    char line_buffer[1024];
    int i = 0;

    while (fgets(line_buffer, sizeof(line_buffer), fp)!= NULL) {
        i++;

        if (i == line) {
            sscanf(line_buffer, "%d", value);
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return -1;
}

// Function to calculate the CPU usage percentage
int calculate_cpu_usage(int total_time, int idle_time) {
    float cpu_usage = ((total_time - idle_time) * 100.0) / total_time;
    return (int)cpu_usage;
}

int main() {
    int total_time, idle_time, cpu_usage;

    // Read the total time and idle time from the /proc/stat file
    read_value(PROC_SELF_STAT, 22, &total_time);
    read_value(PROC_SELF_STAT, 23, &idle_time);

    // Calculate the CPU usage percentage
    cpu_usage = calculate_cpu_usage(total_time, idle_time);

    // Print the CPU usage percentage
    printf("CPU Usage: %d%%\n", cpu_usage);

    return 0;
}