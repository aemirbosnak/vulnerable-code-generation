//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct FitnessTracker
{
    char name[MAX_CHAR];
    int stepsTaken;
    int caloriesBurned;
    int heartRate;
    struct FitnessTracker* next;
} FitnessTracker;

void insertFitnessTracker(FitnessTracker** head, char* name, int stepsTaken, int caloriesBurned, int heartRate)
{
    FitnessTracker* newNode = (FitnessTracker*)malloc(sizeof(FitnessTracker));
    strcpy(newNode->name, name);
    newNode->stepsTaken = stepsTaken;
    newNode->caloriesBurned = caloriesBurned;
    newNode->heartRate = heartRate;
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

void displayFitnessTracker(FitnessTracker* head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Steps Taken: %d\n", head->stepsTaken);
        printf("Calories Burned: %d\n", head->caloriesBurned);
        printf("Heart Rate: %d\n", head->heartRate);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    FitnessTracker* head = NULL;

    insertFitnessTracker(&head, "John Doe", 10000, 2000, 70);
    insertFitnessTracker(&head, "Jane Doe", 8000, 1800, 60);
    insertFitnessTracker(&head, "Mike Smith", 9000, 1900, 80);

    displayFitnessTracker(head);

    return 0;
}