//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Create a serene garden of pointers
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Plant a new sapling in the garden
Node* createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Let the wind gently sway the branches
void displayGarden(Node *head) {
    Node *current = head;
    printf("\nTranquil Garden: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Nurture the garden with love and care
void insertNode(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Prune the garden to maintain its beauty
void deleteNode(Node **head, int data) {
    if (*head == NULL) {
        printf("Empty garden, nothing to prune.\n");
        return;
    }
    Node *current = *head;
    Node *previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("%d not found in the garden.\n", data);
}

// Let us bask in the serenity of our garden
int main() {
    Node *head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 4);
    insertNode(&head, 9);
    insertNode(&head, 16);
    displayGarden(head);
    deleteNode(&head, 9);
    displayGarden(head);
    return 0;
}