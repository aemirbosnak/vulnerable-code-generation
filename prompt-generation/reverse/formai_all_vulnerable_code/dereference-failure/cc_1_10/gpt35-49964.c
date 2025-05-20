//FormAI DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Creating the structure node
struct node {
    int data; // Data of the node
    struct node* next; // Pointer to the next node
};

// Function to create a new node and return its pointer
struct node* createNode(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); // Allocating memory
    new_node->data = data; // Assigning data to the node
    new_node->next = NULL; // Assigning NULL to next
    return new_node;
}

// Function to insert a node at the beginning of the linked list
struct node* insertAtBeginning(struct node* head, int data){
    struct node* new_node = createNode(data); // Creating a new node
    if(head == NULL) // If the linked list is empty
        return new_node;
    new_node->next = head; // Making new node as the head
    return new_node;
}

// Function to insert a node at the end of the linked list
struct node* insertAtEnd(struct node* head, int data){
    struct node* new_node = createNode(data); // Creating a new node
    if(head == NULL) // If the linked list is empty
        return new_node;
    struct node* temp = head; 
    while(temp->next != NULL) // Traversing till the end of the linked list
        temp = temp->next;
    temp->next = new_node; // Making new node as the last node
    return head;
}

// Function to delete a node from the linked list
struct node* deleteNode(struct node* head, int key){
    if(head == NULL) // If the linked list is empty
        return head;
    if(head->data == key){ // If head node is to be deleted
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node* temp = head;
    while(temp->next != NULL && temp->next->data != key) // Traversing till the key or end of linked list
        temp = temp->next;
    if(temp->next == NULL) // If key not found
        return head;
    struct node* del_node = temp->next;
    temp->next = temp->next->next; // Removing the node from linked list
    free(del_node);
    return head;
}

// Function to print all values in a linked list
void printList(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program
int main(){
    struct node* head = NULL;

    // Inserting values at the beginning of the linked list
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);
    printf("Linked list after inserting values at the beginning: ");
    printList(head);
    printf("\n");

    // Inserting values at the end of the linked list
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    printf("Linked list after inserting values at the end: ");
    printList(head);
    printf("\n");

    // Deleting a node from the linked list
    head = deleteNode(head, 30);
    printf("Linked list after deleting 30: ");
    printList(head);
    printf("\n");

    // Deleting a node from the linked list
    head = deleteNode(head, 50);
    printf("Linked list after deleting 50: ");
    printList(head);
    printf("\n");

    return 0;
}