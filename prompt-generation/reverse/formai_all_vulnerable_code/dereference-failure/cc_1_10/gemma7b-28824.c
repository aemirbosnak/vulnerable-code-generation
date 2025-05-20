//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 4096

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

char extractFromTail(Node** head) {
    if (*head == NULL) {
        return -1;
    }

    char data = (*head)->data;
    *head = (*head)->next;
    return data;
}

int main() {
    Node* secretList = NULL;

    // Hide the secret message in the list
    insertAtTail(&secretList, 'H');
    insertAtTail(&secretList, 'i');
    insertAtTail(&secretList, 'c');
    insertAtTail(&secretList, 'o');
    insertAtTail(&secretList, 'n');
    insertAtTail(&secretList, 'a');
    insertAtTail(&secretList, 'T');
    insertAtTail(&secretList, 'o');
    insertAtTail(&secretList, 'R');
    insertAtTail(&secretList, 'a');

    // Reveal the secret message
    for (Node* current = secretList; current; current = current->next) {
        printf("%c ", extractFromTail(&secretList));
    }

    printf("\n");

    return 0;
}