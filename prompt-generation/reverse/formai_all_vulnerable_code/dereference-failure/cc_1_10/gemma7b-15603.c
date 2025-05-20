//Gemma-7B DATASET v1.0 Category: Chess engine ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int move;
    struct Node* next;
} Node;

Node** createList(int n) {
    Node** head = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        head[i] = NULL;
    }
    return head;
}

void insertNode(Node** head, int move) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->move = move;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int searchList(Node** head, int move) {
    for (Node* node = *head; node; node = node->next) {
        if (node->move == move) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n = MAX;
    Node** list = createList(n);

    insertNode(list, 1);
    insertNode(list, 2);
    insertNode(list, 3);

    if (searchList(list, 2)) {
        printf("Move 2 found in the list.\n");
    } else {
        printf("Move 2 not found in the list.\n");
    }

    return 0;
}