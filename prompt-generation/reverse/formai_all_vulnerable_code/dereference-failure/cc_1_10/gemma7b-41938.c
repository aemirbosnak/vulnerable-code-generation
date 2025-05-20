//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct Node {
    char character;
    int frequency;
    struct Node* next;
} Node;

Node* insertNode(Node* head, char character) {
    Node* newNode = malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = 1;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* traversal = head;
        while (traversal->next) {
            traversal = traversal->next;
        }
        traversal->next = newNode;
    }

    return head;
}

void traverse(Node* head) {
    Node* traversal = head;
    while (traversal) {
        printf("%c: %d ", traversal->character, traversal->frequency);
        traversal = traversal->next;
    }
}

int main() {
    char text[] = "This is a sample text to count character frequencies.";
    Node* head = NULL;

    // Insert characters into the linked list
    for (int i = 0; text[i] != '\0'; i++) {
        insertNode(head, text[i]);
    }

    // Traverse the linked list and print character frequencies
    traverse(head);

    return 0;
}