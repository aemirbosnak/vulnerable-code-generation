//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int steps;
    int calories;
    int distance;
    int heart_rate;
    time_t timestamp;
} fitness_data;

typedef struct {
    fitness_data *data;
    int size;
    int capacity;
} fitness_tracker;

fitness_tracker *fitness_tracker_create() {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->data = NULL;
    tracker->size = 0;
    tracker->capacity = 0;
    return tracker;
}

void fitness_tracker_destroy(fitness_tracker *tracker) {
    free(tracker->data);
    free(tracker);
}

int fitness_tracker_add_data(fitness_tracker *tracker, fitness_data data) {
    if (tracker->capacity == 0) {
        tracker->capacity = 16;
        tracker->data = malloc(tracker->capacity * sizeof(fitness_data));
    } else if (tracker->size == tracker->capacity) {
        tracker->capacity *= 2;
        tracker->data = realloc(tracker->data, tracker->capacity * sizeof(fitness_data));
    }

    tracker->data[tracker->size++] = data;
    return 0;
}

int fitness_tracker_get_avg_steps(fitness_tracker *tracker) {
    int total_steps = 0;

    for (int i = 0; i < tracker->size; i++) {
        total_steps += tracker->data[i].steps;
    }

    return total_steps / tracker->size;
}

int fitness_tracker_get_max_heart_rate(fitness_tracker *tracker) {
    int max_heart_rate = 0;

    for (int i = 0; i < tracker->size; i++) {
        if (tracker->data[i].heart_rate > max_heart_rate) {
            max_heart_rate = tracker->data[i].heart_rate;
        }
    }

    return max_heart_rate;
}

void fitness_tracker_print_data(fitness_tracker *tracker) {
    printf("Fitness data:\n");
    printf("---------------------------------------------------------------------\n");
    printf("|Timestamp |Steps |Calories |Distance |Heart Rate |\n");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < tracker->size; i++) {
        printf("|%s |%d |%d |%d |%d |\n", ctime(&tracker->data[i].timestamp), tracker->data[i].steps, tracker->data[i].calories, tracker->data[i].distance, tracker->data[i].heart_rate);
    }

    printf("---------------------------------------------------------------------\n");
    printf("Average steps: %d\n", fitness_tracker_get_avg_steps(tracker));
    printf("Max heart rate: %d\n", fitness_tracker_get_max_heart_rate(tracker));
}

int main() {
    fitness_tracker *tracker = fitness_tracker_create();

    fitness_data data1 = {3000, 250, 2000, 120, time(NULL)};
    fitness_data data2 = {4000, 300, 2500, 130, time(NULL)};
    fitness_data data3 = {5000, 350, 3000, 140, time(NULL)};
    fitness_data data4 = {6000, 400, 3500, 150, time(NULL)};
    fitness_data data5 = {7000, 450, 4000, 160, time(NULL)};

    fitness_tracker_add_data(tracker, data1);
    fitness_tracker_add_data(tracker, data2);
    fitness_tracker_add_data(tracker, data3);
    fitness_tracker_add_data(tracker, data4);
    fitness_tracker_add_data(tracker, data5);

    fitness_tracker_print_data(tracker);

    fitness_tracker_destroy(tracker);

    return 0;
}