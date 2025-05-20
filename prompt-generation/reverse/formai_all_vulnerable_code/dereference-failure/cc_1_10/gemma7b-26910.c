//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Node** createList() {
    return (struct Node**)malloc(sizeof(struct Node*) * MAX_SIZE);
}

void addToTail(struct Node** head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void findMazeRoute(struct Node** head) {
    struct Node* current = *head;
    char route[MAX_SIZE] = "";

    while (current) {
        if (current->data == 'E') {
            printf("The route is: %s\n", route);
            return;
        } else if (current->data != 'S') {
            addToTail(route, current->data);
        }

        current = current->next;
    }

    printf("No route found.\n");
}

int main() {
    struct Node** head = createList();
    addToTail(head, 'A');
    addToTail(head, 'B');
    addToTail(head, 'C');
    addToTail(head, 'D');
    addToTail(head, 'E');

    findMazeRoute(head);

    return 0;
}