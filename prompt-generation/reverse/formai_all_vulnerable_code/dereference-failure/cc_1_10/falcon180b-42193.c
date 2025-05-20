//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

typedef struct node{
    int data;
    struct node* next;
} node;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(node* head, int data){
    node* newNode = createNode(data);
    newNode->next = head->next;
    head->next = newNode;
}

void delete(node* head, int data){
    node* temp = head->next;
    while(temp!= NULL && temp->data!= data){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Element not found\n");
        return;
    }
    node* del = temp;
    head->next = temp->next;
    free(del);
}

void search(node* head, int data){
    node* temp = head->next;
    while(temp!= NULL){
        if(temp->data == data){
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

int main(){
    node* head = NULL;
    int choice, data;
    while(1){
        printf("Enter your choice:\n1. Insert\n2. Delete\n3. Search\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be inserted:\n");
                scanf("%d", &data);
                insert(head, data);
                break;
            case 2:
                printf("Enter the element to be deleted:\n");
                scanf("%d", &data);
                delete(head, data);
                break;
            case 3:
                printf("Enter the element to be searched:\n");
                scanf("%d", &data);
                search(head, data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}