//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
    int size;
};

struct list *create_list() {
    struct list *list = malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void destroy_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int add_to_list(struct list *list, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
    return 0;
}

int remove_from_list(struct list *list, int data) {
    struct node *current = list->head;
    struct node *previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (current == list->head) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            if (current == list->tail) {
                list->tail = previous;
            }
            free(current);
            list->size--;
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return -1;
}

int find_in_list(struct list *list, int data) {
    struct node *current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void print_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct list *list = create_list();
    add_to_list(list, 1);
    add_to_list(list, 2);
    add_to_list(list, 3);
    add_to_list(list, 4);
    add_to_list(list, 5);
    print_list(list);
    remove_from_list(list, 3);
    print_list(list);
    int found = find_in_list(list, 4);
    printf("Found 4: %d\n", found);
    destroy_list(list);
    return 0;
}