//Gemma-7B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 256

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Node* head = NULL;
    int key = 13;

    // Generate prime numbers and insert them into the linked list
    for (int i = 3; prime(i); i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    // Find the key in the linked list
    Node* current = head;
    while (current) {
        if (current->data == key) {
            printf("Key found!\n");
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found.\n");
    }

    return 0;
}