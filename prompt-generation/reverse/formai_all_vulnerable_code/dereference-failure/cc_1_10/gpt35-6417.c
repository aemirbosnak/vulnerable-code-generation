//FormAI DATASET v1.0 Category: Data structures visualization ; Style: excited
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void display(struct Node* head) {
    if (head == NULL)
        printf("List is empty\n");
    else {
        printf("List elements are: ");
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node* head = NULL;
    int n = 5;
    for (int i = 0; i < n; i++) 
        push(&head, rand() % 100 + 1);
    printf("Before sorting:\n");
    display(head);
    struct Node* first = head;
    struct Node* second = head->next;
    while (second->next != NULL) {
        first = first->next;
        second = second->next->next;
    }
    second = first->next;
    first->next = NULL;
    first = head;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->next = NULL;
    struct Node* tail = temp;
    while (first != NULL && second != NULL) {
        if (first->data < second->data) {
            tail->next = first;
            first = first->next;
        }
        else {
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }
    if (first != NULL)
        tail->next = first;
    else
        tail->next = second;
    printf("\nAfter sorting:\n");
    display(temp->next);
    return 0;
}