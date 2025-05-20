//FormAI DATASET v1.0 Category: Linked list operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// structure to represent each node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node **head_ref, int new_data){
    // allocate memory for the new node
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    // assign the new data to the new node's data field
    new_node->data = new_data;

    // set the new node's next field to the current head of the linked list
    new_node->next = *head_ref;

    // set the head of the linked list to the new node
    *head_ref = new_node;
}

// function to insert a new node at the end of the linked list
void insertAtEnd(struct Node **head_ref, int new_data){
    // allocate memory for the new node
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    // assign the new data to the new node's data field
    new_node->data = new_data;

    // set the new node's next field to NULL, since it will be the last node
    new_node->next = NULL;

    // if the linked list is empty, set the new node as the head of the linked list
    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    // traverse the linked list until the last node is reached
    struct Node *last = *head_ref;
    while (last->next != NULL){
        last = last->next;
    }

    // set the next field of the last node to the new node
    last->next = new_node;
}

// function to delete a node with a given value from the linked list
void deleteNode(struct Node **head_ref, int key){
    // if the head node needs to be deleted
    if (*head_ref != NULL && (*head_ref)->data == key){
        // store the head node's next field in a temporary variable
        struct Node *temp = *head_ref;

        // set the head node to its next field
        *head_ref = (*head_ref)->next;

        // free the memory allocated to the old head node
        free(temp);
        return;
    }

    // traverse the linked list until the node to be deleted is found
    struct Node *prev = NULL;
    struct Node *curr = *head_ref;
    while (curr != NULL && curr->data != key){
        prev = curr;
        curr = curr->next;
    }

    // return if the node to be deleted was not found
    if (curr == NULL){
        return;
    }

    // set the previous node's next field to the current node's next field
    prev->next = curr->next;

    // free the memory allocated to the node to be deleted
    free(curr);
}

// function to print the linked list
void printList(struct Node *node){
    while (node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    // create an empty linked list
    struct Node *head = NULL;

    // insert some nodes at the beginning of the linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 1);

    // print the updated linked list
    printf("Updated linked list after insertion at beginning: ");
    printList(head);
    printf("\n");

    // insert some nodes at the end of the linked list
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 11);

    // print the updated linked list
    printf("Updated linked list after insertion at end: ");
    printList(head);
    printf("\n");

    // delete some nodes from the linked list
    deleteNode(&head, 5);
    deleteNode(&head, 11);
    deleteNode(&head, 1);

    // print the updated linked list
    printf("Updated linked list after deletion: ");
    printList(head);
    printf("\n");

    return 0;
}