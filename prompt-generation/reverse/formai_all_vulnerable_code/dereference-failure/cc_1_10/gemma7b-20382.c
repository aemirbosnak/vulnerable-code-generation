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
    FitnessTracker* newNode = malloc(sizeof(FitnessTracker));
    strcpy(newNode->name, name);
    newNode->stepsTaken = stepsTaken;
    newNode->distanceTraveled = distanceTraveled;
    newNode->heartRate = heartRate;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

void printFitnessTracker(FitnessTracker* head)
{
    FitnessTracker* current = head;
    while (current)
    {
        printf("Name: %s, Steps Taken: %d, Distance Traveled: %.2f km, Heart Rate: %d\n", current->name, current->stepsTaken, current->distanceTraveled, current->heartRate);
        current = current->next;
    }
}

int main()
{
    FitnessTracker* head = NULL;

    insertFitnessTracker(head, "John Doe", 10000, 5.0, 70);
    insertFitnessTracker(head, "Jane Doe", 8000, 4.0, 60);
    insertFitnessTracker(head, "Peter Pan", 12000, 6.0, 80);

    printFitnessTracker(head);

    return 0;
}