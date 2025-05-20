//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 12
#define MAX_MSG_LEN 1024

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
        ((*head)->next = newNode);
        *head = newNode;
    }
}

int encode(char* message, Node** head) {
    int i = 0;
    for (; message[i] != '\0'; i++) {
        insertAtTail(head, (message[i] << KEY) & 0xFF);
    }
    return i;
}

int decode(Node* head, char** message) {
    int i = 0;
    *message = malloc(MAX_MSG_LEN);
    for (; head; head = head->next) {
        (*message)[i] = (head->data & 0xFF) >> KEY;
        i++;
    }
    (*message)[i] = '\0';
    return i;
}

int main() {
    char message[] = "This is a secret message";
    Node* head = NULL;
    int messageLen = encode(message, &head);

    char* decodedMessage = NULL;
    int decodedLen = decode(head, &decodedMessage);

    printf("Original message: %s\n", message);
    printf("Decoded message: %s\n", decodedMessage);

    return 0;
}