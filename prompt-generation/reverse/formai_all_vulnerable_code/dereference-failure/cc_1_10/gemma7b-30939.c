//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

typedef struct Node {
    double value;
    struct Node* next;
} Node;

Node* InsertAtTail(Node* head, double value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

double CalculateVoltage(Node* head) {
    double voltage = 0.0;
    Node* current = head;

    while (current) {
        voltage += current->value;
        current = current->next;
    }

    return voltage;
}

int main() {
    Node* head = NULL;

    InsertAtTail(head, 1.5);
    InsertAtTail(head, 2.0);
    InsertAtTail(head, 2.5);
    InsertAtTail(head, 3.0);

    double voltage = CalculateVoltage(head);

    printf("The total voltage is: %.2f\n", voltage);

    return 0;
}