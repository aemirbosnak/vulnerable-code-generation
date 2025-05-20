//FormAI DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

/* Defining the structure of node in linked list */
struct node {
    int data;
    struct node* next;
};

/* A function to create a new node with given data */
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* A function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int data) {
    struct node* node = newNode(data);
    node->next = (*head_ref);
    (*head_ref) = node;
}

/* A function to insert a node after a given node */
void insertAfter(struct node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
    struct node* node = newNode(data);
    node->next = prev_node->next;
    prev_node->next = node;
}

/* A function to insert a node at the end of linked list */
void append(struct node** head_ref, int data) {
    struct node* node = newNode(data);
    struct node* last = (*head_ref);
    node->next = NULL;
    if (*head_ref == NULL) {
        (*head_ref) = node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = node;
}

/* A function to delete a node from linked list */
void deleteNode(struct node** head_ref, int key) {
    struct node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

/* A function to print linked list */
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above functions */
int main() {
    struct node* head = NULL;
    push(&head, 1); /* Add 1 at the beginning */
    append(&head, 4); /* Add 4 at the end */
    insertAfter(head->next, 3); /* Add 3 after 1 */
    printf("Original List: ");
    printList(head);
    deleteNode(&head, 3); /* Delete node with key 3 */
    printf("\nList after deletion of 3: ");
    printList(head);
    return 0;
}