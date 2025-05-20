//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node{
    int data;
    struct node *next;
};

struct node *createNode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node *insertNode(struct node *head, int data){
    struct node *newnode = createNode(data);
    if(head == NULL){
        head = newnode;
    }
    else{
        struct node *temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

struct node *deleteNode(struct node *head, int key){
    struct node *temp = head;
    struct node *prev = NULL;
    if(temp!= NULL && temp->data == key){
        head = temp->next;
        free(temp);
        return head;
    }
    while(temp!= NULL && temp->data!= key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

void printList(struct node *head){
    struct node *temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);
    printf("Original List:\n");
    printList(head);
    head = deleteNode(head, 3);
    printf("List after deleting 3:\n");
    printList(head);
    head = deleteNode(head, 1);
    printf("List after deleting 1:\n");
    printList(head);
    head = deleteNode(head, 5);
    printf("List after deleting 5:\n");
    printList(head);
    head = deleteNode(head, 2);
    printf("List after deleting 2:\n");
    printList(head);
    head = deleteNode(head, 4);
    printf("List after deleting 4:\n");
    printList(head);
    return 0;
}