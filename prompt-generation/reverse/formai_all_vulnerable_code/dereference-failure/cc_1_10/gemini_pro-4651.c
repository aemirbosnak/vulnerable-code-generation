//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STEPS 100000
#define MAX_HEARTRATE 220

typedef struct {
    int steps;
    int heartrate;
    time_t timestamp;
} fitness_data_t;

fitness_data_t *fitness_data;
int fitness_data_count = 0;

void add_fitness_data(int steps, int heartrate) {
    if (fitness_data_count >= MAX_STEPS) {
        printf("Error: Fitness data buffer is full.\n");
        return;
    }

    fitness_data[fitness_data_count].steps = steps;
    fitness_data[fitness_data_count].heartrate = heartrate;
    fitness_data[fitness_data_count].timestamp = time(NULL);

    fitness_data_count++;
}

void print_fitness_data() {
    for (int i = 0; i < fitness_data_count; i++) {
        printf("Steps: %d\n", fitness_data[i].steps);
        printf("Heartrate: %d bpm\n", fitness_data[i].heartrate);
        printf("Timestamp: %s\n", ctime(&fitness_data[i].timestamp));
    }
}

int main() {
    // Initialize fitness data buffer
    fitness_data = malloc(sizeof(fitness_data_t) * MAX_STEPS);

    // Add some fitness data
    add_fitness_data(5000, 120);
    add_fitness_data(7500, 135);
    add_fitness_data(10000, 150);

    // Print fitness data
    print_fitness_data();

    // Free fitness data buffer
    free(fitness_data);

    return 0;
}