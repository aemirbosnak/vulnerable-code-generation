//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Node* insertAtTail(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int findMazeRoute(struct Node* head) {
    struct Node* current = head;
    int visited = 0;
    int route = 0;

    while (current) {
        if (visited & current->data) {
            continue;
        }

        visited |= current->data;

        if (current->next && current->next->data == route) {
            route = current->data;
        }

        current = current->next;
    }

    return route;
}

int main() {
    struct Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);

    int route = findMazeRoute(head);

    printf("The route is: %d", route);

    return 0;
}