//FormAI DATASET v1.0 Category: Linked list operations ; Style: careful
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **headRef, int data){
    Node* newHead = createNode(data);
    newHead->next = *headRef;
    *headRef = newHead;
}

void insertAtEnd(Node **headRef, int data){
    Node* newTail = createNode(data);
    if(*headRef == NULL){
        *headRef = newTail;
        return;
    }
    Node* temp = *headRef;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newTail;
}

int getNodeCount(Node *head) { 
    int count = 0;
    Node *temp = head; 
    while(temp != NULL) { 
        count++; 
        temp = temp->next; 
    } 
    return count; 
} 

void insertAtPosition(Node **headRef, int data, int position){
    if(position <= 0){
        printf("Invalid position");
        return;
    }
    if(position == 1){
        insertAtBeginning(headRef, data);
        return;
    }
    int count = getNodeCount(*headRef);
    if(position > count+1){
        printf("Invalid position");
        return;
    }
    Node* newNode = createNode(data);
    Node* currentNode = *headRef;
    Node* previousNode;
    int currentPosition = 1;
    while(currentPosition != position){
        previousNode = currentNode;
        currentNode = currentNode->next;
        currentPosition++;
    }
    previousNode->next = newNode;
    newNode->next = currentNode;
}

void deleteAtBeginning(Node **headRef){
    if(*headRef == NULL){
        printf("List is empty");
        return;
    }
    Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
}

void deleteAtEnd(Node **headRef){
    if(*headRef == NULL){
        printf("List is empty");
        return;
    }
    if((*headRef)->next == NULL){
        free(*headRef);
        *headRef = NULL;
        return;
    }
    Node* temp = *headRef;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(Node **headRef, int position){
    if(position <= 0){
        printf("Invalid position");
        return;
    }
    if(position == 1){
        deleteAtBeginning(headRef);
        return;
    }
    int count = getNodeCount(*headRef);
    if(position > count){
        printf("Invalid position");
        return;
    }
    Node* currentNode = *headRef;
    Node* previousNode;
    int currentPosition = 1;
    while(currentPosition != position){
        previousNode = currentNode;
        currentNode = currentNode->next;
        currentPosition++;
    }
    previousNode->next = currentNode->next;
    free(currentNode);
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtPosition(&head, 40, 3);
    printf("Before deletion:\n");
    printList(head);
    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    deleteAtPosition(&head, 2);
    printf("After deletion:\n");
    printList(head);
    return 0;
}