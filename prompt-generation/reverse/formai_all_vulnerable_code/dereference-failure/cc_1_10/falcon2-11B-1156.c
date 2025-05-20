//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Linked list operations */
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtHead(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAtPosition(struct Node** head_ref, int pos, int new_data) {
    if (pos == 0) {
        insertAtHead(head_ref, new_data);
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    struct Node* temp = *head_ref;
    int count = 0;
    while (temp!= NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position not found.\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* curr = *head_ref;
    while (curr!= NULL) {
        struct Node* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    *head_ref = prev;
}

int main() {
    struct Node* head = NULL;
    insertAtHead(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtPosition(&head, 1, 0);
    insertAtPosition(&head, 2, 4);
    insertAtPosition(&head, 3, 5);
    printList(head);
    printf("\n");
    reverseList(&head);
    printList(head);
    printf("\n");
    return 0;
}