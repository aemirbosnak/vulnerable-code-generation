//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_WEIGHT 20

typedef struct baggage {
    char *name;
    int weight;
    struct baggage *next;
} baggage;

void insert_baggage(baggage **head, char *name, int weight) {
    baggage *new_baggage = malloc(sizeof(baggage));
    new_baggage->name = name;
    new_baggage->weight = weight;
    new_baggage->next = NULL;

    if (*head == NULL) {
        *head = new_baggage;
    } else {
        (*head)->next = new_baggage;
    }
}

void print_baggage(baggage *head) {
    while (head) {
        printf("%s (%.2f kg)\n", head->name, head->weight);
        head = head->next;
    }
}

int main() {
    baggage *head = NULL;

    // Insert some baggage
    insert_baggage(&head, "John Doe's suitcase", 15);
    insert_baggage(&head, "Jane Doe's backpack", 12);
    insert_baggage(&head, "Peter Pan's trunk", 18);

    // Print the baggage
    print_baggage(head);

    // Simulate baggage handling
    time_t t = time(NULL);
    srand(t);

    // Randomly select a bag
    int bag_index = rand() % MAX_BAGS;

    // Weigh the selected bag
    int weight = head->next->weight;

    // Print the weight of the selected bag
    printf("The weight of the selected bag is: %.2f kg\n", weight);

    return 0;
}