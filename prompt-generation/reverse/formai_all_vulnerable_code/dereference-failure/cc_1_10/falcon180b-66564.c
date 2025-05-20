//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("Pushed %d to the stack\n", new_data);
}

void pop(struct Node** head_ref) {
    struct Node* temp = *head_ref;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped %d from the stack\n", temp->data);
    *head_ref = temp->next;
    free(temp);
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);

    printf("Stack after pushing 10, 20, 30, 40, and 50\n");
    printList(head);

    pop(&head);
    printf("Stack after popping 50\n");
    printList(head);

    pop(&head);
    printf("Stack after popping 40\n");
    printList(head);

    pop(&head);
    printf("Stack after popping 30\n");
    printList(head);

    pop(&head);
    printf("Stack after popping 20\n");
    printList(head);

    pop(&head);
    printf("Stack after popping 10\n");
    printList(head);

    return 0;
}