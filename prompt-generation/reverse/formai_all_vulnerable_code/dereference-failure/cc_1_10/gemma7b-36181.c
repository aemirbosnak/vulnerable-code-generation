//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node* head, int data) {
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

void findRoute(Node* head, int target) {
    Node* current = head;
    while (current) {
        if (current->data == target) {
            printf("Route found!\n");
            return;
        } else if (current->data < target) {
            current = current->next;
        } else {
            return;
        }
    }
    printf("No route found.\n");
}

int main() {
    Node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    insert(head, 9);
    insert(head, 10);

    findRoute(head, 6);

    return 0;
}