//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct fitnessTracker {
    char *activityName;
    int duration;
    int caloriesBurned;
};

int main() {
    int numActivities;
    printf("Welcome to Fitness Tracker!\n");
    printf("How many activities did you do today?\n");
    scanf("%d", &numActivities);

    struct fitnessTracker activities[numActivities];

    int totalCaloriesBurned = 0;
    int totalDuration = 0;

    srand(time(NULL));

    for(int i = 0; i < numActivities; i++) {
        printf("What is the name of activity %d?\n", i+1);

        char tempName[50];
        scanf("%s", tempName);

        activities[i].activityName = malloc(sizeof(char) * 50);
        activities[i].activityName = tempName;

        int randDuration = rand() % 61;
        printf("How many minutes did you do this activity? (Random number between 0-60 will be generated)\n", randDuration);
        scanf("%d", &activities[i].duration);
        activities[i].duration = randDuration;

        int randCalories = rand() % 201;
        printf("Approximately how many calories did you burn during this activity? (Random number between 0-200 will be generated)\n", randCalories);
        scanf("%d", &activities[i].caloriesBurned);
        activities[i].caloriesBurned = randCalories;

        totalDuration += activities[i].duration;
        totalCaloriesBurned += activities[i].caloriesBurned;
    }

    printf("\nSummary of Activities\n");
    printf("----------------------\n");

    for(int i = 0; i < numActivities; i++) {
        printf("Activity %d: %s\n", i+1, activities[i].activityName);
        printf("Duration: %d minutes\n", activities[i].duration);
        printf("Calories Burned: %d\n", activities[i].caloriesBurned);
        printf("----------------------\n");
    }

    printf("Total Duration: %d minutes\n", totalDuration);
    printf("Total Calories Burned: %d\n", totalCaloriesBurned);

    return 0;
}