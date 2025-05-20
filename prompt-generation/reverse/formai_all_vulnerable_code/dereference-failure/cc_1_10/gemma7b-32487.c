//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    printList(head);

    // Greedy Algorithm Example

    Node* pointer = head;
    while (pointer) {
        Node* current = pointer;
        pointer = pointer->next;

        if (current->data > pointer->data) {
            insert(head, current->data);
            free(current);
        }
    }

    printList(head);

    return 0;
}