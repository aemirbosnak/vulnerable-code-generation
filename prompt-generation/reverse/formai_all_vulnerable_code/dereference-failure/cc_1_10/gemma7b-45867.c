//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a baggage handling system
    int baggage_number = 0;
    char **baggage_list = NULL;

    // Simulate baggage check-in
    printf("Please enter the number of bags you have: ");
    int num_bags = 0;
    scanf("%d", &num_bags);

    // Allocate memory for baggage list
    baggage_list = (char**)malloc(num_bags * sizeof(char*));

    // Get baggage details
    for (int i = 0; i < num_bags; i++)
    {
        printf("Enter the name of your baggage: ");
        baggage_list[i] = (char*)malloc(20 * sizeof(char));
        scanf("%s", baggage_list[i]);
    }

    // Check for overweight baggage
    for (int i = 0; i < num_bags; i++)
    {
        printf("Enter the weight of your baggage (in kg): ");
        int weight = 0;
        scanf("%d", &weight);

        if (weight > 20)
        {
            printf("Your baggage is overweight! Please reduce the weight or pay an overweight fee.\n");
        }
    }

    // Print baggage list
    printf("Your baggage list:\n");
    for (int i = 0; i < num_bags; i++)
    {
        printf("Baggage name: %s\n", baggage_list[i]);
    }

    // Free memory
    for (int i = 0; i < num_bags; i++)
    {
        free(baggage_list[i]);
    }
    free(baggage_list);

    return 0;
}