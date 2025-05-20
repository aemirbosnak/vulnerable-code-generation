//FormAI DATASET v1.0 Category: Linked list operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

/* Define a Node structure for the linked list */
typedef struct Node{
    int data;
    struct Node* next;
}Node;

/* Initialize the linked list by creating a head node */
Node* head = NULL;

/* Function to insert a node at the beginning of the linked list */
void insertAtBegin(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

/* Function to insert a node at the end of the linked list */
void insertAtEnd(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node* temp = head;
    if(temp==NULL){
        head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Function to delete the first node of the linked list */
void deleteAtBegin(){
    if(head==NULL){
        printf("List is Empty.\n");
        return;
    }
    Node* temp = head->next;
    free(head);
    head = temp;
}

/* Function to delete the last node of the linked list */
void deleteAtEnd(){
    if(head==NULL){
        printf("List is Empty.\n");
        return;
    }
    Node* temp1 = head;
    Node* temp2 = temp1->next;
    if(temp2==NULL){
        free(head);
        head = NULL;
        return;
    }
    while(temp2->next != NULL){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = NULL;
    free(temp2);
}

/* Function to display all the elements of the linked list */
void display(){
    if(head==NULL){
        printf("List is Empty.\n");
        return;
    }
    printf("Elements of the list are: ");
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Main function for testing the linked list operations */
int main(){
    int option, data;
    printf("Welcome to the Linked List Operations Program!\n");
    do{
        printf("Select an option:\n");
        printf("1 - Insert a node at the beginning of the list\n");
        printf("2 - Insert a node at the end of the list\n");
        printf("3 - Delete the first node of the list\n");
        printf("4 - Delete the last node of the list\n");
        printf("5 - Display all the elements of the list\n");
        printf("6 - Exit\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter the data to be inserted at the beginning of the list: ");
                scanf("%d", &data);
                insertAtBegin(data);
                break;
            case 2:
                printf("Enter the data to be inserted at the end of the list: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                deleteAtBegin();
                break;
            case 4:
                deleteAtEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }while(option!=6);
    return 0;
}