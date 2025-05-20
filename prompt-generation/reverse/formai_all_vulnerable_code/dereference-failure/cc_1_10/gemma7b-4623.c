//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 10

typedef struct FitnessTracker
{
    char name[MAX_CHAR];
    int stepsTaken;
    float distanceTraveled;
    int heartRate;
    struct FitnessTracker* next;
} FitnessTracker;

FitnessTracker* insertFitnessTracker(FitnessTracker* head, char* name, int stepsTaken, float distanceTraveled, int heartRate)
{
    FitnessTracker* newFitnessTracker = malloc(sizeof(FitnessTracker));

    strcpy(newFitnessTracker->name, name);
    newFitnessTracker->stepsTaken = stepsTaken;
    newFitnessTracker->distanceTraveled = distanceTraveled;
    newFitnessTracker->heartRate = heartRate;

    if (head == NULL)
    {
        head = newFitnessTracker;
    }
    else
    {
        head->next = newFitnessTracker;
    }

    return head;
}

void printFitnessTracker(FitnessTracker* head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Steps Taken: %d\n", head->stepsTaken);
        printf("Distance Traveled: %.2f miles\n", head->distanceTraveled);
        printf("Heart Rate: %d\n", head->heartRate);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    FitnessTracker* head = NULL;

    insertFitnessTracker(head, "John Doe", 10000, 2.5, 70);
    insertFitnessTracker(head, "Jane Doe", 8000, 2.2, 65);
    insertFitnessTracker(head, "Peter Pan", 12000, 2.8, 80);

    printFitnessTracker(head);

    return 0;
}