//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 256

typedef struct Node {
    char data[HASH_SIZE];
    struct Node* next;
} Node;

Node* hash_insert(Node* head, char* data) {
    int hash = hash_function(data);
    Node* node = malloc(sizeof(Node));
    node->data[0] = data[0];
    node->next = NULL;

    if (head == NULL) {
        head = node;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }

    return head;
}

int hash_function(char* data) {
    int hash = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        hash = (hash * 33) + data[i];
    }

    return hash % HASH_SIZE;
}

int main() {
    Node* head = NULL;
    head = hash_insert(head, "abc");
    head = hash_insert(head, "bcd");
    head = hash_insert(head, "cde");

    Node* current = head;
    while (current) {
        printf("%s ", current->data);
        current = current->next;
    }

    return 0;
}