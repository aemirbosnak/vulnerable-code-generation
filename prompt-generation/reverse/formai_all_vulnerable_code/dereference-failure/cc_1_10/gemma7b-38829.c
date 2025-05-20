//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void InsertNode(Node* head, int x, int y) {
    Node* newNode = CreateNode(x, y);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void FindMazeRoute(Node* head) {
    time_t start = time(NULL);
    int visited[MAX_SIZE][MAX_SIZE] = {{0}};
    visited[head->x][head->y] = 1;

    Node* current = head;
    while (current) {
        if (visited[current->x][current->y] == 0) {
            InsertNode(current, current->x - 1, current->y);
            InsertNode(current, current->x + 1, current->y);
            InsertNode(current, current->x, current->y - 1);
            InsertNode(current, current->x, current->y + 1);
            visited[current->x][current->y] = 1;
        }
        current = current->next;
    }

    time_t end = time(NULL);
    printf("Time taken: %ld seconds\n", end - start);
}

int main() {
    Node* head = CreateNode(0, 0);
    InsertNode(head, 1, 0);
    InsertNode(head, 2, 0);
    InsertNode(head, 3, 0);
    InsertNode(head, 3, 1);
    InsertNode(head, 3, 2);
    InsertNode(head, 2, 2);
    InsertNode(head, 1, 2);
    InsertNode(head, 0, 2);

    FindMazeRoute(head);

    return 0;
}