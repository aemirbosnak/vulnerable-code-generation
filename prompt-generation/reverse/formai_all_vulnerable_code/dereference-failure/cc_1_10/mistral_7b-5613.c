//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;
node_t *new_node;
node_t *temp;
node_t *prev;
int value_to_delete;

void print_list(void) {
    node_t *current = head;

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void create_new_node(int value) {
    new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = value;
    new_node->next = NULL;
}

void insert_at_beginning(int value) {
    create_new_node(value);
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int value) {
    create_new_node(value);

    if (head == NULL) {
        head = new_node;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_node_by_value(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == value) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    prev = NULL;
    temp = head;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

int main(void) {
    int i;

    for (i = 0; i < 5; i++) {
        insert_at_beginning(i);
        print_list();
    }

    printf("After inserting new nodes at the beginning:\n");

    for (i = 5; i <= 10; i++) {
        insert_at_end(i);
        print_list();
    }

    printf("After inserting new nodes at the end:\n");

    delete_node_by_value(3);
    print_list();

    delete_node_by_value(0);
    print_list();

    delete_node_by_value(11);
    print_list();

    return 0;
}