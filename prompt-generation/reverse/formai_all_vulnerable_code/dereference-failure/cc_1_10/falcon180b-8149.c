//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct node{
    int data;
    struct node* next;
};

struct node* create_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(struct node** head, int data){
    struct node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void delete_node(struct node** head, int data){
    struct node* temp = *head;
    struct node* prev = NULL;
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
        printf("Element not found!\n");
    else{
        if(prev == NULL)
            *head = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }
}

void display_list(struct node* head){
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;
    int choice, data;

    while(1){
        printf("1. Add element\n");
        printf("2. Delete element\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &data);
                add_node(&head, data);
                break;

            case 2:
                printf("Enter the element to be deleted: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;

            case 3:
                display_list(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}