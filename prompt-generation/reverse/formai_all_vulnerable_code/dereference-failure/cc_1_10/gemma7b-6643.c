//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

void encrypt(Node* head) {
    Node* current = head;
    while (current) {
        current->data ^= 0x1F;
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    // Insert data into the linked list
    insertAtTail(head, 'H');
    insertAtTail(head, 'a');
    insertAtTail(head, 'r');
    insertAtTail(head, 'a');

    // Encrypt the data
    encrypt(head);

    // Print the encrypted data
    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}