//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store fitness tracker data
typedef struct FitnessTrackerData
{
    int stepsTaken;
    int caloriesBurned;
    int minutesSpent;
    struct FitnessTrackerData* next;
} FitnessTrackerData;

// Function to add a new node to the fitness tracker linked list
void addNewNode(FitnessTrackerData** head, int stepsTaken, int caloriesBurned, int minutesSpent)
{
    FitnessTrackerData* newNode = (FitnessTrackerData*)malloc(sizeof(FitnessTrackerData));
    newNode->stepsTaken = stepsTaken;
    newNode->caloriesBurned = caloriesBurned;
    newNode->minutesSpent = minutesSpent;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

// Function to display the fitness tracker data
void displayFitnessTrackerData(FitnessTrackerData* head)
{
    while (head)
    {
        printf("Steps taken: %d\n", head->stepsTaken);
        printf("Calories burned: %d\n", head->caloriesBurned);
        printf("Minutes spent: %d\n", head->minutesSpent);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    FitnessTrackerData* head = NULL;

    // Add some sample data
    addNewNode(&head, 1000, 500, 20);
    addNewNode(&head, 1500, 600, 30);
    addNewNode(&head, 2000, 700, 40);

    // Display the fitness tracker data
    displayFitnessTrackerData(head);

    return 0;
}