//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int id;
    int state;
    int count;
    struct node *next;
};

void init(struct node **head) {
    *head = NULL;
}

void add_node(struct node **head, int id, int state) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->id = id;
    new_node->state = state;
    new_node->count = 0;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void change_state(struct node **head, int id, int state) {
    struct node *temp = *head;
    while (temp!= NULL) {
        if (temp->id == id) {
            temp->state = state;
            break;
        }
        temp = temp->next;
    }
}

void update_counts(struct node **head) {
    struct node *temp = *head;
    while (temp!= NULL) {
        temp->count++;
        temp = temp->next;
    }
}

void print_list(struct node *head) {
    while (head!= NULL) {
        printf("ID: %d, State: %d, Count: %d\n", head->id, head->state, head->count);
        head = head->next;
    }
}

int main() {
    srand(time(NULL));

    struct node *head = NULL;

    int num_nodes = rand() % 100 + 1;
    int i;
    for (i = 0; i < num_nodes; i++) {
        int id = rand() % 1000 + 1;
        int state = rand() % 3;
        add_node(&head, id, state);
    }

    int num_iterations = rand() % 1000 + 1;
    for (i = 0; i < num_iterations; i++) {
        int id = rand() % 1000 + 1;
        int state = rand() % 3;
        change_state(&head, id, state);
        update_counts(&head);
        print_list(head);
        printf("\n");
    }

    return 0;
}