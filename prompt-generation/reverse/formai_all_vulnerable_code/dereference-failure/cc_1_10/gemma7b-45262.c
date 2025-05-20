//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAG_NUMBER 10
#define MAX_BAG_WEIGHT 50

typedef struct baggage_node {
    char *name;
    int weight;
    struct baggage_node *next;
} baggage_node;

baggage_node *create_baggage_node(char *name, int weight) {
    baggage_node *new_node = (baggage_node *)malloc(sizeof(baggage_node));
    new_node->name = name;
    new_node->weight = weight;
    new_node->next = NULL;
    return new_node;
}

void print_baggage_list(baggage_node *head) {
    while (head) {
        printf("%s (%.2f kg)\n", head->name, head->weight);
        head = head->next;
    }
}

void simulate_baggage_handling() {
    // Create a baggage list
    baggage_node *head = create_baggage_node("John Doe's suitcase", 25);
    head = create_baggage_node("Mary Smith's backpack", 12);
    head = create_baggage_node("Peter Jones's trolley", 38);

    // Print the baggage list
    print_baggage_list(head);

    // Randomly select a bag
    srand(time(NULL));
    int random_bag_index = rand() % MAX_BAG_NUMBER;

    // Get the weight of the selected bag
    int bag_weight = head->weight;

    // Simulate weighing the bag
    printf("The weight of the selected bag is: %.2f kg\n", bag_weight);

    // Check if the bag weight exceeds the allowed limit
    if (bag_weight > MAX_BAG_WEIGHT) {
        printf("The bag weight exceeds the allowed limit.\n");
    } else {
        printf("The bag weight is within the allowed limit.\n");
    }
}

int main() {
    simulate_baggage_handling();
    return 0;
}