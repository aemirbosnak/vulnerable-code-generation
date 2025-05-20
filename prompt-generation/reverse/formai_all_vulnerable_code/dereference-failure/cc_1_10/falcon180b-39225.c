//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

// Define node structure
struct node{
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void push(struct node** head_ref, int new_data){
    struct node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a node at the end of the list
void append(struct node** head_ref, int new_data){
    struct node* new_node = newNode(new_data);
    struct node* last = *head_ref;
    if(*head_ref == NULL){
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }
    while(last->next!= NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

// Function to insert a node at a specific position
void insertNode(struct node* prev_node, int new_data){
    if(prev_node == NULL){
        printf("The given previous node cannot be NULL");
        return;
    }
    struct node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the list
void deleteNode(struct node **head_ref, struct node* del){
    struct node* temp = *head_ref;
    if(temp == del){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp!= del){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Node not found in the list");
        return;
    }
    temp->next = temp->next->next;
    free(del);
}

// Function to print the list
void printList(struct node* node){
    while(node!= NULL){
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main(){
    struct node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    printf("Created Linked List: ");
    printList(head);
    append(&head, 50);
    printf("\nLinked List after appending 50: ");
    printList(head);
    insertNode(head->next, 25);
    printf("\nLinked List after inserting 25 at position 2: ");
    printList(head);
    deleteNode(&head, head->next->next);
    printf("\nLinked List after deleting 20: ");
    printList(head);
    return 0;
}