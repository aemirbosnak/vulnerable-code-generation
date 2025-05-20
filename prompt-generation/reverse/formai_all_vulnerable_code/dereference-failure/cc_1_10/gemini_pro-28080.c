//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct linked_list {
    int size;
    struct node *head;
    struct node *tail;
};

void init_linked_list(struct linked_list *list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

void insert_node(struct linked_list *list, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

bool search_node_linear(struct linked_list *list, int data) {
    struct node *current_node = list->head;

    while (current_node != NULL) {
        if (current_node->data == data) {
            return true;
        }

        current_node = current_node->next;
    }

    return false;
}

bool search_node_binary(struct linked_list *list, int data) {
    if (list->size == 0) {
        return false;
    }

    int low = 0;
    int high = list->size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        struct node *mid_node = list->head;

        for (int i = 0; i < mid; i++) {
            mid_node = mid_node->next;
        }

        if (mid_node->data == data) {
            return true;
        } else if (mid_node->data < data) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}

void print_linked_list(struct linked_list *list) {
    struct node *current_node = list->head;

    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

int main() {
    struct linked_list list;
    init_linked_list(&list);

    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    for (int i = 0; i < 10; i++) {
        insert_node(&list, data[i]);
    }

    printf("Linear Search: \n");
    if (search_node_linear(&list, 11)) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }

    printf("Binary Search: \n");
    if (search_node_binary(&list, 11)) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }

    return 0;
}