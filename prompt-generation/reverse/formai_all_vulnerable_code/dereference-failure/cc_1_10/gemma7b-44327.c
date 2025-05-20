//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: rigorous
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

void printList(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    printList(head);

    // Maze Route Finder Algorithm

    struct Node* current = head;
    struct Node* goal = head->next->next->next;

    while (current != goal) {
        if (current->next != NULL) {
            current = current->next;
        } else {
            current = head;
        }
    }

    printf("Goal reached!\n");

    return 0;
}