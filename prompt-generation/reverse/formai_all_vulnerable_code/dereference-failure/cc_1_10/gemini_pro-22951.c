//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int steps;
    int distance;
    int calories;
    int duration;
} activity_t;

typedef struct {
    char *name;
    int age;
    int height;
    int weight;
    activity_t *activities;
    int num_activities;
} user_t;

user_t *create_user(char *name, int age, int height, int weight) {
    user_t *user = malloc(sizeof(user_t));
    user->name = strdup(name);
    user->age = age;
    user->height = height;
    user->weight = weight;
    user->activities = NULL;
    user->num_activities = 0;
    return user;
}

void free_user(user_t *user) {
    free(user->name);
    for (int i = 0; i < user->num_activities; i++) {
        free(user->activities[i].name);
    }
    free(user->activities);
    free(user);
}

activity_t *create_activity(char *name, int steps, int distance, int calories, int duration) {
    activity_t *activity = malloc(sizeof(activity_t));
    activity->name = strdup(name);
    activity->steps = steps;
    activity->distance = distance;
    activity->calories = calories;
    activity->duration = duration;
    return activity;
}

void free_activity(activity_t *activity) {
    free(activity->name);
    free(activity);
}

void add_activity(user_t *user, activity_t *activity) {
    user->activities = realloc(user->activities, (user->num_activities + 1) * sizeof(activity_t));
    user->activities[user->num_activities++] = *activity;
}

void print_user(user_t *user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %d\n", user->height);
    printf("Weight: %d\n", user->weight);
    printf("Activities:\n");
    for (int i = 0; i < user->num_activities; i++) {
        printf("  %s: %d steps, %d distance, %d calories, %d duration\n",
            user->activities[i].name, user->activities[i].steps, user->activities[i].distance,
            user->activities[i].calories, user->activities[i].duration);
    }
}

int main() {
    // Create a user
    user_t *user = create_user("John Doe", 30, 180, 80);

    // Add some activities
    add_activity(user, create_activity("Running", 10000, 5, 500, 60));
    add_activity(user, create_activity("Cycling", 20000, 10, 1000, 120));
    add_activity(user, create_activity("Swimming", 5000, 2, 250, 30));

    // Print the user's information
    print_user(user);

    // Free the user's memory
    free_user(user);

    return 0;
}