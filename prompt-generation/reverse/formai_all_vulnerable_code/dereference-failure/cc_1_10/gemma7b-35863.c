//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    // Define a struct to store baggage information
    typedef struct baggage
    {
        char* name;
        int weight;
        struct baggage* next;
    } baggage;

    // Create a linked list of baggage
    baggage* head = NULL;

    // Simulate baggage check-in
    printf("Please enter the name of your baggage:");
    char* name = malloc(20);
    scanf("%s", name);

    printf("Please enter the weight of your baggage (in kilograms):");
    int weight = 0;
    scanf("%d", &weight);

    // Create a new baggage node
    baggage* new_baggage = malloc(sizeof(baggage));
    new_baggage->name = name;
    new_baggage->weight = weight;
    new_baggage->next = NULL;

    // Add the new baggage node to the linked list
    if (head == NULL)
    {
        head = new_baggage;
    }
    else
    {
        new_baggage->next = head;
        head = new_baggage;
    }

    // Print the baggage information
    printf("Your baggage information:");
    baggage* current = head;
    while (current)
    {
        printf("Name: %s, Weight: %d\n", current->name, current->weight);
        current = current->next;
    }

    // Free the baggage memory
    free(name);
    free(new_baggage);

    return 0;
}