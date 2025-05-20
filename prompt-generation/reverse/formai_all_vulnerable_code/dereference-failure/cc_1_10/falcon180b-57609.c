//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Defining the node structure
typedef struct node{
    int data;
    struct node* next;
}Node;

//Function to create a new node
Node* newNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        printf("Memory error\n");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

//Function to print the linked list
void printList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Function to add an element at the end of the linked list
void push(Node** head_ref, int new_data){
    Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//Function to add an element at the beginning of the linked list
void push2(Node** head_ref, int new_data){
    Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//Function to remove an element from the linked list
void pop(Node** head_ref){
    Node* temp = (*head_ref);
    (*head_ref) = (*head_ref)->next;
    free(temp);
}

//Function to reverse the linked list
void reverseList(Node** head_ref){
    Node* prev = NULL;
    Node* current = (*head_ref);
    while(current!= NULL){
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*head_ref) = prev;
}

//Function to sort the linked list
void sortList(Node** head_ref){
    Node* current = (*head_ref);
    while(current!= NULL && current->next!= NULL){
        if(current->data > current->next->data){
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
        }
        current = current->next;
    }
}

//Main function
int main(){
    Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);

    printf("Original list:\n");
    printList(head);

    reverseList(&head);
    printf("List after reversing:\n");
    printList(head);

    sortList(&head);
    printf("List after sorting:\n");
    printList(head);

    pop(&head);
    printf("List after removing first element:\n");
    printList(head);

    return 0;
}