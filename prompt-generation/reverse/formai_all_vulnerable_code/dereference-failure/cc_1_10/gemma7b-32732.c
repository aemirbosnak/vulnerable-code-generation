//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 1024

#define HASH_PRIME 311

typedef struct Node {
    char data[HASH_SIZE];
    struct Node* next;
} Node;

void hash_init(Node** head) {
    *head = NULL;
}

int hash_insert(Node** head, char* data) {
    int hash = hash_calc(data);
    Node* newNode = malloc(sizeof(Node));
    newNode->data[0] = data[0];
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    return hash;
}

int hash_calc(char* data) {
    int hash = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        hash += data[i] * HASH_PRIME;
    }
    return hash % HASH_SIZE;
}

int main() {
    Node* head = NULL;
    hash_init(&head);
    hash_insert(&head, "John");
    hash_insert(&head, "Mary");
    hash_insert(&head, "Bob");
    hash_insert(&head, "Alice");

    for (Node* current = head; current; current = current->next) {
        printf("%s\n", current->data);
    }

    return 0;
}