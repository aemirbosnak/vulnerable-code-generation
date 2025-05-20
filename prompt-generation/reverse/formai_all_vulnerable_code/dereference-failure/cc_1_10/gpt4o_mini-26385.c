//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 30
#define DATE_LENGTH 11

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int steps;
    double distance; // in kilometers
    double calories; // in kilocalories
    char date[DATE_LENGTH]; // format YYYY-MM-DD
} Activity;

Activity activityLog[MAX_ENTRIES];
int entryCount = 0;

void addActivity() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Activity log is full! Cannot add more activities.\n");
        return;
    }

    Activity newActivity;
    newActivity.id = entryCount + 1;

    printf("Enter activity name: ");
    scanf("%s", newActivity.name);
    printf("Enter number of steps: ");
    scanf("%d", &newActivity.steps);
    printf("Enter distance covered (in km): ");
    scanf("%lf", &newActivity.distance);
    printf("Enter calories burned: ");
    scanf("%lf", &newActivity.calories);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(newActivity.date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    activityLog[entryCount] = newActivity;
    entryCount++;
    printf("Activity added successfully!\n");
}

void displayActivities() {
    if (entryCount == 0) {
        printf("No activities logged yet.\n");
        return;
    }
    
    printf("\nActivity Log:\n");
    printf("ID\tName\t\tSteps\tDistance (km)\tCalories\tDate\n");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d\t%-15s\t%d\t%.2f\t\t%.2f\t%s\n",
               activityLog[i].id,
               activityLog[i].name,
               activityLog[i].steps,
               activityLog[i].distance,
               activityLog[i].calories,
               activityLog[i].date);
    }
}

void calculateStatistics() {
    if (entryCount == 0) {
        printf("No activities available for statistics.\n");
        return;
    }

    int totalSteps = 0;
    double totalDistance = 0.0;
    double totalCalories = 0.0;

    for (int i = 0; i < entryCount; i++) {
        totalSteps += activityLog[i].steps;
        totalDistance += activityLog[i].distance;
        totalCalories += activityLog[i].calories;
    }

    printf("\nStatistics:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories Burned: %.2f\n", totalCalories);
}

void clearLog() {
    entryCount = 0;
    printf("Activity log cleared!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add Activity\n");
        printf("2. Display Activities\n");
        printf("3. Calculate Statistics\n");
        printf("4. Clear Log\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addActivity();
                break;
            case 2:
                displayActivities();
                break;
            case 3:
                calculateStatistics();
                break;
            case 4:
                clearLog();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}