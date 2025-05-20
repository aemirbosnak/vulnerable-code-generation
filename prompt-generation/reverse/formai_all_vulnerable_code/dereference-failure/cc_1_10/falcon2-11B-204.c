//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

struct linked_list {
    struct node* head;
};

struct node* add_node(int value, struct linked_list* list) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    return list->head;
}

struct node* delete_node(int value, struct linked_list* list) {
    struct node* current = list->head;
    struct node* previous = NULL;

    while (current!= NULL && current->data!= value) {
        previous = current;
        current = current->next;
    }

    if (current!= NULL) {
        previous->next = current->next;
        free(current);
    }

    return list->head;
}

void display_list(struct linked_list* list) {
    struct node* current = list->head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct node* search_list(int value, struct linked_list* list) {
    struct node* current = list->head;

    while (current!= NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

struct node* reverse_list(struct linked_list* list) {
    struct node* prev = NULL;
    struct node* current = list->head;
    struct node* next = NULL;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head = prev;
    return list->head;
}

int main() {
    struct linked_list list;
    list.head = NULL;

    add_node(1, &list);
    add_node(2, &list);
    add_node(3, &list);

    printf("Original List: ");
    display_list(&list);

    delete_node(2, &list);

    printf("\nModified List: ");
    display_list(&list);

    struct node* found_node = search_list(2, &list);
    if (found_node!= NULL) {
        printf("Node with value 2 found!\n");
    } else {
        printf("Node with value 2 not found\n");
    }

    reverse_list(&list);

    printf("\nReversed List: ");
    display_list(&list);

    delete_node(3, &list);

    printf("\nFinal List: ");
    display_list(&list);

    return 0;
}