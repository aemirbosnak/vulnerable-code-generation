//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int weight;
    char* destination;
} Bag;

int main() {
    // Create and fill in a bag
    Bag bag1 = {"luggage", 50, "Paris"};
    
    // Print out the bag's information
    printf("Bag 1:\n");
    printf("Name: %s\n", bag1.name);
    printf("Weight: %d\n", bag1.weight);
    printf("Destination: %s\n", bag1.destination);
    printf("\n");
    
    // Create and fill in another bag
    Bag bag2 = {"suitcase", 75, "London"};
    
    // Print out the bag's information
    printf("Bag 2:\n");
    printf("Name: %s\n", bag2.name);
    printf("Weight: %d\n", bag2.weight);
    printf("Destination: %s\n", bag2.destination);
    printf("\n");
    
    // Combine the bags
    Bag combined = {"combined", 125, "London"};
    combined.name = strcat(combined.name, " + ");
    combined.name = strcat(combined.name, bag1.name);
    combined.name = strcat(combined.name, " + ");
    combined.name = strcat(combined.name, bag2.name);
    printf("Combined bag:\n");
    printf("Name: %s\n", combined.name);
    printf("Weight: %d\n", combined.weight);
    printf("Destination: %s\n", combined.destination);
    printf("\n");
    
    // Print out all bags
    printf("All bags:\n");
    printf("Bag 1:\n");
    printf("Name: %s\n", bag1.name);
    printf("Weight: %d\n", bag1.weight);
    printf("Destination: %s\n", bag1.destination);
    printf("\n");
    printf("Bag 2:\n");
    printf("Name: %s\n", bag2.name);
    printf("Weight: %d\n", bag2.weight);
    printf("Destination: %s\n", bag2.destination);
    printf("\n");
    printf("Combined bag:\n");
    printf("Name: %s\n", combined.name);
    printf("Weight: %d\n", combined.weight);
    printf("Destination: %s\n", combined.destination);
    printf("\n");
    
    return 0;
}