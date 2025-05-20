//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
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

void printPrimes(Node* head) {
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
    Node* head = insertAtTail(NULL, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    insertAtTail(head, 11);
    insertAtTail(head, 13);

    printPrimes(head);

    return 0;
}