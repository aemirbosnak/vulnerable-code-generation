//FormAI DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

// Insert Node at the beginning of the linked list
void insertAtBeginning(struct node **head, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Delete Node from the linked list
void deleteNode(struct node **head, int key){
    struct node* prev = NULL;
    struct node* current = *head;
    
    // If head node itself holds the key to be delete
    if(current != NULL && current->data == key){
        *head = current->next;
        free(current);
        return;
    }
    
    // Search for the key to be deleted, keep track of the     
    // previous node as well
    while(current != NULL && current->data != key){
        prev = current;
        current = current->next;
    }
    
    // If key was not present in linked list
    if(current == NULL){
        return;
    }
    
    // Unlink the node from the linked list
    prev->next = current->next;
    free(current);
}

// Print the Linked List
void printList(struct node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    struct node* head = NULL;
    
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);
    
    printf("Original Linked List : ");
    printList(head);
    
    deleteNode(&head, 5); //To delete node with data value 5
    printf("\nLinked List after Deletion : ");
    printList(head);
    
    deleteNode(&head, 1); //To delete node with data value 1
    printf("\nLinked List after Deletion : ");
    printList(head);
    
    return 0;
}