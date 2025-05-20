//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 10
#define MAX_BAG_WEIGHT 20

typedef struct baggage {
    char name[50];
    int weight;
    struct baggage* next;
} baggage;

baggage* create_baggage(char* name, int weight) {
    baggage* new_baggage = (baggage*)malloc(sizeof(baggage));
    strcpy(new_baggage->name, name);
    new_baggage->weight = weight;
    new_baggage->next = NULL;
    return new_baggage;
}

void add_baggage(baggage* head, char* name, int weight) {
    baggage* new_baggage = create_baggage(name, weight);
    if (head == NULL) {
        head = new_baggage;
    } else {
        new_baggage->next = head;
        head = new_baggage;
    }
}

int calculate_total_weight(baggage* head) {
    int total_weight = 0;
    while (head) {
        total_weight += head->weight;
        head = head->next;
    }
    return total_weight;
}

void print_baggage(baggage* head) {
    while (head) {
        printf("%s (%.2f kg)\n", head->name, head->weight);
        head = head->next;
    }
}

int main() {
    baggage* baggage_list = NULL;
    add_baggage(baggage_list, "John Doe's suitcase", 15);
    add_baggage(baggage_list, "Jane Doe's backpack", 12);
    add_baggage(baggage_list, "Peter Pan's trolley", 22);

    print_baggage(baggage_list);

    int total_weight = calculate_total_weight(baggage_list);
    printf("Total weight: %.2f kg\n", total_weight);

    return 0;
}