//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Data structures
typedef struct {
    int steps;
    int calories;
    int distance;
} ActivityData;

typedef struct {
    char *name;
    int age;
    int weight;
    int height;
    ActivityData activityData;
} Profile;

// Function prototypes
Profile *createProfile(char *name, int age, int weight, int height);
void displayProfile(Profile *profile);
void updateActivityData(Profile *profile, int steps, int calories, int distance);
void displayActivityData(Profile *profile);

// Main function
int main() {
    // Create a profile
    Profile *profile = createProfile("John Doe", 30, 75, 180);

    // Display the profile
    displayProfile(profile);

    // Update the activity data
    updateActivityData(profile, 10000, 500, 5);

    // Display the activity data
    displayActivityData(profile);

    // Free the profile
    free(profile);

    return 0;
}

// Function definitions
Profile *createProfile(char *name, int age, int weight, int height) {
    Profile *profile = malloc(sizeof(Profile));
    profile->name = name;
    profile->age = age;
    profile->weight = weight;
    profile->height = height;
    profile->activityData.steps = 0;
    profile->activityData.calories = 0;
    profile->activityData.distance = 0;
    return profile;
}

void displayProfile(Profile *profile) {
    printf("Name: %s\n", profile->name);
    printf("Age: %d\n", profile->age);
    printf("Weight: %d\n", profile->weight);
    printf("Height: %d\n", profile->height);
}

void updateActivityData(Profile *profile, int steps, int calories, int distance) {
    profile->activityData.steps += steps;
    profile->activityData.calories += calories;
    profile->activityData.distance += distance;
}

void displayActivityData(Profile *profile) {
    printf("Steps: %d\n", profile->activityData.steps);
    printf("Calories: %d\n", profile->activityData.calories);
    printf("Distance: %d\n", profile->activityData.distance);
}