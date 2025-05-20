//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 10

struct baggage {
    char name[20];
    int weight;
    struct baggage* next;
};

typedef struct baggage baggage;

void insert_bag(baggage**, int);
void print_bags(baggage*);

int main()
{
    baggage* head = NULL;

    // Insert some baggage
    insert_bag(&head, 20);
    insert_bag(&head, 15);
    insert_bag(&head, 30);
    insert_bag(&head, 25);

    // Print all baggage
    print_bags(head);

    return 0;
}

void insert_bag(baggage** head, int weight)
{
    baggage* new_bag = (baggage*)malloc(sizeof(baggage));
    new_bag->weight = weight;

    if (*head == NULL) {
        *head = new_bag;
    } else {
        (*head)->next = new_bag;
        *head = new_bag;
    }
}

void print_bags(baggage* head)
{
    while (head) {
        printf("Name: %s, Weight: %d\n", head->name, head->weight);
        head = head->next;
    }
}