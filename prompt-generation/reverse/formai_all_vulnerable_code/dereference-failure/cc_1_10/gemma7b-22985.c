//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

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
        (*head)->next = newNode;
    }
}

int main() {
    Node* head = NULL;

    // Insert a bunch of wacky items
    insertAtTail(&head, 'a');
    insertAtTail(&head, 'b');
    insertAtTail(&head, 'c');
    insertAtTail(&head, 'e');
    insertAtTail(&head, 'f');
    insertAtTail(&head, 'g');
    insertAtTail(&head, 'h');

    // Now, let's play a surrealist game
    while (head) {
        // Randomly shuffle the items
        int r = rand() % MAX_SIZE;
        Node* current = head;
        for (int i = 0; i < r; i++) {
            current = current->next;
        }

        // Swap the items
        char temp = current->data;
        current->data = head->data;
        head->data = temp;

        // Eat the items
        printf("%c has been devoured!\n", current->data);

        // Free the memory
        free(current);
        head = head->next;
    }

    return 0;
}