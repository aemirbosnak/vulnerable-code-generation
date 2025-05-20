//FormAI DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data; /* data = node value */
    struct node* next; /* pointer to next node */
};

/* Function to insert a node at the beginning of a Linked List*/
void insertAtBeginning(struct node **head_ref, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* Function to insert a node at the end of a Linked List*/
void insertAtEnd(struct node **head_ref, int data) {
    struct node* current = *head_ref;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

/* Function to print Linked List from a given node */
void printList(struct node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

/* Function to delete a node from a Linked List*/
void deleteNode(struct node **head_ref, int key) {
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

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

/* Function to reverse a Linked List*/
void reverse(struct node** head_ref) {
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

int main() {
    /* Creating a Linked List */
    struct node* head = NULL;

    /* Insertion Operations */
    insertAtEnd(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 6);

    /* Displaying Linked List after insertion */
    printf("Linked List after Insertion: ");
    printList(head);

    /* Deletion Operation */
    deleteNode(&head, 4);

    /* Displaying Linked List after deletion */
    printf("Linked List after Deletion: ");
    printList(head);

    /* Reversing Operation */
    reverse(&head);

    /* Displaying Linked List after Reversal */
    printf("Linked List after Reversal: ");
    printList(head);

    return 0;
}