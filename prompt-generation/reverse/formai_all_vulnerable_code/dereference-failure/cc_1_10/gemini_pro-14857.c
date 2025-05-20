//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    uint32_t steps;
    uint32_t distance;
    uint32_t calories;
    uint32_t heart_rate;
} activity_data_t;

typedef struct {
    char *name;
    uint32_t age;
    uint32_t height;
    uint32_t weight;
    activity_data_t activity_data;
} user_data_t;

user_data_t *create_user(char *name, uint32_t age, uint32_t height, uint32_t weight) {
    user_data_t *user = malloc(sizeof(user_data_t));
    user->name = strdup(name);
    user->age = age;
    user->height = height;
    user->weight = weight;
    user->activity_data.steps = 0;
    user->activity_data.distance = 0;
    user->activity_data.calories = 0;
    user->activity_data.heart_rate = 0;
    return user;
}

void free_user(user_data_t *user) {
    free(user->name);
    free(user);
}

void update_activity_data(user_data_t *user, uint32_t steps, uint32_t distance, uint32_t calories, uint32_t heart_rate) {
    user->activity_data.steps += steps;
    user->activity_data.distance += distance;
    user->activity_data.calories += calories;
    user->activity_data.heart_rate += heart_rate;
}

void print_user_data(user_data_t *user) {
    printf("Name: %s\n", user->name);
    printf("Age: %u\n", user->age);
    printf("Height: %u\n", user->height);
    printf("Weight: %u\n", user->weight);
    printf("Steps: %u\n", user->activity_data.steps);
    printf("Distance: %u\n", user->activity_data.distance);
    printf("Calories: %u\n", user->activity_data.calories);
    printf("Heart Rate: %u\n", user->activity_data.heart_rate);
}

int main() {
    user_data_t *user = create_user("John Doe", 30, 180, 80);

    // Simulate some activity
    update_activity_data(user, 10000, 5000, 500, 100);

    // Print the user data
    print_user_data(user);

    // Free the user data
    free_user(user);

    return 0;
}