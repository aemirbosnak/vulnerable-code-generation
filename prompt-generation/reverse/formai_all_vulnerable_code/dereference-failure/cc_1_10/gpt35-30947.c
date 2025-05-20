//FormAI DATASET v1.0 Category: Data mining ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void printList(struct node* head);

void recursiveDataMining(struct node* currNode){
    if(currNode != NULL){
        printf("%d->", currNode -> data);
        recursiveDataMining(currNode -> next);
    }
}

int main(){
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    head -> data = 1;
    head -> next = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = NULL;

    printf("Printing linked list using iterative method: ");
    printList(head);

    printf("\nPrinting linked list using recursive method: ");
    recursiveDataMining(head);

    return 0;
}

void printList(struct node* head){
    while(head != NULL){
        printf("%d->", head -> data);
        head = head -> next;
    }
}