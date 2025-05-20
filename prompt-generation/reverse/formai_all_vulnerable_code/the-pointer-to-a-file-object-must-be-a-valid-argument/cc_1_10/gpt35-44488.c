//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: inquisitive
#include <stdio.h>
#include <unistd.h>

int main() {
    FILE* file;
    char buffer[256];

    long idle_prev, total_prev, idle, total;
    double cpu_usage;

    // Open the /proc/stat file
    file = fopen("/proc/stat", "r");

    // Read the first line of the file
    fgets(buffer, sizeof(buffer), file);

    // Extract the idle and total CPU time from the first line
    sscanf(buffer, "cpu %ld %ld %*ld %*ld %*ld %*ld %*ld", &idle_prev, &total_prev);

    fclose(file);

    // Loop to monitor the CPU usage every second
    while (1) {
        // Wait for 1 second
        sleep(1);

        // Reopen the /proc/stat file
        file = fopen("/proc/stat", "r");

        // Read the first line of the file
        fgets(buffer, sizeof(buffer), file);

        // Extract the idle and total CPU time from the first line
        sscanf(buffer, "cpu %ld %ld %*ld %*ld %*ld %*ld %*ld", &idle, &total);

        fclose(file);

        // Calculate the CPU usage percentage
        cpu_usage = ((double)(total - total_prev) - (double)(idle - idle_prev)) / (double)(total - total_prev) * 100.0;

        // Update the previous idle and total CPU time values
        idle_prev = idle;
        total_prev = total;

        // Print the CPU usage percentage
        printf("CPU usage: %.2f%%\n", cpu_usage);
    }

    return 0;
}