//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to schedule processes
int schedule_processes(int num_processes, int* process_arrivals, int* process_priorities) {
    int* process_queue = (int*) malloc(num_processes * sizeof(int));
    int* process_lengths = (int*) malloc(num_processes * sizeof(int));
    int i, j;
    int max_priority = process_priorities[0];
    int min_arrival = process_arrivals[0];

    // Initialize the process queue and lengths
    for (i = 0; i < num_processes; i++) {
        process_queue[i] = process_arrivals[i];
        process_lengths[i] = process_priorities[i];
    }

    // Sort the process queue based on arrival time and length
    for (i = 0; i < num_processes - 1; i++) {
        for (j = i + 1; j < num_processes; j++) {
            if (process_queue[i] > process_queue[j]) {
                int temp = process_queue[i];
                process_queue[i] = process_queue[j];
                process_queue[j] = temp;

                temp = process_lengths[i];
                process_lengths[i] = process_lengths[j];
                process_lengths[j] = temp;
            }
        }
    }

    // Start scheduling processes
    for (i = 0; i < num_processes; i++) {
        int curr_process = process_queue[i];
        int curr_length = process_lengths[i];

        // Process is ready to start
        if (curr_process <= curr_length) {
            // Process is scheduled
            printf("Process %d started at time %d with length %d\n", i + 1, curr_process, curr_length);

            // Remove process from queue and update process lengths
            for (j = i; j < num_processes; j++) {
                process_queue[j - 1] = process_queue[j];
                process_lengths[j - 1] = process_lengths[j];
            }

            num_processes--;

            // Check if there are more processes to schedule
            if (num_processes > 0) {
                max_priority = process_priorities[num_processes];
                min_arrival = process_arrivals[num_processes];
            }
        } else {
            // Process is waiting
            printf("Process %d waiting with priority %d and length %d\n", i + 1, process_priorities[i], process_lengths[i]);
        }
    }

    free(process_queue);
    free(process_lengths);

    return 0;
}

int main() {
    int num_processes = 5;
    int process_arrivals[] = {10, 12, 14, 16, 18};
    int process_priorities[] = {1, 2, 3, 4, 5};

    schedule_processes(num_processes, process_arrivals, process_priorities);

    return 0;
}