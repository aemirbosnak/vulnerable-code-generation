//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double value;
    struct node* next;
} node;

void addNode(node** head, double value) {
    node* newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

void printList(node* head) {
    while (head!= NULL) {
        printf("%f ", head->value);
        head = head->next;
    }
}

void freeList(node** head) {
    node* temp = *head;
    while (temp!= NULL) {
        node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

int main() {
    node* circuit = NULL;
    addNode(&circuit, 1.0);
    addNode(&circuit, 2.0);
    addNode(&circuit, 3.0);

    printf("Original circuit: ");
    printList(circuit);

    node* temp = circuit;
    while (temp!= NULL) {
        temp->value *= 2;
        temp = temp->next;
    }

    printf("\nCircuit with all values doubled: ");
    printList(circuit);

    freeList(&circuit);
    return 0;
}