//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: retro
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define baggage handling constants
#define MAX_NUMBER_OF_BAGS 10
#define BAG_WEIGHT_LIMIT 20
#define CHECK_IN_FEE 5

// Define baggage structure
typedef struct Bag {
    char* name;
    int weight;
    struct Bag* next;
} Bag;

// Function to simulate baggage handling
void simulate_baggage_handling(Bag* head) {
    // Randomly select a bag
    Bag* current_bag = head;
    srand(time(NULL));
    int random_index = rand() % MAX_NUMBER_OF_BAGS;
    current_bag = current_bag->next;

    // Check if the selected bag is overweight
    if (current_bag->weight > BAG_WEIGHT_LIMIT) {
        // Charge overweight fee
        current_bag->weight -= BAG_WEIGHT_LIMIT;
        int fee = CHECK_IN_FEE * current_bag->weight;
        printf("Overweight baggage fee: $%d\n", fee);
    }

    // Print baggage information
    printf("Bag name: %s\n", current_bag->name);
    printf("Bag weight: %d\n", current_bag->weight);
    printf("Bag status: Checked In\n");
}

int main() {
    // Create a linked list of bags
    Bag* head = NULL;
    head = malloc(sizeof(Bag));
    head->name = "John Doe's Bag";
    head->weight = 15;
    head->next = malloc(sizeof(Bag));
    head->next->name = "Jane Doe's Bag";
    head->next->weight = 12;

    // Simulate baggage handling
    simulate_baggage_handling(head);

    return 0;
}