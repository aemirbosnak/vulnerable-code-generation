//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        printf("Memory Error!");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(node** head_ref, int data){
    node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("%d pushed to stack\n", data);
}

int pop(node** head_ref){
    node* temp = *head_ref;
    int data = temp->data;
    temp = temp->next;
    free(temp);
    *head_ref = temp;
    printf("%d popped from stack\n", data);
    return data;
}

void traverse(node* head){
    int count = 0;
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
        count++;
        if(count == 10){
            printf("\n");
            count = 0;
        }
    }
}

int main(){
    node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    traverse(head);
    printf("\nStack after popping an element:\n");
    pop(&head);
    traverse(head);
    return 0;
}