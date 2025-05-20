//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000 // Maximum number of samples to store

// Struct to hold RAM usage data
typedef struct {
    float usage; // Percentage of RAM usage
    int timestamp; // Timestamp in seconds
} RamUsage;

// Function to get current RAM usage
float getRAMUsage() {
    FILE *file = fopen("/proc/meminfo", "r");
    char line[100];
    float usage = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, "MemTotal")!= NULL) {
            fgets(line, sizeof(line), file); // Skip to next line
            sscanf(line, "%d", &usage);
            break;
        }
    }

    fclose(file);
    return usage;
}

// Function to store RAM usage data
void storeRAMUsage(RamUsage *ramUsage, int index, float usage) {
    ramUsage[index].usage = usage;
    ramUsage[index].timestamp = time(NULL);
}

// Function to print RAM usage data
void printRAMUsage(RamUsage *ramUsage, int size) {
    printf("RAM Usage History:\n");
    for (int i = 0; i < size; i++) {
        printf("%d seconds ago: %.2f%%\n", (int)(difftime(time(NULL), ramUsage[i].timestamp)), ramUsage[i].usage);
    }
}

int main() {
    RamUsage ramUsage[MAX_SIZE];
    int size = 0;

    // Initialize with current RAM usage
    storeRAMUsage(ramUsage, size, getRAMUsage());

    while (1) {
        sleep(5); // Sample every 5 seconds

        // Get current RAM usage
        float currentUsage = getRAMUsage();

        // Store data if there is a significant change in RAM usage
        if (abs(currentUsage - ramUsage[size - 1].usage) > 5) {
            storeRAMUsage(ramUsage, size, currentUsage);
            size++;
        } else if (size >= MAX_SIZE) {
            storeRAMUsage(ramUsage, 0, currentUsage);
            size = 1;
        }
    }

    return 0;
}