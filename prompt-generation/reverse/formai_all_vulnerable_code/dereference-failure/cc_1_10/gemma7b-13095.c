//Gemma-7B DATASET v1.0 Category: QR code reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_MAX 256
#define HASH_SIZE 10

typedef struct Node {
    struct Node* next;
    int key;
    char data[KEY_MAX];
} Node;

void insert(Node** head, int key, char* data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int search(Node* head, int key) {
    while (head) {
        if (head->key == key) {
            return 1;
        } else if (head->key > key) {
            return 0;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    Node* head = NULL;
    insert(&head, 1, "Hello, world!");
    insert(&head, 2, "This is a secret message.");
    insert(&head, 3, "It can only be seen by the owner.");

    if (search(head, 2)) {
        printf("The secret message is: %s\n", head->next->data);
    } else {
        printf("Key not found.\n");
    }

    return 0;
}