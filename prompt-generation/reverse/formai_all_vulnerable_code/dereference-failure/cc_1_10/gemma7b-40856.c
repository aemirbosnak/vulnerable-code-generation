//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node {
    char name[MAX];
    struct node* next;
} node;

node* insert(node* head, char name[]) {
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void findRoute(node* head, char* start, char* end) {
    node* current = head;
    char* currentPos = start;
    char* targetPos = end;

    while (current) {
        if (strcmp(currentPos, current->name) == 0) {
            printf("Current position: %s\n", currentPos);
            printf("Target position: %s\n", targetPos);

            if (strcmp(targetPos, current->name) == 0) {
                printf("Route found!\n");
                return;
            }

            currentPos = current->next;
        } else {
            current = current->next;
        }
    }

    printf("No route found.\n");
}

int main() {
    node* head = NULL;
    insert(head, "A");
    insert(head, "B");
    insert(head, "C");
    insert(head, "D");
    insert(head, "E");

    findRoute(head, "A", "D");

    return 0;
}