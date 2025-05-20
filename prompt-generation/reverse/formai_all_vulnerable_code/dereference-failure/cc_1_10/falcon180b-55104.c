//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node* next;
};

//Function to create a new node
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Function to print the linked list
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Function to add a node at the beginning of the linked list
void push(struct Node** head, int data){
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

//Function to add a node at the end of the linked list
void append(struct Node** head, int data){
    struct Node* node = newNode(data);
    struct Node* temp = *head;
    if(*head == NULL){
        node->next = NULL;
        *head = node;
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = node;
}

//Function to add a node after a given position in the linked list
void insertAfter(struct Node* prevNode, int data){
    if(prevNode == NULL){
        printf("The given previous node cannot be NULL");
        return;
    }
    struct Node* node = newNode(data);
    node->next = prevNode->next;
    prevNode->next = node;
}

//Function to delete a node from the linked list
void deleteNode(struct Node** head, int key){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if(temp!= NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

//Main function
int main(){
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 3);
    push(&head, 7);
    push(&head, 1);
    printList(head);
    append(&head, 9);
    printList(head);
    insertAfter(head->next, 4);
    printList(head);
    deleteNode(&head, 7);
    printList(head);
    return 0;
}