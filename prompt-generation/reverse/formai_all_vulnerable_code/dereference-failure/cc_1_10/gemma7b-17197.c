//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Cyberpunk
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
    struct Node* prev;
} Node;

void insert(Node** head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void findRoute(Node* head, char* start, char* end) {
    while (head) {
        if (strcmp(start, head->name) == 0) {
            printf("Found start node: %s\n", head->name);
            findRoute(head->next, end, start);
        } else if (strcmp(end, head->name) == 0) {
            printf("Found end node: %s\n", head->name);
            return;
        } else {
            findRoute(head->next, end, start);
        }
    }
    printf("No route found.\n");
}

int main() {
    Node* head = NULL;
    insert(&head, "A");
    insert(&head, "B");
    insert(&head, "C");
    insert(&head, "D");
    insert(&head, "E");

    findRoute(head, "A", "E");

    return 0;
}