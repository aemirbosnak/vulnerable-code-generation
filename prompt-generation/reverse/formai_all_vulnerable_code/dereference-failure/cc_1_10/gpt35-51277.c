//FormAI DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void addNode(Node** head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = createNode(data);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    printf("Original List: ");
    printList(head);

    // Deleting the node with data 3
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) {
        if (current->data == 3) {
            if (prev == NULL) {
                head = head->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
    printf("List after deleting node with data 3: ");
    printList(head);

    // Adding a new node with data 6
    addNode(&head, 6);
    printf("List after adding node with data 6: ");
    printList(head);

    return 0;
}