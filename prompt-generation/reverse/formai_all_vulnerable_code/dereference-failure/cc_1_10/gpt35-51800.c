//FormAI DATASET v1.0 Category: Linked list operations ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = *head;
    *head = new_node;
}

void insert_at_end(struct node **head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *ptr = *head;
    while (ptr -> next != NULL) {
        ptr = ptr -> next;
    }
    ptr -> next = new_node;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ",ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}

void delete_node(struct node **head, int key) {
    if (*head == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node *ptr = *head, *prev = NULL;
    while (ptr != NULL && ptr -> data != key) {
        prev = ptr;
        ptr = ptr -> next;
    }
    if (prev == NULL) {
        *head = (*head) -> next;
        free(ptr);
        return;
    }
    if (ptr == NULL) {
        printf("%d not found\n",key);
        return;
    }
    prev -> next = ptr -> next;
    free(ptr);
}

int main() {
    struct node *head = NULL;
    //testing insert_at_beginning
    insert_at_beginning(&head,5);
    insert_at_beginning(&head,4);
    insert_at_beginning(&head,3);
    insert_at_beginning(&head,2);
    insert_at_beginning(&head,1);
    printf("List after insert_at_beginning: ");
    display(head);
    //testing insert_at_end
    insert_at_end(&head,6);
    insert_at_end(&head,7);
    insert_at_end(&head,8);
    insert_at_end(&head,9);
    insert_at_end(&head,10);
    printf("List after insert_at_end: ");
    display(head);
    //testing delete_node
    delete_node(&head,5);
    delete_node(&head,1);
    delete_node(&head,10);
    printf("List after delete operations: ");
    display(head);
    return 0;
}