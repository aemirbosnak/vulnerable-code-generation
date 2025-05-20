//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Define a structure to store baggage information
    struct baggage
    {
        char name[20];
        int weight;
        struct baggage* next;
    };

    // Create a linked list to store baggage information
    struct baggage* head = NULL;

    // Simulate baggage check-in
    printf("Enter the name of your baggage:");
    scanf("%s", head->name);

    printf("Enter the weight of your baggage:");
    scanf("%d", &head->weight);

    // Insert the baggage into the linked list
    head = (struct baggage*)malloc(sizeof(struct baggage));
    head->next = NULL;

    // Repeat the process for the remaining baggage
    int num_bags = 1;
    while (num_bags < 3)
    {
        printf("Enter the name of your baggage:");
        scanf("%s", head->next->name);

        printf("Enter the weight of your baggage:");
        scanf("%d", &head->next->weight);

        // Insert the baggage into the linked list
        head->next = (struct baggage*)malloc(sizeof(struct baggage));
        head->next->next = NULL;

        num_bags++;
    }

    // Print the baggage information
    struct baggage* current = head;
    while (current)
    {
        printf("Name: %s, Weight: %d\n", current->name, current->weight);
        current = current->next;
    }

    return 0;
}