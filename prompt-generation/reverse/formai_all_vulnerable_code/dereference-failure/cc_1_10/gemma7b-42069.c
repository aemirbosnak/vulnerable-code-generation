//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertNode(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void convertBinary(Node* head) {
    int i = 0;
    int number = 0;
    char binary[MAX_BUFFER_SIZE];

    while (head) {
        int digit = head->data;
        head = head->next;

        binary[i++] = digit + '0';
        number += digit * pow(2, i - 1);
    }

    printf("Number: %d\n", number);
    printf("Binary: ");

    for (i = 0; binary[i] != '\0'; i++) {
        printf("%c ", binary[i]);
    }

    printf("\n");
}

int main() {
    Node* head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 2);
    insertNode(&head, 1);
    insertNode(&head, 0);

    convertBinary(head);

    return 0;
}