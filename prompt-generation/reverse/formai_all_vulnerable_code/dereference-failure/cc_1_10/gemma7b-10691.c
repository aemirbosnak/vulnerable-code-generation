//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

void findMazeRoute(Node* head) {
    Node* current = head;
    int visited[MAX_SIZE] = {0};

    while (current) {
        if (!visited[current->data]) {
            visited[current->data] = 1;

            printf("Current Node: %d\n", current->data);

            if (current->next) {
                findMazeRoute(current->next);
            }
        }
        current = current->next;
    }

    return;
}

int main() {
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    findMazeRoute(head);

    return 0;
}