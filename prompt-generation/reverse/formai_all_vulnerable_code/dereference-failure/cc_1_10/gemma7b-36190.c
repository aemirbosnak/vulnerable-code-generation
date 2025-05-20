//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return;
}

int convertDecimalToBinary(int decimal) {
    Node* head = NULL;

    while (decimal) {
        int digit = decimal % 2;
        insertAtTail(head, digit);
        decimal /= 2;
    }

    int binary = 0;
    Node* current = head;

    while (current) {
        binary += current->data * pow(2, current->next ? current->next->data : 0);
        current = current->next;
    }

    return binary;
}

int main() {
    int decimal = 13;
    int binary = convertDecimalToBinary(decimal);

    printf("Decimal: %d, Binary: %d", decimal, binary);

    return 0;
}