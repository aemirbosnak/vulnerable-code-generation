//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void findCircle(Node* head) {
    int i = 0;
    while (head) {
        i++;
        if (head->next && head->next->next && head->next->next->next && head->next->next->next->next) {
            double dx1 = head->x - head->next->next->next->x;
            double dy1 = head->y - head->next->next->next->y;
            double dx2 = head->x - head->next->next->next->next->x;
            double dy2 = head->y - head->next->next->next->next->y;

            double r = sqrt(dx1 * dx1 + dy1 * dy1) + sqrt(dx2 * dx2 + dy2 * dy2);

            if (r < MAX) {
                printf("Circle found at (%d, %d) with radius %.2lf\n", head->x, head->y, r);
            }
        }
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 1, 1);
    insertAtTail(&head, 2, 2);
    insertAtTail(&head, 3, 3);
    insertAtTail(&head, 4, 4);
    insertAtTail(&head, 5, 5);
    insertAtTail(&head, 6, 6);

    findCircle(head);

    return 0;
}