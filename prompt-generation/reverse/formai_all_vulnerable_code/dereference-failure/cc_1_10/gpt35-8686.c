//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include<stdio.h>
#include<stdlib.h>

// Defining a node structure
struct Node{
    int data;
    struct Node* next;
};

// Function to traverse and print a linked list
void printList(struct Node* n){
    while(n!=NULL){
        printf("%d ",n->data);
        n = n->next;
    }
}

// Function to add a node at the end of linked list
void addNode(struct Node** head_ref, int value){
    // Creating a dynamic node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Storing the value in the new node
    new_node->data = value;
    new_node->next = NULL;
    // If the linked list is empty, make the new node as head
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    // Traversing the linked list to reach at the end
    struct Node* last_node = *head_ref;
    while(last_node->next != NULL){
        last_node = last_node->next;
    }
    // Assigning the new node at the end of linked list
    last_node->next = new_node;
}

// Function to delete a node from linked list
void deleteNode(struct Node** head_ref, int key){
    // Store head node
    struct Node* temp = *head_ref, *prev;
    // If head node itself holds the key to be deleted
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Searching for the key to be deleted
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    // If key was not present in linked list
    if(temp == NULL){
        printf("\nKey not found in linked list\n");
        return;
    }
    // Removing the node with the key
    prev->next = temp->next;
    free(temp);
}

// Function to update a node value in linked list
void updateNode(struct Node** head_ref, int old_value, int new_value){
    // Traversing the linked list to search the node with old value
    struct Node* temp = *head_ref;
    while(temp != NULL){
        if(temp->data == old_value){
            temp->data = new_value;
            return;
        }
        temp = temp->next;
    }
    // If node with old value was not found
    printf("\nNode not found in linked list\n");
}

int main(){
    // Creating an empty linked list
    struct Node* head = NULL;

    // Adding some nodes in linked list
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);

    // Printing the linked list
    printf("\nLinked List:\n");
    printList(head);

    // Deleting a node with key=30
    printf("\n\nAfter deleting a node with key=30:\n");
    deleteNode(&head, 30);
    printList(head);

    // Updating a node value with old_value=20 and new_value=25
    printf("\n\nAfter updating a node value:\n");
    updateNode(&head, 20, 25);
    printList(head);

    // Adding some more nodes in linked list
    printf("\n\nAfter adding some nodes:\n");
    addNode(&head, 60);
    addNode(&head, 70);
    printList(head);
    return 0;
}