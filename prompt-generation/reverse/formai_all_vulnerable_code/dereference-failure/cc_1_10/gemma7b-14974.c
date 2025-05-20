//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void findRoute(Node* head, char target) {
    char currentChar;
    Node* current = head;

    while (current) {
        currentChar = current->data;

        if (currentChar == target) {
            printf("Target found!\n");
            return;
        } else if (currentChar < target) {
            current = current->next;
        } else {
            printf("No route found.\n");
            return;
        }
    }

    printf("No route found.\n");
}

int main() {
    Node* head = insertAtTail(NULL, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'd');
    insertAtTail(head, 'e');

    findRoute(head, 'e');

    return 0;
}