//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

// Function to get the current RAM usage
double getCurrentRAMUsage() {
    FILE *file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmSize:", 7) == 0){
            result = atoi(&line[7]);
            break;
        }
    }

    fclose(file);
    return (double)result / 1024.0;
}

// Function to get the maximum RAM usage
double getMaximumRAMUsage() {
    FILE *file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmPeak:", 7) == 0){
            result = atoi(&line[7]);
            break;
        }
    }

    fclose(file);
    return (double)result / 1024.0;
}

// Main function
int main() {
    double currentRAMUsage = 0.0;
    double maximumRAMUsage = 0.0;
    printf("Monitoring C RAM Usage...\n");

    // Loop to continuously monitor RAM usage every 5 seconds
    while(1) {
        currentRAMUsage = getCurrentRAMUsage();
        maximumRAMUsage = fmax(currentRAMUsage, maximumRAMUsage);
        printf("Current RAM usage: %.2lf MB\n", currentRAMUsage);
        printf("Maximum RAM usage: %.2lf MB\n", maximumRAMUsage);
        sleep(5);
    }

    return 0;
}