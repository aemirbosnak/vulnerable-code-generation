//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* data;
    struct node* next;
    struct node* prev;
} node;

typedef struct list {
    node* head;
    node* tail;
    int size;
} list;

list* create_list(void) {
    list* new_list = (list*)malloc(sizeof(list));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

void destroy_list(list* lst) {
    node* current = lst->head;
    while (current != NULL) {
        node* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(lst);
}

void push_back(list* lst, char* data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = strdup(data);
    new_node->next = NULL;
    if (lst->tail == NULL) {
        lst->head = new_node;
        lst->tail = new_node;
    } else {
        lst->tail->next = new_node;
        lst->tail = new_node;
    }
    lst->size++;
}

void print_list(list* lst) {
    node* current = lst->head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int reverse_list_recursive(list* lst, node* current) {
    if (current == NULL) {
        return 0;
    }
    reverse_list_recursive(lst, current->next);
    if (current == lst->head) {
        lst->tail = current;
    } else {
        current->next->prev = current;
    }
    current->next = current->prev;
    current->prev = NULL;
    lst->head = current;
    return 0;
}

int main(void) {
    list* lst = create_list();
    push_back(lst, "Hello");
    push_back(lst, "World");
    push_back(lst, "!");
    print_list(lst);
    reverse_list_recursive(lst, lst->head);
    print_list(lst);
    destroy_list(lst);
    return 0;
}