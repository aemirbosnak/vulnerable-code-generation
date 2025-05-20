//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: active
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void append(struct node **head, int data);
void prepend(struct node **head, int data);
void delete(struct node **head, int data);
void print(struct node *head);

int main(){
    struct node *head = NULL;

    append(&head, 10);
    prepend(&head, 20);
    prepend(&head, 30);
    append(&head, 40);
    print(head);

    delete(&head, 30);
    print(head);

    delete(&head, 10);
    print(head);

    delete(&head, 20);
    print(head);

    delete(&head, 40);
    print(head);

    return 0;
}

void append(struct node **head, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    struct node *temp = *head;

    while(temp->next!= NULL){
        temp = temp->next;
    }

    temp->next = new_node;
}

void prepend(struct node **head, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;

    *head = new_node;
}

void delete(struct node **head, int data){
    struct node *temp = *head;

    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data){
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    struct node *prev = temp->next;
    free(temp);
    temp = prev;
}

void print(struct node *head){
    struct node *temp = head;

    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}