//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* create_node(int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(node** head_ref, int new_data){
    node* new_node = create_node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print_list(node* node){
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
}

int main(){
    node* head = NULL;
    int choice,data;

    while(1){
        printf("\n\n1.Push\n2.Print\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                push(&head,data);
                break;
            case 2:
                printf("List: ");
                print_list(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}