//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

void push(node** head_ref, int new_data){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(){
    node* head = NULL;
    int choice, value;

    while(1){
        printf("Enter your choice:\n");
        printf("1. Push\n2. Print\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(&head, value);
                break;
            }
            case 2:{
                printList(head);
                break;
            }
            case 3:{
                exit(0);
            }
            default:{
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}