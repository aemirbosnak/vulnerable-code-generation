//FormAI DATASET v1.0 Category: Linked list operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct node {
    int data;
    struct node *next;
};

// Create a new node
struct node* create_node(int value){
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the beginning of the linked list
void insert_beginning(struct node** headRef, int value){
    struct node* newNode = create_node(value); // create a new node
    newNode->next = *headRef; // point the new node to the current head
    *headRef = newNode; // set the new node as the head
}

// Insert a node at the end of the linked list
void insert_end(struct node** headRef, int value){
    struct node* newNode = create_node(value); // create a new node
    struct node* currentNode = *headRef;
    // if the list is empty, make the new node the head
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    // iterate to the last node
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    // add the new node to the end
    currentNode->next = newNode;
}

// Delete a node with a given value from the linked list
void delete_node(struct node** headRef, int value){
    struct node* currentNode = *headRef;
    struct node* prevNode = NULL;
    // if the head node has the value we're looking for
    if (currentNode != NULL && currentNode->data == value) {
        *headRef = currentNode->next; // set the next node as the new head
        free(currentNode); // free the memory of the deleted node
        return;
    }
    // iterate through the list to find the node to be deleted
    while (currentNode != NULL && currentNode->data != value) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    // if the value is not found in the list
    if (currentNode == NULL) {
        return;
    }
    prevNode->next = currentNode->next; // set the next node after the deleted node as the new next node for the previous node
    free(currentNode); // free the memory of the deleted node
}

// Print the linked list
void print_list(struct node* head){
    struct node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL; // initialize an empty linked list
    
    insert_beginning(&head, 5); // add 5 to the beginning of the list
    insert_beginning(&head, 10); // add 10 to the beginning of the list
    insert_end(&head, 20); // add 20 to the end of the list
    insert_end(&head, 30); // add 30 to the end of the list
    
    printf("Original Linked List: ");
    print_list(head); // print the original linked list
    
    delete_node(&head, 20); // delete 20 from the list
    
    printf("Linked List after deleting 20: ");
    print_list(head); // print the list after deletion
    
    return 0;
}