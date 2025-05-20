//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

void insert_at_head(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation error!\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void delete_at_head(struct node **head_ref) {
    struct node *temp = (*head_ref);
    if (!temp) {
        printf("List is empty!\n");
        return;
    }
    (*head_ref) = temp->next;
    free(temp);
}

void print_list(struct node *head) {
    struct node *temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    insert_at_head(&head, 1);
    insert_at_head(&head, 2);
    insert_at_head(&head, 3);
    print_list(head);

    delete_at_head(&head);
    print_list(head);

    return 0;
}