//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_WEIGHT 50

typedef struct Bag {
    char name[20];
    int weight;
    struct Bag* next;
} Bag;

void createBag(Bag** head) {
    *head = malloc(sizeof(Bag));
    (*head)->name[0] = '\0';
    (*head)->weight = 0;
    (*head)->next = NULL;
}

void addBag(Bag** head, char* name, int weight) {
    Bag* newBag = malloc(sizeof(Bag));
    newBag->name[0] = '\0';
    newBag->weight = weight;

    if (*head == NULL) {
        *head = newBag;
    } else {
        ((*head)->next = newBag);
        *head = newBag;
    }
}

void handleLuggage(Bag* head) {
    while (head) {
        printf("Bag name: %s, Weight: %d\n", head->name, head->weight);
        head = head->next;
    }
}

int main() {
    Bag* baggage = NULL;

    createBag(&baggage);
    addBag(&baggage, "John Doe's bag", 25);
    addBag(&baggage, "Jane Doe's bag", 30);
    addBag(&baggage, "Peter Pan's bag", 15);

    handleLuggage(baggage);

    return 0;
}