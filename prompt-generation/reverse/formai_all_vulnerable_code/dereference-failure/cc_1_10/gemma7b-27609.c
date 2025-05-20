//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct Node {
    char character;
    int frequency;
    struct Node* next;
} Node;

Node* insert(Node* head, char character, int frequency) {
    Node* newNode = malloc(sizeof(Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        Node* previous = NULL;

        while (current) {
            if (newNode->character == current->character) {
                current->frequency++;
                return head;
            } else if (newNode->character < current->character) {
                previous = current;
                current = current->next;
            } else {
                previous = current;
                current = current->next;
            }
        }

        previous->next = newNode;
    }

    return head;
}

void huffman(Node* head) {
    // Build the Huffman tree
    // Traverse the tree and encode the characters

    printf("Huffman Coding:**\n");
    printf("--------------------\n");

    Node* current = head;
    while (current) {
        printf("%c: %d\n", current->character, current->frequency);
    }

    printf("--------------------\n");
}

int main() {
    Node* head = NULL;

    head = insert(head, 'a', 5);
    head = insert(head, 'b', 3);
    head = insert(head, 'c', 2);
    head = insert(head, 'd', 4);
    head = insert(head, 'e', 6);

    huffman(head);

    return 0;
}