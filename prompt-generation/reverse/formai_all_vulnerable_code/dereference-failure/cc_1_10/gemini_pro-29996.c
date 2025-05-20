//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char *description;
    float amount;
};

struct node {
    struct expense *expense;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
};

struct list *create_list() {
    struct list *list = malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_expense(struct list *list, struct expense *expense) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->expense = expense;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_list(struct list *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        printf("%s: $%.2f\n", current_node->expense->description, current_node->expense->amount);
        current_node = current_node->next;
    }
}

void free_list(struct list *list) {
    struct node *current_node = list->head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

int main() {
    struct list *list = create_list();
    struct expense *expense1 = malloc(sizeof(struct expense));
    expense1->description = "A bouquet of red roses";
    expense1->amount = 30.00;
    add_expense(list, expense1);
    struct expense *expense2 = malloc(sizeof(struct expense));
    expense2->description = "A romantic dinner for two";
    expense2->amount = 100.00;
    add_expense(list, expense2);
    print_list(list);
    free_list(list);
    return 0;
}