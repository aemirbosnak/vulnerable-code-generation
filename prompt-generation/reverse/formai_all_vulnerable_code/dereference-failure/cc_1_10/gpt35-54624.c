//FormAI DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

//Structure definition of a Node in the Linked List
struct Node{
    int data;
    struct Node* next;
};

//Function to traverse the Linked List
void traverse(struct Node* head){
    printf("Linked List: ");
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Function to insert a node at the beginning of a Linked List
struct Node* insertAtBeginning(struct Node* head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

//Function to insert a node at the end of a Linked List
struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

//Function to insert a node at a particular position of a Linked List
struct Node* insertAtPosition(struct Node* head, int data, int position){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = head;
    for(int i=1;i<position-1;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

//Function to delete a node from the head of a Linked List
struct Node* deleteFromBeginning(struct Node* head){
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

//Function to delete a node from the end of a Linked List
struct Node* deleteFromEnd(struct Node* head){
    struct Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

//Function to delete a node from a particular position of a Linked List
struct Node* deleteFromPosition(struct Node* head, int position){
    struct Node* temp = head;
    for(int i=1;i<position-1;i++){
        temp = temp->next;
    }
    struct Node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    return head;
}

int main(){
    struct Node* head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 4);
    head = insertAtBeginning(head, 0);
    head = insertAtPosition(head, 3, 3);
    traverse(head);
    head = deleteFromBeginning(head);
    head = deleteFromEnd(head);
    head = deleteFromPosition(head, 3);
    traverse(head);
    return 0;
}