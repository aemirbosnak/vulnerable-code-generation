//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct node {
    int data;
    struct node* next;
} node;

node* insert(node* head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void findMazeRoute(node* head) {
    node* current = head;
    node* previous = NULL;
    int visited[MAX_SIZE] = {0};

    while (current) {
        if (!visited[current->data]) {
            visited[current->data] = 1;

            if (previous) {
                printf("(%d, %d) ", previous->data, current->data);
            }

            printf("%d ", current->data);

            previous = current;
            current = current->next;
        }
    }

    printf("\n");
}

int main() {
    node* head = insert(NULL, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    findMazeRoute(head);

    return 0;
}