//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (head == NULL) {
        head = new_node;
        return;
    }
    
    struct node *curr = head;
    while (curr->next!= NULL) {
        curr = curr->next;
    }
    
    curr->next = new_node;
}

void delete_node(int data) {
    struct node *curr = head;
    while (curr!= NULL && curr->data!= data) {
        curr = curr->next;
    }
    
    if (curr == NULL) {
        return;
    }
    
    if (curr == head) {
        struct node *temp = curr->next;
        free(curr);
        head = temp;
        return;
    }
    
    struct node *prev = curr->next;
    curr->next = curr->next->next;
    free(prev);
}

void print_list() {
    struct node *curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    insert_node(1);
    insert_node(2);
    insert_node(3);
    insert_node(4);
    insert_node(5);
    insert_node(6);
    print_list();
    
    delete_node(3);
    print_list();
    
    delete_node(5);
    print_list();
    
    delete_node(4);
    print_list();
    
    return 0;
}