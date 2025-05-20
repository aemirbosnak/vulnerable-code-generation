//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertBegining(struct Node** head_ref, int new_data){
    struct Node* new_node = createNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertEnd(struct Node** head_ref, int new_data){
    struct Node* new_node = createNode(new_data);
    struct Node* temp = *head_ref;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertInBetween(struct Node** head_ref, int data_to_insert_before, int new_data){
    struct Node* new_node = createNode(new_data);
    struct Node* temp = *head_ref;
    struct Node* temp_to_insert_before = *head_ref;
    while(temp!= NULL && temp->data!= data_to_insert_before){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Data to insert before not found!\n");
    }
    else{
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void deleteNode(struct Node** head_ref, int data_to_delete){
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    while(temp!= NULL && temp->data!= data_to_delete){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Data to delete not found!\n");
    }
    else{
        prev->next = temp->next;
        free(temp);
    }
}

void deleteList(struct Node** head_ref){
    struct Node* temp = *head_ref;
    while(temp!= NULL){
        struct Node* temp_to_delete = temp;
        temp = temp->next;
        free(temp_to_delete);
    }
    *head_ref = NULL;
}

void main(){
    struct Node* head = NULL;
    insertBegining(&head, 10);
    insertBegining(&head, 20);
    insertBegining(&head, 30);
    insertBegining(&head, 40);
    insertBegining(&head, 50);
    insertEnd(&head, 60);
    insertEnd(&head, 70);
    printList(head);
    printf("Deleted 40\n");
    deleteNode(&head, 40);
    printList(head);
    printf("Deleted Entire List\n");
    deleteList(&head);
}