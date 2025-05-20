//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* InsertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void PrintPrimes(Node* head) {
    Node* current = head;
    while (current) {
        int isPrime = 1;
        for (int i = 2; i * i <= current->data; i++) {
            if (current->data % i == 0) {
                isPrime = 0;
            }
        }

        if (isPrime) {
            printf("%d ", current->data);
        }
        current = current->next;
    }
}

int main() {
    Node* head = InsertAtTail(NULL, 3);
    InsertAtTail(head, 5);
    InsertAtTail(head, 7);
    InsertAtTail(head, 11);
    InsertAtTail(head, 13);

    PrintPrimes(head);

    return 0;
}