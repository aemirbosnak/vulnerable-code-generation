//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct node* create_list(int data) {
    struct node* head = create_node(data);
    struct node* tail = head;

    return head;
}

void insert_at_beginning(struct node* list, int data) {
    struct node* new_node = create_node(data);

    new_node->next = list;
    list = new_node;
}

void insert_at_end(struct node* list, int data) {
    struct node* new_node = create_node(data);
    struct node* tail = list;

    while (tail->next!= NULL) {
        tail = tail->next;
    }
    tail->next = new_node;
}

void print_list(struct node* list) {
    struct node* temp = list;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* list = create_list(1);
    insert_at_beginning(list, 2);
    insert_at_end(list, 3);
    print_list(list);
    return 0;
}