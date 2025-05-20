//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void delete(struct node **head_ref, int key) {
    struct node *temp = *head_ref;
    struct node *prev;

    if (temp == NULL)
        return;

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (temp == *head_ref) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int search(struct node *head, int key) {
    while (head!= NULL && head->data!= key) {
        head = head->next;
    }

    if (head == NULL)
        return -1;
    else
        return 1;
}

int main() {
    struct node *head = NULL;
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);

    printf("Search 15: %d\n", search(head, 15));
    printf("Search 20: %d\n", search(head, 20));

    delete(&head, 10);

    printf("Search 10: %d\n", search(head, 10));

    return 0;
}