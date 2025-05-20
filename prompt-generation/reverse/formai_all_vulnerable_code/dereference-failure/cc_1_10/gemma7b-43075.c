//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STASH 1024

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
    }
}

char extractFromTail(Node** head) {
    if (*head == NULL) {
        return -1;
    }

    char data = (*head)->data;
    *head = (*head)->next;
    return data;
}

int main() {
    Node* stash = NULL;

    // Embed secret message in the stash
    insertAtTail(&stash, 'H');
    insertAtTail(&stash, 'I');
    insertAtTail(&stash, 'S');
    insertAtTail(&stash, 'T');
    insertAtTail(&stash, 'H');

    // Retrieve secret message from the stash
    char secretMessage[MAX_STASH];
    int i = 0;
    while ((secretMessage[i] = extractFromTail(&stash)) != -1) {
        i++;
    }

    // Print the secret message
    secretMessage[i] = '\0';
    printf("%s", secretMessage);

    return 0;
}