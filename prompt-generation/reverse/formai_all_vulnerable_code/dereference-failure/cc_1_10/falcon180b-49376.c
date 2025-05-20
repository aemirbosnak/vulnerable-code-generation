//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

//define node structure
struct node{
    int data;
    struct node* next;
};

void addNodeAtBeginning(struct node** head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void addNodeAtEnd(struct node** head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void addNodeAtPosition(struct node** head, int data, int position){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if(position == 1){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    for(int i=0; i<position-2 && temp!= NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNodeByValue(struct node** head, int value){
    struct node* temp = *head;

    if(temp!= NULL && temp->data == value){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= value){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Value not found\n");
        return;
    }

    struct node* prev = temp->next;
    temp->next = NULL;
    free(temp);

    if(prev == NULL){
        *head = NULL;
    }else{
        prev->next = NULL;
    }
}

void deleteNodeByPosition(struct node** head, int position){
    struct node* temp = *head;

    if(temp == NULL){
        printf("List is empty\n");
        return;
    }

    if(position == 1){
        *head = temp->next;
        free(temp);
        return;
    }

    for(int i=0; i<position-2 && temp!= NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Invalid position\n");
        return;
    }

    struct node* prev = temp->next;
    temp->next = NULL;
    free(temp);

    if(prev == NULL){
        *head = NULL;
    }else{
        prev->next = NULL;
    }
}

void displayList(struct node* head){
    printf("List:\n");
    struct node* temp = head;
    while(temp!= NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct node* head = NULL;

    //add nodes
    addNodeAtBeginning(&head, 5);
    addNodeAtBeginning(&head, 3);
    addNodeAtBeginning(&head, 1);

    displayList(head);

    addNodeAtEnd(&head, 7);

    displayList(head);

    addNodeAtPosition(&head, 4, 3);

    displayList(head);

    deleteNodeByValue(&head, 3);

    displayList(head);

    deleteNodeByPosition(&head, 2);

    displayList(head);

    return 0;
}