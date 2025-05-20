//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insert(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

void findRoute(Node* head, char start, char end) {
    char buffer[MAX_BUFFER_SIZE];
    int bufferIndex = 0;
    Node* current = head;

    while (current) {
        if (current->data == start) {
            insert(head, end);
            break;
        } else if (bufferIndex < MAX_BUFFER_SIZE) {
            insert(head, current->data);
            buffer[bufferIndex++] = current->data;
        } else {
            break;
        }
        current = current->next;
    }

    if (bufferIndex == 0) {
        printf("No route found.\n");
    } else {
        printf("Route found: ");
        for (int i = 0; i < bufferIndex; i++) {
            printf("%c ", buffer[i]);
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    insert(head, 'a');
    insert(head, 'b');
    insert(head, 'c');
    insert(head, 'd');
    insert(head, 'e');

    findRoute(head, 'a', 'e');

    return 0;
}