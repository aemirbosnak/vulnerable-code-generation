//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Define a structure to store baggage information
    typedef struct Baggage
    {
        char name[50];
        int weight;
        struct Baggage* next;
    } Baggage;

    // Create a linked list of baggage
    Baggage* head = NULL;

    // Simulate baggage check-in
    printf("Welcome to the grand hall of the Medieval Castle Airport!\n");
    printf("Please tell me the name of your baggage:** ");
    scanf("%s", head->name);

    printf("Please enter the weight of your baggage (in kilograms): ");
    scanf("%d", &head->weight);

    // Create a new baggage node
    Baggage* new_baggage = malloc(sizeof(Baggage));

    // Link the new baggage node to the head of the list
    new_baggage->next = head;
    head = new_baggage;

    // Simulate baggage retrieval
    printf("Please tell me the name of your baggage:");
    scanf("%s", new_baggage->name);

    // Search for the baggage and print its weight
    Baggage* current_baggage = head;
    while (current_baggage)
    {
        if (strcmp(current_baggage->name, new_baggage->name) == 0)
        {
            printf("The weight of your baggage is: %d kilograms\n", current_baggage->weight);
            break;
        }
        current_baggage = current_baggage->next;
    }

    // Free the memory allocated for the new baggage node
    free(new_baggage);

    // Thank the traveler
    printf("Thank you for choosing the Medieval Castle Airport!");

    return;
}