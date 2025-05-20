//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Node structure definition
struct Node{
    int data;
    struct Node* next;
};

//Function prototypes
void addNode(struct Node** head, int data);
void deleteNode(struct Node** head, int data);
void printList(struct Node* head);
void reverseList(struct Node** head);
void sortList(struct Node* head);

int main(){
    struct Node* head = NULL;

    //Add nodes to the list
    addNode(&head, 5);
    addNode(&head, 3);
    addNode(&head, 8);
    addNode(&head, 2);
    addNode(&head, 1);

    //Print the list
    printf("Original List: ");
    printList(head);

    //Delete a node from the list
    deleteNode(&head, 2);

    //Print the list after deletion
    printf("\nList after deleting node 2: ");
    printList(head);

    //Reverse the list
    reverseList(&head);

    //Print the reversed list
    printf("\nReversed List: ");
    printList(head);

    //Sort the list
    sortList(head);

    //Print the sorted list
    printf("\nSorted List: ");
    printList(head);

    return 0;
}

//Function to add a node to the list
void addNode(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function to delete a node from the list
void deleteNode(struct Node** head, int data){
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    prev->next = temp->next;
    free(temp);
}

//Function to print the list
void printList(struct Node* head){
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Function to reverse the list
void reverseList(struct Node** head){
    struct Node* prev = NULL;
    struct Node* curr = *head;

    //Reverse the list
    while(curr!= NULL){
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //Update head pointer
    *head = prev;
}

//Function to sort the list
void sortList(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL && temp->next!= NULL){
        if(temp->data > temp->next->data){
            int tempData = temp->data;
            temp->data = temp->next->data;
            temp->next->data = tempData;
        }
        temp = temp->next;
    }
}