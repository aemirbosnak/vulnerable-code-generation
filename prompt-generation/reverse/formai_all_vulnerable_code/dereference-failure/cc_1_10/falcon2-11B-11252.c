//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate CPU scheduling
void scheduleProcess(int numProcesses, int processTimes[], int currentTime) {
    int i, j;
    int nextTime;

    // Initialize current time and process times
    currentTime = 0;
    for (i = 0; i < numProcesses; i++) {
        processTimes[i] = rand() % 100;
    }

    // Simulate CPU scheduling
    while (1) {
        // Get the next process to run
        for (i = 0; i < numProcesses; i++) {
            if (processTimes[i] <= currentTime) {
                break;
            }
        }

        // Update current time
        currentTime += processTimes[i];

        // Run the selected process
        printf("Running process %d with time %d\n", i, processTimes[i]);

        // Update process times
        for (j = i + 1; j < numProcesses; j++) {
            processTimes[j] -= 1;
        }

        // Check if all processes have completed
        if (processTimes[numProcesses - 1] <= 0) {
            break;
        }
    }
}

int main() {
    int numProcesses = 5;
    int processTimes[numProcesses];

    // Simulate CPU scheduling
    scheduleProcess(numProcesses, processTimes, 0);

    return 0;
}