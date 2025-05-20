//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 10000
#define MAX_CALORIES 10000
#define MAX_HEART_RATE 200
#define MAX_SLEEP 24

typedef struct {
    int steps;
    float distance;
    int calories;
    int heart_rate;
    int sleep;
} FitnessData;

FitnessData* createFitnessData() {
    FitnessData* data = (FitnessData*)malloc(sizeof(FitnessData));
    data->steps = 0;
    data->distance = 0;
    data->calories = 0;
    data->heart_rate = 0;
    data->sleep = 0;
    return data;
}

void updateFitnessData(FitnessData* data) {
    printf("Please enter your fitness data:\n");
    printf("Steps: ");
    scanf("%d", &data->steps);
    printf("Distance: ");
    scanf("%f", &data->distance);
    printf("Calories: ");
    scanf("%d", &data->calories);
    printf("Heart rate: ");
    scanf("%d", &data->heart_rate);
    printf("Sleep: ");
    scanf("%d", &data->sleep);
}

void printFitnessData(FitnessData* data) {
    printf("Fitness data:\n");
    printf("Steps: %d\n", data->steps);
    printf("Distance: %.2f\n", data->distance);
    printf("Calories burned: %d\n", data->calories);
    printf("Average heart rate: %d\n", data->heart_rate);
    printf("Hours of sleep: %d\n", data->sleep);
}

int main() {
    FitnessData* data = createFitnessData();
    int choice;
    do {
        printf("Fitness Tracker\n");
        printf("1. Enter fitness data\n");
        printf("2. View fitness data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                updateFitnessData(data);
                break;
            case 2:
                printFitnessData(data);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
    free(data);
    return 0;
}