//Code Llama-13B DATASET v1.0 Category: RAM usage monitor ; Style: post-apocalyptic
/*
 * RAM Usage Monitor
 * A post-apocalyptic style program to monitor RAM usage
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAM_USAGE_THRESHOLD 75

int main() {
    // Get the total amount of RAM available
    long total_ram = 0;
    FILE *fp = popen("free -m", "r");
    if (fp) {
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, "Mem:")) {
                total_ram = atol(line);
                break;
            }
        }
        pclose(fp);
    }

    // Get the amount of free RAM available
    long free_ram = 0;
    fp = popen("free -m", "r");
    if (fp) {
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, "Mem:")) {
                free_ram = atol(line);
                break;
            }
        }
        pclose(fp);
    }

    // Calculate the percentage of RAM used
    long used_ram = total_ram - free_ram;
    long percent_used = (used_ram / total_ram) * 100;

    // Display the RAM usage information
    printf("Total RAM: %ld MB\n", total_ram);
    printf("Free RAM: %ld MB\n", free_ram);
    printf("Used RAM: %ld MB (%ld%%)\n", used_ram, percent_used);

    // Check if the RAM usage is above the threshold
    if (percent_used >= RAM_USAGE_THRESHOLD) {
        printf("WARNING: RAM usage above %d%%\n", RAM_USAGE_THRESHOLD);
    } else {
        printf("RAM usage below %d%%\n", RAM_USAGE_THRESHOLD);
    }

    return 0;
}