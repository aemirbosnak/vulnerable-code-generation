//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define a structure to store baggage information
    typedef struct Baggage
    {
        char *name;
        int weight;
        struct Baggage *next;
    } Baggage;

    // Create a linked list of baggage
    Baggage *head = NULL;

    // Simulate baggage check-in
    printf("Please enter the name of your baggage:");
    char *name = malloc(20);
    scanf("%s", name);

    printf("Please enter the weight of your baggage (in kg):");
    int weight = 0;
    scanf("%d", &weight);

    // Create a new baggage node
    Baggage *new_baggage = malloc(sizeof(Baggage));
    new_baggage->name = name;
    new_baggage->weight = weight;
    new_baggage->next = NULL;

    // If the linked list is empty, make the new node the head
    if (head == NULL)
    {
        head = new_baggage;
    }
    // Otherwise, add the new node to the tail
    else
    {
        head->next = new_baggage;
        head = new_baggage;
    }

    // Simulate baggage handling
    printf("Your baggage has been checked in. Here is your baggage tag:");
    printf("%p", head);

    // Calculate the total weight of the baggage
    int total_weight = 0;
    for (Baggage *current = head; current; current = current->next)
    {
        total_weight += current->weight;
    }

    // Print the total weight of the baggage
    printf("The total weight of your baggage is: %d kg", total_weight);

    // Free the memory allocated for the baggage
    free(name);
    free(new_baggage);

    return 0;
}