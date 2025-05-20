//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int age;
    int weight;
    int height;
    int steps;
    int calories;
    int distance;
    int active_minutes;
    int sleep_hours;
    int sleep_quality;
    time_t last_updated;
} fitness_tracker;

fitness_tracker *create_fitness_tracker(int id, char *name, int age, int weight, int height) {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->id = id;
    tracker->name = strdup(name);
    tracker->age = age;
    tracker->weight = weight;
    tracker->height = height;
    tracker->steps = 0;
    tracker->calories = 0;
    tracker->distance = 0;
    tracker->active_minutes = 0;
    tracker->sleep_hours = 0;
    tracker->sleep_quality = 0;
    tracker->last_updated = time(NULL);
    return tracker;
}

void destroy_fitness_tracker(fitness_tracker *tracker) {
    free(tracker->name);
    free(tracker);
}

void update_fitness_tracker(fitness_tracker *tracker, int steps, int calories, int distance, int active_minutes, int sleep_hours, int sleep_quality) {
    tracker->steps += steps;
    tracker->calories += calories;
    tracker->distance += distance;
    tracker->active_minutes += active_minutes;
    tracker->sleep_hours += sleep_hours;
    tracker->sleep_quality += sleep_quality;
    tracker->last_updated = time(NULL);
}

void print_fitness_tracker(fitness_tracker *tracker) {
    printf("ID: %d\n", tracker->id);
    printf("Name: %s\n", tracker->name);
    printf("Age: %d\n", tracker->age);
    printf("Weight: %d\n", tracker->weight);
    printf("Height: %d\n", tracker->height);
    printf("Steps: %d\n", tracker->steps);
    printf("Calories: %d\n", tracker->calories);
    printf("Distance: %d\n", tracker->distance);
    printf("Active Minutes: %d\n", tracker->active_minutes);
    printf("Sleep Hours: %d\n", tracker->sleep_hours);
    printf("Sleep Quality: %d\n", tracker->sleep_quality);
    printf("Last Updated: %s\n", ctime(&tracker->last_updated));
}

int main() {
    fitness_tracker *tracker = create_fitness_tracker(1, "John Doe", 30, 180, 72);
    update_fitness_tracker(tracker, 10000, 500, 5, 60, 8, 3);
    print_fitness_tracker(tracker);
    destroy_fitness_tracker(tracker);
    return 0;
}