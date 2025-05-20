//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to represent a baggage
typedef struct baggage {
    char *name;
    int weight;
    struct baggage *next;
} baggage;

// Function to simulate baggage handling at the airport
void simulate_baggage_handling(baggage *head) {
    // Randomly select a baggage
    baggage *current_baggage = head;
    srand(time(NULL));
    int rand_num = rand() % head->next->next->weight;
    current_baggage = current_baggage->next->next;

    // Weigh the baggage
    printf("Weighing baggage: %s\n", current_baggage->name);
    printf("Weight: %d kg\n", current_baggage->weight);

    // Place the baggage on the conveyor belt
    printf("Placing baggage on the conveyor belt...\n");

    // Simulate the baggage moving on the conveyor belt
    printf("Baggage is moving on the conveyor belt...\n");

    // Collect the baggage
    printf("Collecting baggage...\n");

    // Print a receipt
    printf("Baggage receipt:\n");
    printf("Name: %s\n", current_baggage->name);
    printf("Weight: %d kg\n", current_baggage->weight);
    printf("Fee: $5.00\n");
    printf("Thank you for your baggage, have a pleasant flight!\n");
}

int main() {
    // Create a linked list of baggage
    baggage *head = malloc(sizeof(baggage));
    head->name = "John Doe's baggage";
    head->weight = 25;
    head->next = malloc(sizeof(baggage));
    head->next->name = "Jane Doe's baggage";
    head->next->weight = 30;
    head->next->next = malloc(sizeof(baggage));
    head->next->next->name = "Peter Pan's baggage";
    head->next->next->weight = 40;

    // Simulate baggage handling
    simulate_baggage_handling(head);

    return 0;
}