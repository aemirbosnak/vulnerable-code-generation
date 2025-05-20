//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

/* Define the structure for the linked list node */
struct node {
    int data;
    struct node *next;
};

/* Function to create a new node with the given data */
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to add a node at the end of the list */
void add_node(struct node **head, int data) {
    struct node *new_node = create_node(data);
    struct node *temp = *head;
    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
}

/* Function to delete a node with the given data */
void delete_node(struct node **head, int data) {
    struct node *temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    struct node *prev = temp->next;
    temp->next = NULL;
    free(temp);
    prev->next = temp->next;
}

/* Function to search for a node with the given data */
struct node *search_node(struct node *head, int data) {
    struct node *temp = head;
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return NULL;
    }
    return temp;
}

/* Function to print the list */
void print_list(struct node *head) {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Driver program */
int main() {
    struct node *head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    print_list(head);
    search_node(head, 3);
    delete_node(&head, 2);
    print_list(head);
    return 0;
}