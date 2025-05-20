//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 255

typedef struct _FitnessTracker {
    char name[MAX_CHAR];
    int stepsTaken;
    double distanceTraveled;
    int caloriesBurned;
    struct _FitnessTracker* next;
} FitnessTracker;

int main() {
    FitnessTracker* head = NULL;
    FitnessTracker* current = NULL;

    // Allocate memory for the first node
    head = (FitnessTracker*)malloc(sizeof(FitnessTracker));
    current = head;

    // Set the name, steps taken, distance traveled, and calories burned for the first node
    strcpy(current->name, "John Doe");
    current->stepsTaken = 1000;
    current->distanceTraveled = 5.0;
    current->caloriesBurned = 200;

    // Create a loop to add more nodes to the linked list
    for (int i = 1; i < 5; i++) {
        // Allocate memory for the new node
        FitnessTracker* newNode = (FitnessTracker*)malloc(sizeof(FitnessTracker));

        // Set the name, steps taken, distance traveled, and calories burned for the new node
        strcpy(newNode->name, "Jane Doe");
        newNode->stepsTaken = 1200 + i * 100;
        newNode->distanceTraveled = 6.0 + i * 0.5;
        newNode->caloriesBurned = 250 + i * 20;

        // Link the new node to the current node
        newNode->next = current;

        // Update the current node to the new node
        current = newNode;
    }

    // Print the data of each node in the linked list
    current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Steps Taken: %d\n", current->stepsTaken);
        printf("Distance Traveled: %.2f miles\n", current->distanceTraveled);
        printf("Calories Burned: %d\n", current->caloriesBurned);
        printf("\n");
        current = current->next;
    }

    return 0;
}