//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define NODE_SIZE sizeof(struct node)
#define CELL_SIZE sizeof(struct cell)

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct cell {
    int data;
    struct cell *next;
    struct cell *prev;
};

struct list {
    struct node *head;
    struct node *tail;
};

void push_front(struct list *list, int data) {
    struct node *new_node = malloc(NODE_SIZE);
    new_node->data = data;
    new_node->next = list->head;
    new_node->prev = NULL;
    if (list->head != NULL) {
        list->head->prev = new_node;
    }
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

void push_back(struct list *list, int data) {
    struct node *new_node = malloc(NODE_SIZE);
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = new_node;
    }
    list->tail = new_node;
    if (list->head == NULL) {
        list->head = new_node;
    }
}

void pop_front(struct list *list) {
    if (list->head != NULL) {
        struct node *next_node = list->head->next;
        free(list->head);
        list->head = next_node;
        if (next_node != NULL) {
            next_node->prev = NULL;
        } else {
            list->tail = NULL;
        }
    }
}

void pop_back(struct list *list) {
    if (list->tail != NULL) {
        struct node *prev_node = list->tail->prev;
        free(list->tail);
        list->tail = prev_node;
        if (prev_node != NULL) {
            prev_node->next = NULL;
        } else {
            list->head = NULL;
        }
    }
}

void print_list(struct list *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void push_front_cell(struct cell *cell, int data) {
    struct cell *new_cell = malloc(CELL_SIZE);
    new_cell->data = data;
    new_cell->next = cell->next;
    new_cell->prev = NULL;
    if (cell->next != NULL) {
        cell->next->prev = new_cell;
    }
    cell->next = new_cell;
    if (cell->prev == NULL) {
        cell->prev = new_cell;
    }
}

void push_back_cell(struct cell *cell, int data) {
    struct cell *new_cell = malloc(CELL_SIZE);
    new_cell->data = data;
    new_cell->next = NULL;
    new_cell->prev = cell->prev;
    if (cell->prev != NULL) {
        cell->prev->next = new_cell;
    }
    cell->prev = new_cell;
    if (cell->next == NULL) {
        cell->next = new_cell;
    }
}

void pop_front_cell(struct cell *cell) {
    if (cell->next != NULL) {
        struct cell *next_cell = cell->next->next;
        free(cell->next);
        cell->next = next_cell;
        if (next_cell != NULL) {
            next_cell->prev = cell;
        } else {
            cell->prev = NULL;
        }
    }
}

void pop_back_cell(struct cell *cell) {
    if (cell->prev != NULL) {
        struct cell *prev_cell = cell->prev->prev;
        free(cell->prev);
        cell->prev = prev_cell;
        if (prev_cell != NULL) {
            prev_cell->next = cell;
        } else {
            cell->next = NULL;
        }
    }
}

void print_cell(struct cell *cell) {
    struct cell *current_cell = cell->next;
    while (current_cell != NULL) {
        printf("%d ", current_cell->data);
        current_cell = current_cell->next;
    }
    printf("\n");
}

int main() {
    struct list list;
    list.head = NULL;
    list.tail = NULL;

    push_front(&list, 1);
    push_front(&list, 2);
    push_front(&list, 3);
    push_back(&list, 4);
    push_back(&list, 5);
    push_back(&list, 6);

    print_list(&list);

    pop_front(&list);
    pop_back(&list);

    print_list(&list);

    struct cell cell;
    cell.next = NULL;
    cell.prev = NULL;

    push_front_cell(&cell, 1);
    push_front_cell(&cell, 2);
    push_front_cell(&cell, 3);
    push_back_cell(&cell, 4);
    push_back_cell(&cell, 5);
    push_back_cell(&cell, 6);

    print_cell(&cell);

    pop_front_cell(&cell);
    pop_back_cell(&cell);

    print_cell(&cell);

    return 0;
}