//FormAI DATASET v1.0 Category: Memory management ; Style: genious
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
}typedef node;

node* head = NULL;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(int data){
    if(head == NULL){
        head = createNode(data);
    }
    else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = createNode(data);
    }
}

void deleteNode(int data){
    if(head == NULL){
        printf("List is empty\n");
    }
    else if(head->data == data){
        node* temp = head;
        head = head->next;
        free(temp);
    }
    else{
        node* temp = head;
        node* prev = NULL;
        while(temp != NULL && temp->data != data){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("%d not found in the list\n", data);
        }
        else{
            prev->next = temp->next;
            free(temp);
        }
    }
}

void display(){
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        node* temp = head;
        printf("List:\n");
        while(temp != NULL){
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    display();
    deleteNode(1);
    display();
    deleteNode(3);
    display();
    insertNode(5);
    display();
    return 0;
}