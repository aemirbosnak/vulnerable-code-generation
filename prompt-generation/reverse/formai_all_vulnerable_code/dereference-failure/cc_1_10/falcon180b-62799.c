//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: active
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_at_end(struct node** head, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL){
        new_node->next = NULL;
        *head = new_node;
    }
    else{
        struct node* temp = *head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }
}

void insert_at_beginning(struct node** head, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;

    *head = new_node;
}

void delete_node(struct node** head, int data){
    struct node* temp = *head;
    struct node* prev = NULL;

    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void print_list(struct node* head){
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    struct node* head = NULL;

    insert_at_end(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_end(&head, 30);
    insert_at_beginning(&head, 40);

    printf("Original list:\n");
    print_list(head);

    printf("\nAfter deleting node with data 20:\n");
    delete_node(&head, 20);
    print_list(head);

    printf("\nAfter deleting node with data 10:\n");
    delete_node(&head, 10);
    print_list(head);

    return 0;
}