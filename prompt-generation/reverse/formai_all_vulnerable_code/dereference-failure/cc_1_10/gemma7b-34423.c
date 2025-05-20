//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the baggage handling structure
typedef struct baggage {
    char name[50];
    int weight;
    struct baggage* next;
} baggage;

// Function to create a new baggage node
baggage* create_baggage(char* name, int weight) {
    baggage* new_baggage = (baggage*)malloc(sizeof(baggage));
    strcpy(new_baggage->name, name);
    new_baggage->weight = weight;
    new_baggage->next = NULL;
    return new_baggage;
}

// Function to add a baggage node to the end
void add_baggage(baggage* head, char* name, int weight) {
    baggage* new_baggage = create_baggage(name, weight);
    if (head == NULL) {
        head = new_baggage;
    } else {
        head->next = new_baggage;
        head = new_baggage;
    }
}

// Function to simulate baggage handling
void simulate_baggage_handling(baggage* head) {
    time_t start_time = time(NULL);
    printf("Baggage handling simulation started...\n");

    // Randomly select a baggage
    baggage* current_baggage = head;
    srand(start_time);
    int random_index = rand() % head->next->next->next->weight;
    current_baggage = current_baggage->next->next->next->next->next;

    // Weigh the selected baggage
    printf("Weighing baggage: %s\n", current_baggage->name);
    printf("Weight: %d kg\n", current_baggage->weight);

    // Transfer the baggage to the conveyor belt
    printf("Transferring baggage to the conveyor belt...\n");

    // Simulate the conveyor belt movement
    printf("Conveyor belt is moving...\n");
    sleep(2);

    // Claim the baggage
    printf("Claiming baggage: %s\n", current_baggage->name);

    time_t end_time = time(NULL);
    printf("Baggage handling simulation completed in %.2f seconds\n", (double)(end_time - start_time));
}

int main() {
    // Create a baggage handling system
    baggage* head = NULL;
    add_baggage(head, "John Doe's luggage", 20);
    add_baggage(head, "Jane Doe's suitcase", 15);
    add_baggage(head, "Bill Smith's backpack", 10);
    add_baggage(head, "Mary Johnson's handbag", 5);

    // Simulate baggage handling
    simulate_baggage_handling(head);

    return 0;
}