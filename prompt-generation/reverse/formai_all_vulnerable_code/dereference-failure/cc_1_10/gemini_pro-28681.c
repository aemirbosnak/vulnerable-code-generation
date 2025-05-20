//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *name;
    char *time;
    char *location;
} appointment;

typedef struct node {
    appointment appt;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
} list;

void init_list(list *l) {
    l->head = NULL;
    l->tail = NULL;
}

void add_appt(list *l, appointment appt) {
    node *new_node = malloc(sizeof(node));
    new_node->appt = appt;
    new_node->next = NULL;

    if (l->head == NULL) {
        l->head = new_node;
        l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node;
    }
}

void print_list(list *l) {
    node *current_node = l->head;

    while (current_node != NULL) {
        printf("%s at %s in %s\n", current_node->appt.name, current_node->appt.time, current_node->appt.location);
        current_node = current_node->next;
    }
}

int main() {
    list appt_list;
    init_list(&appt_list);

    appointment appt1 = {"John Doe", "10:00 AM", "Starbucks"};
    add_appt(&appt_list, appt1);

    appointment appt2 = {"Jane Smith", "11:00 AM", "Panera Bread"};
    add_appt(&appt_list, appt2);

    appointment appt3 = {"Bill Jones", "12:00 PM", "Chipotle"};
    add_appt(&appt_list, appt3);

    print_list(&appt_list);

    return 0;
}