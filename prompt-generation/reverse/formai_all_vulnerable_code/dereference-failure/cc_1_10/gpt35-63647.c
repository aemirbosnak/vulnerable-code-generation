//FormAI DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void add(Node** head, int val) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void delete(Node** head, int val) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == val) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;
    add(&head, 5);
    add(&head, 7);
    add(&head, 10);
    add(&head, 12);
    add(&head, 18);

    printf("Initial linked list: ");
    display(head);

    printf("\nDeleting 10 from linked list...\n");
    delete(&head, 10);

    printf("Updated linked list: ");
    display(head);

    printf("\nAdding 25 to linked list...\n");
    add(&head, 25);

    printf("Updated linked list: ");
    display(head);
  
    return 0;
}