//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node* next;
} node;

void insertAtTail(node* head, char data) {
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void printMaze(node* head) {
    node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'd');
    insertAtTail(head, 'e');

    printMaze(head);

    // Find the route from a to e
    node* current = head;
    while (current) {
        if (current->data == 'a') {
            current = current->next->next->next->next->next;
            printMaze(current);
            break;
        }
        current = current->next;
    }

    return 0;
}