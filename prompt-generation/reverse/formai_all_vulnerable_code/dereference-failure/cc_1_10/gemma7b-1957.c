//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define a list of baggage items
    char** baggage_items = NULL;
    int baggage_item_count = 0;

    // Simulate baggage drop-off
    int passenger_id = rand() % 100;
    char* baggage_item = "Suitcase";
    int baggage_item_weight = rand() % 50;

    // Add the baggage item to the list
    baggage_items = realloc(baggage_items, (baggage_item_count + 1) * sizeof(char*));
    baggage_items[baggage_item_count++] = baggage_item;
    baggage_item_weight += rand() % 10;

    // Weigh the baggage
    int total_weight = 0;
    for (int i = 0; i < baggage_item_count; i++)
    {
        total_weight += baggage_items[i] == "Suitcase" ? baggage_item_weight : rand() % 20;
    }

    // Check if the baggage is overweight
    if (total_weight > 50)
    {
        // Charge overweight fees
        int fees = total_weight - 50;
        printf("Passenger ID: %d\n", passenger_id);
        printf("Baggage items: ");
        for (int i = 0; i < baggage_item_count; i++)
        {
            printf("%s ", baggage_items[i]);
        }
        printf("\nTotal weight: %d\n", total_weight);
        printf("Overweight fees: %d\n", fees);
    }
    else
    {
        // Check in the passenger
        printf("Passenger ID: %d\n", passenger_id);
        printf("Baggage items: ");
        for (int i = 0; i < baggage_item_count; i++)
        {
            printf("%s ", baggage_items[i]);
        }
        printf("\nTotal weight: %d\n", total_weight);
        printf("Check in complete.\n");
    }

    return 0;
}