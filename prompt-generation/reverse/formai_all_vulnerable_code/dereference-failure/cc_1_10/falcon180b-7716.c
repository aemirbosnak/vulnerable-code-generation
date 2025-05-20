//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void insert_at_end(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_by_value(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insert_at_end(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    insert_at_end(&head, 5);

    printf("Linked List before deletion:\n");
    display(head);

    delete_by_value(&head, 3);

    printf("Linked List after deletion:\n");
    display(head);

    return 0;
}