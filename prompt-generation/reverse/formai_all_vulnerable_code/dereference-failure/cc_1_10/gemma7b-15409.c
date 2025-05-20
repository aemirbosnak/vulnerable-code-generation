//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIGITS 64

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next = newNode);
    }
}

int main() {
    Node* head = NULL;
    char input[MAX_DIGITS];
    int i, num, decimal, binary, exp = 0;

    printf("Enter a decimal number: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++) {
        num = input[i] - '0';
        insertAtTail(&head, num);
    }

    while (head) {
        decimal = head->data * pow(2, exp);
        binary = decimal % 2;
        insertAtTail(&head, binary);
        exp++;
    }

    printf("Binary representation:");
    while (head) {
        printf(" %d", head->data);
        head = head->next;
    }

    printf("\n");

    return 0;
}