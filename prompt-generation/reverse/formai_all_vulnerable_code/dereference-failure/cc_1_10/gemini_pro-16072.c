//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: puzzling
// Puzzle: Can you unscramble the words to reveal a hidden message?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a linked list node to store a single word
typedef struct Node {
    char *word;
    struct Node *next;
} Node;

// Create a new node with the given word
Node *createNode(char *word) {
    Node *node = malloc(sizeof(Node));
    node->word = strdup(word);
    node->next = NULL;
    return node;
}

// Insert a new node at the end of the list
void insertNode(Node **head, char *word) {
    Node *new_node = createNode(word);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Print the words in the list in reverse order
void printListReverse(Node *head) {
    if (head == NULL) {
        return;
    }
    printListReverse(head->next);
    printf("%s ", head->word);
}

// Free the memory allocated for the list
void freeList(Node *head) {
    if (head == NULL) {
        return;
    }
    freeList(head->next);
    free(head->word);
    free(head);
}

int main() {
    // Create a list of words
    Node *head = NULL;
    insertNode(&head, "the");
    insertNode(&head, "the");
    insertNode(&head, "for");
    insertNode(&head, "of");
    insertNode(&head, "people");
    insertNode(&head, "by");
    insertNode(&head, "by");
    insertNode(&head, "the");

    // Print the words in the list in reverse order
    printListReverse(head);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}