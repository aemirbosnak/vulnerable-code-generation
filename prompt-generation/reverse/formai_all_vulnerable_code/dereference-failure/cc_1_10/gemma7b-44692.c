//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store fitness tracker data
typedef struct FitnessTrackerData {
    int stepsTaken;
    int caloriesBurned;
    char activityType;
    struct FitnessTrackerData* next;
} FitnessTrackerData;

// Function to insert a new node into the linked list
void insertNode(FitnessTrackerData* head, int stepsTaken, int caloriesBurned, char activityType) {
    FitnessTrackerData* newNode = (FitnessTrackerData*)malloc(sizeof(FitnessTrackerData));
    newNode->stepsTaken = stepsTaken;
    newNode->caloriesBurned = caloriesBurned;
    newNode->activityType = activityType;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Function to print the fitness tracker data
void printData(FitnessTrackerData* head) {
    while (head) {
        printf("Steps taken: %d\n", head->stepsTaken);
        printf("Calories burned: %d\n", head->caloriesBurned);
        printf("Activity type: %c\n", head->activityType);
        printf("\n");
        head = head->next;
    }
}

int main() {
    // Create a new fitness tracker data structure
    FitnessTrackerData* head = NULL;

    // Insert some data into the fitness tracker
    insertNode(head, 1000, 500, 'A');
    insertNode(head, 1500, 600, 'B');
    insertNode(head, 2000, 700, 'C');

    // Print the fitness tracker data
    printData(head);

    return 0;
}