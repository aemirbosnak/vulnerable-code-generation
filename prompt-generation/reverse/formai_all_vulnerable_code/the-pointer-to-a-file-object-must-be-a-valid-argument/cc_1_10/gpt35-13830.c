//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define NUM_SAMPLES 10

int main() {
    char buf[BUF_SIZE];
    unsigned long long prev_total = 0;
    unsigned long long prev_idle = 0;
    unsigned long long total_jiffies = 0;
    unsigned long long idle_jiffies = 0;
    int num_samples = 0;

    while (1) {
        // Read in the contents of /proc/stat
        FILE* stat_file = fopen("/proc/stat", "r");
        fgets(buf, BUF_SIZE, stat_file);
        fclose(stat_file);

        // Parse the contents of /proc/stat to get the total and idle jiffies
        char* token = strtok(buf, " ");
        token = strtok(NULL, " "); // skip first entry, "cpu"
        total_jiffies = 0;
        for (int i = 0; i < 10; i++) {
            token = strtok(NULL, " ");
            total_jiffies += atoll(token);
            if (i == 3) { // idle jiffies is the 4th entry
                idle_jiffies = atoll(token);
            }
        }

        // Calculate the CPU usage as a percentage
        unsigned long long diff_total = total_jiffies - prev_total;
        unsigned long long diff_idle = idle_jiffies - prev_idle;
        double usage = 100 * (1.0 - ((double) diff_idle / (double) diff_total));

        // Print out the CPU usage
        printf("CPU Usage: %.2f%%\n", usage);

        // Reset the previous values if we're taking a new sample
        num_samples++;
        if (num_samples == NUM_SAMPLES) {
            num_samples = 0;
            prev_total = 0;
            prev_idle = 0;
        }
        prev_total += diff_total;
        prev_idle += diff_idle;
        
        // Sleep for 1 second before checking again
        sleep(1);
    }

    return 0;
}