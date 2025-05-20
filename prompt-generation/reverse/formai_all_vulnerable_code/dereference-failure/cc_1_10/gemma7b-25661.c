//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct FitnessTracker {
    int stepsTaken;
    int caloriesBurned;
    int heartRate;
    struct FitnessTracker* next;
} FitnessTracker;

FitnessTracker* insertFitnessTracker(FitnessTracker* head, int stepsTaken, int caloriesBurned, int heartRate) {
    FitnessTracker* newNode = (FitnessTracker*)malloc(sizeof(FitnessTracker));
    newNode->stepsTaken = stepsTaken;
    newNode->caloriesBurned = caloriesBurned;
    newNode->heartRate = heartRate;
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
        printf("Steps taken: %d\n", current->stepsTaken);
        printf("Calories burned: %d\n", current->caloriesBurned);
        printf("Heart rate: %d\n", current->heartRate);
        printf("\n");
        current = current->next;
    }
}

int main() {
    FitnessTracker* head = NULL;

    insertFitnessTracker(head, 1000, 2000, 70);
    insertFitnessTracker(head, 1500, 2500, 80);
    insertFitnessTracker(head, 2000, 3000, 90);

    printFitnessTracker(head);

    return 0;
}