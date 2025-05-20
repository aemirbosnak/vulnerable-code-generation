//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char character;
    int frequency;
    struct Node* next;
} Node;

Node* insertNode(Node* head, char character, int frequency) {
    Node* newNode = malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

void printFrequency(Node* head) {
    Node* current = head;
    while (current) {
        printf("%c: %d ", current->character, current->frequency);
        current = current->next;
    }
    printf("\n");
}

int main() {
    char* text = "This is a sample text for C word frequency counter.";
    Node* head = NULL;

    // Insert characters and their frequency into the linked list
    insertNode(head, 'a', 3);
    insertNode(head, 'i', 2);
    insertNode(head, 's', 2);
    insertNode(head, 't', 2);
    insertNode(head, 'e', 2);
    insertNode(head, 'c', 1);
    insertNode(head, 'o', 1);
    insertNode(head, 'r', 1);
    insertNode(head, 'f', 1);

    // Print character frequency
    printFrequency(head);

    return 0;
}