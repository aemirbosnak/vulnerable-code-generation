//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENG 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void dfs(Node* current, char target, int* visited, int* path) {
    visited[current->data] = 1;

    if (current->data == target) {
        path[current->data] = 1;
        return;
    }

    for (Node* next = current->next; next != NULL; next++) {
        if (!visited[next->data]) {
            dfs(next, target, visited, path);
        }
    }
}

int main() {
    Node* head = insertAtTail(NULL, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'd');
    insertAtTail(head, 'e');

    int visited[MAX_LENG] = {0};
    int path[MAX_LENG] = {0};

    dfs(head, 'e', visited, path);

    for (int i = 0; i < MAX_LENG; i++) {
        printf("%d ", path[i]);
    }

    return 0;
}