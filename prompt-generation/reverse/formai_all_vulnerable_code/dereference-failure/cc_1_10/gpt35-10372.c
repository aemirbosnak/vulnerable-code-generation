//FormAI DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node* next; 
};

typedef struct {
    struct node* head; 
} linked_list;

void initialize(linked_list *list) {
    list->head = NULL; 
}

void insert(linked_list* list, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void delete(linked_list* list, int data) {
    struct node* curr_node = list->head;
    struct node* prev_node = NULL;

    while(curr_node != NULL) {
        if(curr_node->data == data) {
            if(prev_node == NULL) {
                list->head = curr_node->next;
            } else {
                prev_node->next = curr_node->next;
            }
            free(curr_node);
            return;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
}

void print_list(linked_list* list) {
    struct node* curr_node = list->head;

    while(curr_node != NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }

    printf("\n");
}

void destroy(linked_list* list) {
    struct node* curr_node = list->head;

    while(curr_node != NULL) {
        struct node* next_node = curr_node->next;
        free(curr_node); 
        curr_node = next_node;
    }

    list->head = NULL;
}

int main() {
    linked_list list; 
    int i;

    initialize(&list);

    for(i = 0; i < 10; i++) {
        insert(&list, i);
    }

    delete(&list, 5);
    delete(&list, 9);

    print_list(&list);

    destroy(&list);

    return 0;
}