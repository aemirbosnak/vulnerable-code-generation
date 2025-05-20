//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void printPrimes(Node* head) {
    while (head) {
        int prime = 1;
        for (int i = 2; i * i <= head->data; i++) {
            if (head->data % i == 0) {
                prime = 0;
            }
        }

        if (prime) {
            printf("%d ", head->data);
        }

        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    for (int i = 0; i < MAX; i++) {
        insert(&head, rand() % MAX);
    }

    printPrimes(head);

    return 0;
}