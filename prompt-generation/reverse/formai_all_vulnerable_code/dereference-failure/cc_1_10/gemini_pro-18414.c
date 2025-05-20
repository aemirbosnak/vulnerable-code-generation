//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[32];
    int age;
    int weight;
    int height;
    int steps;
    int calories;
    int distance;
    int active_minutes;
    int sleep_hours;
} fitness_tracker;

fitness_tracker tracker;

void print_tracker() {
    printf("Name: %s\n", tracker.name);
    printf("Age: %d\n", tracker.age);
    printf("Weight: %d\n", tracker.weight);
    printf("Height: %d\n", tracker.height);
    printf("Steps: %d\n", tracker.steps);
    printf("Calories: %d\n", tracker.calories);
    printf("Distance: %d\n", tracker.distance);
    printf("Active Minutes: %d\n", tracker.active_minutes);
    printf("Sleep Hours: %d\n", tracker.sleep_hours);
}

void update_tracker() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    tracker.steps += rand() % 1000;
    tracker.calories += rand() % 100;
    tracker.distance += rand() % 10;
    tracker.active_minutes += rand() % 60;
    tracker.sleep_hours += rand() % 8;

    if (tm->tm_hour >= 6 && tm->tm_hour < 22) {
        tracker.active_minutes += 30;
    } else {
        tracker.sleep_hours += 2;
    }
}

int main() {
    strcpy(tracker.name, "John Doe");
    tracker.age = 30;
    tracker.weight = 80;
    tracker.height = 180;
    tracker.steps = 0;
    tracker.calories = 0;
    tracker.distance = 0;
    tracker.active_minutes = 0;
    tracker.sleep_hours = 0;

    srand(time(NULL));

    while (1) {
        update_tracker();
        print_tracker();
        sleep(10);
    }

    return 0;
}