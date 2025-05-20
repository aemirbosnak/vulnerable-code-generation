//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int binarySearch(Node* head, int x) {
    Node* slow = head;
    Node* fast = head;

    do {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    } while (fast != slow);

    Node* mid = slow;

    do {
        if (mid->data == x)
            return 1;

        if (x < mid->data) {
            fast = mid->next;
            mid = mid->next;
        } else {
            slow = mid;
            mid = mid->next;
        }
    } while (fast != slow);

    return 0;
}

int main() {
    Node* head = NULL;

    // Fill the circular linked list with numbers
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);
    push(&head, 1);
    push(&head, 10);

    int target = 7;

    if (binarySearch(head, target))
        printf("%d found in the array\n", target);
    else
        printf("%d not found in the array\n", target);

    printList(head);

    return 0;
}