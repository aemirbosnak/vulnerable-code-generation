//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 20

typedef struct baggage {
    char name[50];
    int weight;
    struct baggage* next;
} baggage_t;

baggage_t* create_baggage(char* name, int weight) {
    baggage_t* new_baggage = malloc(sizeof(baggage_t));
    strcpy(new_baggage->name, name);
    new_baggage->weight = weight;
    new_baggage->next = NULL;
    return new_baggage;
}

void print_baggage(baggage_t* baggage) {
    printf("Name: %s, Weight: %d\n", baggage->name, baggage->weight);
}

int main() {
    baggage_t* baggage_list = NULL;

    // Simulate baggage check-in
    for (int i = 0; i < MAX_BAGS; i++) {
        char name[50];
        int weight;

        printf("Enter baggage name: ");
        scanf("%s", name);

        printf("Enter baggage weight: ");
        scanf("%d", &weight);

        baggage_t* new_baggage = create_baggage(name, weight);
        if (baggage_list == NULL) {
            baggage_list = new_baggage;
        } else {
            new_baggage->next = baggage_list;
            baggage_list = new_baggage;
        }
    }

    // Print baggage list
    printf("Baggage List:\n");
    print_baggage(baggage_list);

    // Randomly select a baggage
    srand(time(NULL));
    int rand_index = rand() % MAX_BAGS;

    // Print selected baggage
    printf("Selected baggage:\n");
    print_baggage(baggage_list->next->next);

    return 0;
}