//FormAI DATASET v1.0 Category: Linked list operations ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;  //data of the node
    struct node* next;  //pointer to the next node
}Node;

//function to create a new node
Node* create_node(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to add a new node to the front of the list
void push(Node** headRef, int newData){
    Node* newNode = create_node(newData);
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

//function to add a new node after a specified node
void insert_after(Node* prevNode, int newData){
    if(prevNode == NULL){
        printf("Invalid node\n");
        return;
    }
    Node* newNode = create_node(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

//function to add a new node to the end of the list
void append(Node** headRef, int newData){
    Node* newNode = create_node(newData);
    Node* last = (*headRef);
    if(*headRef == NULL){
        *headRef = newNode;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
}

//function to delete a node with a specified value
void delete_node(Node** headRef, int key){
    Node* temp = *headRef, *prev;
    if(temp != NULL && temp->data == key){
        *headRef = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

//function to display the list
void display(Node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;  //initialize the list
    printf("Creating a linked list using C\n");
    printf("Adding nodes using the push, insert_after and append operations\n");
    push(&head, 5);
    push(&head, 3);
    insert_after(head->next, 4);
    append(&head, 7);
    printf("Displaying the list: ");
    display(head);
    printf("Deleting a node with value 4\n");
    delete_node(&head, 4);
    printf("Displaying the list: ");
    display(head);
    printf("Deleting a node with value 10\n");
    delete_node(&head, 10);
    printf("Displaying the list: ");
    display(head);
    return 0;
}