//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int convertDecimalToBinary(int decimal) {
    Node* head = NULL;
    int quotient = decimal;
    int remainder;

    while (quotient) {
        remainder = quotient % 2;
        insertAtTail(&head, remainder);
        quotient /= 2;
    }

    int binary = 0;
    Node* current = head;

    while (current) {
        binary = binary * 2 + current->data;
        current = current->next;
    }

    return binary;
}

int main() {
    int decimal = 13;
    int binary = convertDecimalToBinary(decimal);
    printf("Binary: %d", binary);

    return 0;
}