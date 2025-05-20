//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int size;
    struct node* next;
} node;

typedef struct {
    node* head;
} linked_list;

linked_list* create_linked_list() {
    linked_list* l = (linked_list*)malloc(sizeof(linked_list));
    if (l == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    l->head = NULL;
    return l;
}

void add_node(linked_list* l, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->size = 1;
    new_node->next = NULL;
    if (l->head == NULL) {
        l->head = new_node;
    } else {
        node* temp = l->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Node added with data %d\n", data);
}

void delete_node(linked_list* l, int data) {
    node* temp = l->head;
    while (temp!= NULL) {
        if (temp->data == data) {
            node* prev_node = temp;
            temp = temp->next;
            free(prev_node);
            l->head = temp;
            printf("Node deleted with data %d\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("Node not found with data %d\n", data);
}

void print_linked_list(linked_list* l) {
    node* temp = l->head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    linked_list* l = create_linked_list();
    add_node(l, 1);
    add_node(l, 2);
    add_node(l, 3);
    print_linked_list(l);
    delete_node(l, 2);
    print_linked_list(l);
    delete_node(l, 1);
    print_linked_list(l);
    delete_node(l, 3);
    print_linked_list(l);
    free(l);
    return 0;
}