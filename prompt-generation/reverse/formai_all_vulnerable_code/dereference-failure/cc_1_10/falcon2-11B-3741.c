//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char* name;
    int weight;
    struct node* next;
} node;

typedef struct list {
    node* head;
    node* tail;
} list;

int main() {
    list* baggageList = malloc(sizeof(list));
    if (baggageList == NULL) {
        printf("Failed to allocate memory for baggageList\n");
        return 1;
    }

    baggageList->head = NULL;
    baggageList->tail = NULL;

    node* newBaggage = malloc(sizeof(node));
    if (newBaggage == NULL) {
        printf("Failed to allocate memory for newBaggage\n");
        return 1;
    }

    newBaggage->name = "Romeo's";
    newBaggage->weight = 10;
    newBaggage->next = NULL;

    if (baggageList->head == NULL) {
        baggageList->head = newBaggage;
        baggageList->tail = newBaggage;
    } else {
        baggageList->tail->next = newBaggage;
        baggageList->tail = newBaggage;
    }

    node* secondBaggage = malloc(sizeof(node));
    if (secondBaggage == NULL) {
        printf("Failed to allocate memory for secondBaggage\n");
        return 1;
    }

    secondBaggage->name = "Juliet's";
    secondBaggage->weight = 5;
    secondBaggage->next = NULL;

    if (baggageList->head == NULL) {
        baggageList->head = secondBaggage;
        baggageList->tail = secondBaggage;
    } else {
        baggageList->tail->next = secondBaggage;
        baggageList->tail = secondBaggage;
    }

    printf("Baggage List:\n");
    node* current = baggageList->head;
    while (current!= NULL) {
        printf("%s (%d)\n", current->name, current->weight);
        current = current->next;
    }

    return 0;
}