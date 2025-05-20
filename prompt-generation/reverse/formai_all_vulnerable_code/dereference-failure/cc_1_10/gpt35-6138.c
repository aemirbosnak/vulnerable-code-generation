//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* create_node(int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node_end(Node **head, int data){
    Node *new_node = create_node(data);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    Node *curr_node = *head;
    while(curr_node->next != NULL){
        curr_node = curr_node->next;
    }
    curr_node->next = new_node;
}

void add_node_beginning(Node **head, int data){
    Node *new_node = create_node(data);
    if(*head == NULL){
        *head = new_node;
        return;
    }
    new_node->next = *head;
    *head = new_node;
}

void add_node_at_index(Node **head, int data, int index){
    if(index == 0){
        add_node_beginning(head, data);
        return;
    }
    Node *new_node = create_node(data);
    Node *curr_node = *head;
    int i = 0;
    while(curr_node != NULL && i < index-1){
        curr_node = curr_node->next;
        i++;
    }
    if(curr_node == NULL){
        printf("Index out of bounds, cannot add node.");
        return;
    }
    new_node->next = curr_node->next;
    curr_node->next = new_node;
}

void delete_node(Node **head, int data){
    Node *curr_node = *head;
    Node *prev_node = NULL;
    while(curr_node != NULL && curr_node->data != data){
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    if(curr_node == NULL){
        printf("Node with data %d not found in the list.", data);
        return;
    }
    if(prev_node == NULL){
        *head = curr_node->next;
    }
    else{
        prev_node->next = curr_node->next;
    }
    free(curr_node);
}

void print_list(Node *head){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    Node *curr_node = head;
    while(curr_node != NULL){
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

int main(){
    Node *head = NULL;
    add_node_end(&head, 1);
    add_node_end(&head, 2);
    add_node_end(&head, 3);
    add_node_beginning(&head, -1);
    add_node_at_index(&head, 0, 0);
    add_node_at_index(&head, 4, 5);
    print_list(head);
    delete_node(&head, 0);
    delete_node(&head, 4);
    delete_node(&head, 3);
    print_list(head);
    return 0;
}