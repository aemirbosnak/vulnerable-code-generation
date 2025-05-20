//Falcon-180B DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* head;
} linked_list;

linked_list* create_linked_list() {
    linked_list* list = (linked_list*) malloc(sizeof(linked_list));
    if (list == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}

void add_node(linked_list* list, int data) {
    node* new_node = (node*) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list(linked_list* list) {
    node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_node(linked_list* list, int data) {
    node* temp = list->head;
    node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Node not found.\n");
    } else {
        if (prev == NULL) {
            list->head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}

int main() {
    linked_list* list = create_linked_list();
    add_node(list, 10);
    add_node(list, 20);
    add_node(list, 30);
    add_node(list, 40);
    print_list(list);
    delete_node(list, 20);
    delete_node(list, 10);
    print_list(list);
    delete_node(list, 30);
    print_list(list);
    delete_node(list, 40);
    print_list(list);
    free(list);
    return 0;
}