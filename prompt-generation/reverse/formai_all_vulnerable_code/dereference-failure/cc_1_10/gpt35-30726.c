//FormAI DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create_node(int data){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

void traverse(struct node* head){
    if(head == NULL){
        printf("Linked list is empty\n");
        return;
    }
    struct node* current = head;
    while(current != NULL){
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

void insert_at_beginning(struct node** head, int data){
    struct node* new_node = create_node(data);
    new_node -> next = *head;
    *head = new_node;
    printf("%d inserted at the beginning\n", data);
}

void insert_at_end(struct node** head, int data){
    struct node* new_node = create_node(data);
    if(*head == NULL){
        *head = new_node;
        printf("%d inserted at the end\n", data);
        return;
    }
    struct node* current = *head;
    while(current -> next != NULL){
        current = current -> next;
    }
    current -> next = new_node;
    printf("%d inserted at the end\n", data);
}

void insert_at_index(struct node** head, int data, int index){
    if(index == 0){
        insert_at_beginning(head, data);
        return;
    }
    struct node* new_node = create_node(data);
    struct node* current = *head;
    int curr_index = 0;
    while(current != NULL && curr_index < index-1){
        current = current -> next;
        curr_index++;
    }
    if(current == NULL){
        printf("Index out of bounds\n");
        return;
    }
    new_node -> next = current -> next;
    current -> next = new_node;
    printf("%d inserted at index %d\n", data, index);
}

void delete_at_beginning(struct node** head){
    if(*head == NULL){
        printf("Linked list is empty\n");
        return;
    }
    struct node* current = *head;
    *head = current -> next;
    free(current);
    printf("Node at the beginning deleted\n");
}

void delete_at_end(struct node** head){
    if(*head == NULL){
        printf("Linked list is empty\n");
        return;
    }
    struct node* current = *head;
    struct node* prev = current;
    while(current -> next != NULL){
        prev = current;
        current = current -> next;
    }
    if(current == *head){
        *head = NULL;
    }else{
        prev -> next = NULL;
    }
    free(current);
    printf("Node at the end deleted\n");
}

void delete_at_index(struct node** head, int index){
    if(*head == NULL){
        printf("Linked list is empty\n");
        return;
    }
    if(index == 0){
        delete_at_beginning(head);
        return;
    }
    struct node* current = *head;
    struct node* prev = current;
    int curr_index = 0;
    while(current != NULL && curr_index < index){
        prev = current;
        current = current -> next;
        curr_index++;
    }
    if(current == NULL){
        printf("Index out of bounds\n");
        return;
    }
    prev -> next = current -> next;
    free(current);
    printf("Node at index %d deleted\n", index);
}

int main(){

    struct node* head = NULL;

    traverse(head);

    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 7);
    insert_at_end(&head, 10);
    insert_at_index(&head, 12, 2);
    insert_at_index(&head, 15, 1);

    traverse(head);

    delete_at_index(&head, 1);
    delete_at_beginning(&head);
    delete_at_end(&head);

    traverse(head);

    return 0;
}