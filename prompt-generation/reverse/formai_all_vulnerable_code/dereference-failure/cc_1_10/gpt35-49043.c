//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    
    printf("Hooray! Element %d has been added to the linked list\n", new_data);
}

void delete(struct node **head_ref, int key) {
    struct node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("Hooray! Element %d has been deleted from the linked list\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Oops! Element %d not found in the linked list\n", key);
        return;
    }
    
    prev->next = temp->next;
    free(temp);
    printf("Hooray! Element %d has been deleted from the linked list\n", key);
}

void display(struct node *node) {
    printf("The linked list is: ");
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    insert(&head, 6);
    insert(&head, 3);
    insert(&head, 1);
    insert(&head, 7);
    insert(&head, 10);
    display(head);
    delete(&head, 1);
    display(head);
    delete(&head, 7);
    display(head);
    delete(&head, 9);
    display(head);
    return 0;
}