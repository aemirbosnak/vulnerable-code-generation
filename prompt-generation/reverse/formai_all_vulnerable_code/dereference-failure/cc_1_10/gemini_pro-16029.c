//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define STEPS_PER_DAY 10000
#define CALORIES_PER_DAY 2000
#define SLEEP_HOURS_PER_DAY 8

typedef struct {
    int steps;
    int calories;
    int sleep_hours;
    char *date;
} fitness_log;

fitness_log *fitness_log_create(char *date) {
    fitness_log *log = malloc(sizeof(fitness_log));
    log->steps = 0;
    log->calories = 0;
    log->sleep_hours = 0;
    log->date = strdup(date);
    return log;
}

void fitness_log_destroy(fitness_log *log) {
    free(log->date);
    free(log);
}

void fitness_log_add_steps(fitness_log *log, int steps) {
    log->steps += steps;
}

void fitness_log_add_calories(fitness_log *log, int calories) {
    log->calories += calories;
}

void fitness_log_add_sleep_hours(fitness_log *log, int sleep_hours) {
    log->sleep_hours += sleep_hours;
}

void fitness_log_print(fitness_log *log) {
    printf("Date: %s\n", log->date);
    printf("Steps: %d\n", log->steps);
    printf("Calories: %d\n", log->calories);
    printf("Sleep Hours: %d\n", log->sleep_hours);
}

int main() {
    // Create a fitness log for today
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char date[11];
    strftime(date, sizeof(date), "%Y-%m-%d", tm);
    fitness_log *log = fitness_log_create(date);

    // Simulate walking 10,000 steps
    for (int i = 0; i < STEPS_PER_DAY; i++) {
        fitness_log_add_steps(log, 1);
    }

    // Simulate eating 2,000 calories
    for (int i = 0; i < CALORIES_PER_DAY; i++) {
        fitness_log_add_calories(log, 1);
    }

    // Simulate sleeping 8 hours
    fitness_log_add_sleep_hours(log, SLEEP_HOURS_PER_DAY);

    // Print the fitness log
    fitness_log_print(log);

    // Destroy the fitness log
    fitness_log_destroy(log);

    return 0;
}