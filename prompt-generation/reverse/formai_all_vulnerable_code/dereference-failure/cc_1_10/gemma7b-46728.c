//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next) = newNode;
    }
}

void encrypt(Node** head) {
    Node* current = *head;
    while (current) {
        current->data = (current->data) ^ 0x1F;
        current = current->next;
    }
}

void decrypt(Node** head) {
    Node* current = *head;
    while (current) {
        current->data = (current->data) ^ 0x1F;
        current = current->next;
    }
}

int main() {
    char message[] = "Hello, world!";
    Node* head = NULL;

    for (int i = 0; message[i] != '\0'; i++) {
        insertAtTail(&head, message[i]);
    }

    encrypt(&head);

    printf("Encryped message:\n");
    for (Node* current = head; current; current = current->next) {
        printf("%c ", current->data);
    }

    printf("\n");

    decrypt(&head);

    printf("Decrypted message:\n");
    for (Node* current = head; current; current = current->next) {
        printf("%c ", current->data);
    }

    printf("\n");

    return 0;
}