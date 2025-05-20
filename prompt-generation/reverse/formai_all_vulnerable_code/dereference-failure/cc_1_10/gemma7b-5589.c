//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be tracked
#define MAX_STEPS 1000

// Define the maximum number of hours that can be tracked
#define MAX_HOURS 24

// Define the maximum number of minutes that can be tracked
#define MAX_MINUTES 60

// Define the data structure to store the fitness data
typedef struct FitnessData {
    int steps;
    int hours;
    int minutes;
    time_t timestamp;
} FitnessData;

// Function to add fitness data to the database
void addFitnessData(FitnessData *data) {
    FILE *file = fopen("fitness_data.txt", "a");
    fprintf(file, "%d, %d, %d, %ld\n", data->steps, data->hours, data->minutes, data->timestamp);
    fclose(file);
}

// Function to get the total number of steps taken
int getTotalSteps(void) {
    int totalSteps = 0;
    FILE *file = fopen("fitness_data.txt", "r");
    char line[1024];
    while (fgets(line, 1024, file) != NULL) {
        char *stepsStr = strchr(line, ",") + 1;
        int steps = atoi(stepsStr);
        totalSteps += steps;
    }
    fclose(file);
    return totalSteps;
}

// Function to get the total number of hours spent exercising
int getTotalHours(void) {
    int totalHours = 0;
    FILE *file = fopen("fitness_data.txt", "r");
    char line[1024];
    while (fgets(line, 1024, file) != NULL) {
        char *hoursStr = strchr(line, ",") + 2;
        int hours = atoi(hoursStr);
        totalHours += hours;
    }
    fclose(file);
    return totalHours;
}

// Function to get the total number of minutes spent exercising
int getTotalMinutes(void) {
    int totalMinutes = 0;
    FILE *file = fopen("fitness_data.txt", "r");
    char line[1024];
    while (fgets(line, 1024, file) != NULL) {
        char *minutesStr = strchr(line, ",") + 3;
        int minutes = atoi(minutesStr);
        totalMinutes += minutes;
    }
    fclose(file);
    return totalMinutes;
}

int main() {
    // Create a fitness data structure
    FitnessData data;

    // Get the current timestamp
    time_t timestamp = time(NULL);

    // Set the fitness data structure
    data.steps = 1000;
    data.hours = 5;
    data.minutes = 30;
    data.timestamp = timestamp;

    // Add the fitness data to the database
    addFitnessData(&data);

    // Get the total number of steps taken
    int totalSteps = getTotalSteps();

    // Get the total number of hours spent exercising
    int totalHours = getTotalHours();

    // Get the total number of minutes spent exercising
    int totalMinutes = getTotalMinutes();

    // Print the total fitness data
    printf("Total steps taken: %d\n", totalSteps);
    printf("Total hours spent exercising: %d\n", totalHours);
    printf("Total minutes spent exercising: %d\n", totalMinutes);

    return 0;
}