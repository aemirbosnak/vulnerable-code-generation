//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAG_NUMBER 10
#define MAX_BAG_WEIGHT 20

typedef struct Bag
{
    int number;
    int weight;
    char *owner;
} Bag;

void handle_baggage(Bag *bags, int num_bags)
{
    for (int i = 0; i < num_bags; i++)
    {
        printf("Bag %d: Owner: %s, Weight: %d\n", bags[i].number, bags[i].owner, bags[i].weight);
    }
}

int main()
{
    srand(time(NULL));

    // Create an array of bags
    Bag *bags = (Bag *)malloc(MAX_BAG_NUMBER * sizeof(Bag));

    // Initialize the bags
    for (int i = 0; i < MAX_BAG_NUMBER; i++)
    {
        bags[i].number = i + 1;
        bags[i].weight = rand() % MAX_BAG_WEIGHT;
        bags[i].owner = (char *)malloc(20 * sizeof(char));
        strcpy(bags[i].owner, "Person " + i);
    }

    // Handle the baggage
    handle_baggage(bags, MAX_BAG_NUMBER);

    // Free the bags
    for (int i = 0; i < MAX_BAG_NUMBER; i++)
    {
        free(bags[i].owner);
    }

    free(bags);

    return 0;
}