//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void insert(Node** head, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void draw(Node* head) {
    while (head) {
        printf("(");
        printf("%d, %d)", head->x, head->y);
        printf(")\n");
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    insert(&head, 0, 0);
    insert(&head, 1, 1);
    insert(&head, 2, 2);
    insert(&head, 3, 3);

    draw(head);

    // Shape shifting
    head = head->next;
    head->x = 4;
    head->y = 4;

    draw(head);

    return 0;
}