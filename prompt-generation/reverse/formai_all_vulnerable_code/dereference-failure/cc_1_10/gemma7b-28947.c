//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define baggage handling structure
    typedef struct baggage
    {
        char* name;
        int weight;
        struct baggage* next;
    } baggage;

    // Create a baggage queue
    baggage* head = NULL;

    // Simulate passenger arrival
    printf("Passenger arrives at the baggage drop-off.");
    printf("\n");

    // Get the passenger's name and baggage weight
    char* name = malloc(20);
    printf("Enter your name: ");
    scanf("%s", name);

    int weight = 0;
    printf("Enter your baggage weight (in kg): ");
    scanf("%d", &weight);

    // Create a new baggage node
    baggage* new_baggage = malloc(sizeof(baggage));
    new_baggage->name = name;
    new_baggage->weight = weight;
    new_baggage->next = NULL;

    // Insert the new baggage node into the queue
    if (head == NULL)
    {
        head = new_baggage;
    }
    else
    {
        head->next = new_baggage;
        head = new_baggage;
    }

    // Simulate baggage weighing and tagging
    printf("Baggage is weighed and tagged.");
    printf("\n");

    // Calculate the total weight of the baggage
    int total_weight = 0;
    for (baggage* current = head; current; current = current->next)
    {
        total_weight += current->weight;
    }

    // Print the total weight of the baggage
    printf("Total weight of baggage: %d kg", total_weight);
    printf("\n");

    // Simulate baggage loading onto the plane
    printf("Baggage is loaded onto the plane.");
    printf("\n");

    // Free the memory allocated for the baggage
    free(name);
    free(new_baggage);

    return 0;
}