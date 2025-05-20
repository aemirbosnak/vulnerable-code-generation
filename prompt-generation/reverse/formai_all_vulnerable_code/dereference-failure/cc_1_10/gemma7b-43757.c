//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

void insert(Node* node, char data) {
    Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = node;

    if (node) {
        node->next = newNode;
    } else {
        node = newNode;
    }

    return;
}

void printList(Node* node) {
    while (node) {
        printf("%c ", node->data);
        node = node->next;
    }

    printf("\n");
    return;
}

int main() {
    Node* head = NULL;

    insert(head, 'a');
    insert(head, 'b');
    insert(head, 'c');
    insert(head, 'd');

    printList(head);

    // Find the route from a to d
    Node* current = head;
    Node* destination = NULL;
    char currentChar = 'a';
    char destinationChar = 'd';

    while (current && currentChar != destinationChar) {
        if (current->next && current->next->data == destinationChar) {
            destination = current->next;
            currentChar = destinationChar;
        } else {
            current = current->next;
            currentChar = current->data;
        }
    }

    if (destination) {
        printf("The route from %c to %c is: ", currentChar, destinationChar);
        printList(destination);
    } else {
        printf("No route found.\n");
    }

    return 0;
}