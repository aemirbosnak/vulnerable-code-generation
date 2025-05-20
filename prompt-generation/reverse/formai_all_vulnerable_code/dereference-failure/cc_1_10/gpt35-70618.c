//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE* cpu_file;
    char cpu_line[MAX_LINE_LENGTH];
    double prev_idle = 0, prev_total = 0;
    double idle, total, cpu_usage;

    while (1) {
        // Open /proc/stat file for reading CPU metrics
        cpu_file = fopen("/proc/stat", "r");
        if (!cpu_file) {
            printf("Unable to open /proc/stat file.");
            exit(1);
        }

        // Read first line for total CPU usage metrics
        fgets(cpu_line, MAX_LINE_LENGTH, cpu_file);
        fclose(cpu_file);

        // Extract CPU metrics
        char* token = strtok(cpu_line + 5, " "); // Skip "cpu " at the beginning
        total = 0;
        for (int i = 0; i < 10; i++) {
            if (token == NULL) {
                break;
            }
            total += atoi(token);
            token = strtok(NULL, " ");
        }
        idle = atoi(token);

        // Calculate CPU usage
        if (prev_idle == 0 && prev_total == 0) {
            // First iteration - ignore results
            prev_idle = idle;
            prev_total = total;
        } else {
            // Subsequent iterations - calculate usage percentage
            double diff_total = total - prev_total;
            double diff_idle = idle - prev_idle;
            cpu_usage = 100 * (1 - (diff_idle / diff_total));
            printf("CPU usage: %.2f%%\n", cpu_usage);
            prev_idle = idle;
            prev_total = total;
        }

        // Wait for 1 second
        sleep(1);
    }

    return 0;
}