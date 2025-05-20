//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct node {
    int weight;
    char *destination;
    struct node *next;
};

// Linked list head
struct node *head = NULL;

int main() {
    // Create some bags
    struct node *bag1 = malloc(sizeof(struct node));
    struct node *bag2 = malloc(sizeof(struct node));
    struct node *bag3 = malloc(sizeof(struct node));

    // Initialize the bags
    bag1->weight = 20;
    bag1->destination = "LAX";
    bag2->weight = 10;
    bag2->destination = "JFK";
    bag3->weight = 30;
    bag3->destination = "SFO";

    // Add the bags to the linked list
    if (head == NULL) {
        head = bag1;
    } else {
        struct node *curr = head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = bag1;
    }
    bag1->next = bag2;
    bag2->next = bag3;

    // Process the bags
    struct node *curr = head;
    while (curr!= NULL) {
        printf("Processing bag: %d, %s\n", curr->weight, curr->destination);
        curr = curr->next;
    }

    return 0;
}