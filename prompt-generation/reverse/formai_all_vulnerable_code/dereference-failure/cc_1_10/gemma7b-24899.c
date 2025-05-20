//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct FitnessTracker {
    char name[MAX_SIZE];
    int age;
    double weight;
    double height;
    double targetHeartRate;
    double currentHeartRate;
    double distanceTraveled;
    double totalCaloriesBurned;
    struct FitnessTracker* next;
} FitnessTracker;

FitnessTracker* insertFitnessTracker(FitnessTracker* head, char* name, int age, double weight, double height, double targetHeartRate, double currentHeartRate, double distanceTraveled, double totalCaloriesBurned) {
    FitnessTracker* newNode = (FitnessTracker*)malloc(sizeof(FitnessTracker));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->weight = weight;
    newNode->height = height;
    newNode->targetHeartRate = targetHeartRate;
    newNode->currentHeartRate = currentHeartRate;
    newNode->distanceTraveled = distanceTraveled;
    newNode->totalCaloriesBurned = totalCaloriesBurned;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void printFitnessTracker(FitnessTracker* head) {
    FitnessTracker* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Weight: %.2lf\n", current->weight);
        printf("Height: %.2lf\n", current->height);
        printf("Target Heart Rate: %.2lf\n", current->targetHeartRate);
        printf("Current Heart Rate: %.2lf\n", current->currentHeartRate);
        printf("Distance Traveled: %.2lf miles\n", current->distanceTraveled);
        printf("Total Calories Burned: %.2lf calories\n", current->totalCaloriesBurned);
        printf("\n");
        current = current->next;
    }
}

int main() {
    FitnessTracker* head = NULL;

    insertFitnessTracker(head, "John Doe", 25, 80.0, 74.0, 160.0, 120.0, 10.0, 600.0);
    insertFitnessTracker(head, "Jane Doe", 30, 60.0, 58.0, 140.0, 90.0, 15.0, 400.0);

    printFitnessTracker(head);

    return 0;
}