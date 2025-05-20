//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct C_Fitness_Tracker {
    char name[MAX_BUFFER_SIZE];
    int age;
    float weight;
    float height;
    float target_heart_rate;
    float current_heart_rate;
    int steps_taken;
    int calories_burned;
    int workout_duration;
    struct C_Fitness_Tracker* next;
} C_Fitness_Tracker;

C_Fitness_Tracker* create_fitness_tracker(char* name, int age, float weight, float height, float target_heart_rate) {
    C_Fitness_Tracker* tracker = (C_Fitness_Tracker*)malloc(sizeof(C_Fitness_Tracker));
    strcpy(tracker->name, name);
    tracker->age = age;
    tracker->weight = weight;
    tracker->height = height;
    tracker->target_heart_rate = target_heart_rate;
    tracker->current_heart_rate = 0;
    tracker->steps_taken = 0;
    tracker->calories_burned = 0;
    tracker->workout_duration = 0;
    tracker->next = NULL;

    return tracker;
}

void update_fitness_tracker(C_Fitness_Tracker* tracker, int steps_taken, int workout_duration) {
    tracker->steps_taken += steps_taken;
    tracker->calories_burned += steps_taken * 2;
    tracker->workout_duration += workout_duration;
}

void display_fitness_tracker(C_Fitness_Tracker* tracker) {
    printf("Name: %s\n", tracker->name);
    printf("Age: %d\n", tracker->age);
    printf("Weight: %.2f kg\n", tracker->weight);
    printf("Height: %.2f m\n", tracker->height);
    printf("Target Heart Rate: %.2f bpm\n", tracker->target_heart_rate);
    printf("Current Heart Rate: %.2f bpm\n", tracker->current_heart_rate);
    printf("Steps Taken: %d\n", tracker->steps_taken);
    printf("Calories Burned: %d\n", tracker->calories_burned);
    printf("Workout Duration: %d minutes\n", tracker->workout_duration);
}

int main() {
    C_Fitness_Tracker* tracker = create_fitness_tracker("John Doe", 25, 80.0, 1.75, 140.0);

    update_fitness_tracker(tracker, 1000, 60);

    display_fitness_tracker(tracker);

    return 0;
}