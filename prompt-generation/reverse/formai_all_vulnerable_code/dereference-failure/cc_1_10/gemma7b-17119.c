//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a structure to represent a baggage item
    typedef struct BaggageItem
    {
        char* name;
        int weight;
        struct BaggageItem* next;
    } BaggageItem;

    // Create a linked list of baggage items
    BaggageItem* head = NULL;

    // Simulate baggage handling operations
    while (1)
    {
        // Get the item name and weight from the user
        char* name = malloc(20);
        printf("Enter item name: ");
        scanf("%s", name);

        int weight = 0;
        printf("Enter item weight: ");
        scanf("%d", &weight);

        // Create a new baggage item
        BaggageItem* item = malloc(sizeof(BaggageItem));
        item->name = name;
        item->weight = weight;
        item->next = NULL;

        // Insert the item into the linked list
        if (head == NULL)
        {
            head = item;
        }
        else
        {
            item->next = head;
            head = item;
        }

        // Check if the user wants to continue
        char answer;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &answer);

        // Break out of the loop if the user does not want to continue
        if (answer == 'N')
        {
            break;
        }
    }

    // Print the list of baggage items
    printf("List of baggage items:\n");
    for (BaggageItem* item = head; item != NULL; item = item->next)
    {
        printf("%s (%d kg)\n", item->name, item->weight);
    }

    // Free the memory allocated for the baggage items
    for (BaggageItem* item = head; item != NULL; item = item->next)
    {
        free(item->name);
        free(item);
    }

    return 0;
}