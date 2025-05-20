//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void printPrimes(Node* head) {
    Node* current = head;
    while (current) {
        int prime = 1;
        for (int i = 2; i <= sqrt(current->data); i++) {
            if (current->data % i == 0) {
                prime = 0;
            }
        }

        if (prime) {
            printf("%d ", current->data);
        }
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    insertAtTail(head, 11);
    insertAtTail(head, 13);
    insertAtTail(head, 17);

    printPrimes(head);

    return 0;
}