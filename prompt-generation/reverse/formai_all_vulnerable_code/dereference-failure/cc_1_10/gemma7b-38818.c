//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the baggage handling structure
typedef struct Baggage {
    char *name;
    int weight;
    struct Baggage *next;
} Baggage;

// Function to simulate baggage handling at the airport
void simulate_baggage_handling(Baggage *baggage_list) {
    // Randomly select a baggage
    Baggage *selected_baggage = baggage_list->next;
    int random_number = rand() % baggage_list->next->next->next->weight;

    // Weigh the selected baggage
    printf("Weighing baggage: %s\n", selected_baggage->name);
    printf("Weight: %d kg\n", random_number);

    // Load the selected baggage onto the conveyor belt
    printf("Loading baggage onto the conveyor belt...\n");
    sleep(2);

    // Move the selected baggage to the baggage claim area
    printf("Moving baggage to the baggage claim area...\n");
    sleep(2);

    // Claim the selected baggage
    printf("Claiming baggage: %s\n", selected_baggage->name);
}

int main() {
    // Create a baggage handling list
    Baggage *baggage_list = malloc(sizeof(Baggage));
    baggage_list->name = "John Doe";
    baggage_list->weight = 20;
    baggage_list->next = malloc(sizeof(Baggage));
    baggage_list->next->name = "Jane Doe";
    baggage_list->next->weight = 30;
    baggage_list->next->next = malloc(sizeof(Baggage));
    baggage_list->next->next->name = "Peter Pan";
    baggage_list->next->next->weight = 40;

    // Simulate baggage handling
    simulate_baggage_handling(baggage_list);

    return 0;
}