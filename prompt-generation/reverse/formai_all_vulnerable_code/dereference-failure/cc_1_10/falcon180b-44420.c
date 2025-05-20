//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

//Node structure for linked list
typedef struct node{
    int data;
    struct node* next;
}Node;

//Linked list structure
typedef struct list{
    Node* head;
}List;

//Function prototypes
void push(List* l, int data);
int pop(List* l);
int peek(List* l);
int isEmpty(List* l);
int printList(List* l);

//Main function
int main(){
    List l;
    l.head = NULL;

    push(&l, 1);
    push(&l, 2);
    push(&l, 3);

    printf("Original List: ");
    printList(&l);

    int popped = pop(&l);
    printf("\nPopped element: %d\n", popped);

    printf("List after popping: ");
    printList(&l);

    int peeked = peek(&l);
    printf("\nPeeked element: %d\n", peeked);

    return 0;
}

//Function definitions
void push(List* l, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(l->head == NULL){
        l->head = newNode;
    }
    else{
        Node* temp = l->head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int pop(List* l){
    if(isEmpty(l)){
        return -1;
    }
    else{
        Node* temp = l->head;
        int popped = temp->data;
        l->head = temp->next;
        free(temp);
        return popped;
    }
}

int peek(List* l){
    if(isEmpty(l)){
        return -1;
    }
    else{
        return l->head->data;
    }
}

int isEmpty(List* l){
    if(l->head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int printList(List* l){
    Node* temp = l->head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}