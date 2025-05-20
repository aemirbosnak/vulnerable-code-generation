//FormAI DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insertAtStart(struct Node** headRef, int newData){
    //Create a new node and allocate memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    //Assign the data to the new node
    newNode->data = newData;
    
    //Set the next of the new node to the current head
    newNode->next = *headRef;
    
    //Set the head to the new node
    *headRef = newNode;
}

void insertAtEnd(struct Node** headRef, int newData){
    //Create a new node and allocate memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    //Assign the data to the new node
    newNode->data = newData;
    
    //Set the next of the new node to NULL
    newNode->next = NULL;
    
    //If the linked list is empty, set the new node as the head
    if(*headRef == NULL){
        *headRef = newNode;
        return;
    }
    
    //Traverse to the last node
    struct Node* lastNode = *headRef;
    while(lastNode->next != NULL){
        lastNode = lastNode->next;
    }
    
    //Set the next of the last node to the new node
    lastNode->next = newNode;
}

void deleteNode(struct Node** headRef, int key){
    //If the head is the node to be deleted
    if(*headRef != NULL && (*headRef)->data == key){
        struct Node* temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        printf("Node with data = %d deleted successfully!\n", key);
        return;
    }
    
    //Traverse to the node to be deleted
    struct Node* currentNode = *headRef;
    struct Node* prevNode = NULL;
    while(currentNode != NULL && currentNode->data != key){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    
    //If the node is not found
    if(currentNode == NULL){
        printf("Node with data = %d not found in the linked list.\n", key);
        return;
    }
    
    //Delete the node
    prevNode->next = currentNode->next;
    free(currentNode);
    printf("Node with data = %d deleted successfully!\n", key);
    return;
}

void displayList(struct Node* head){
    //Traverse and print the list
    printf("The linked list is: ");
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    
    //Insert nodes at the start
    insertAtStart(&head, 5);
    insertAtStart(&head, 10);
    insertAtStart(&head, 15);
    displayList(head);
    
    //Insert nodes at the end
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    displayList(head);
    
    //Delete a node
    deleteNode(&head, 10);
    displayList(head);
    
    //Delete a non-existent node
    deleteNode(&head, 100);
    
    return 0;
}