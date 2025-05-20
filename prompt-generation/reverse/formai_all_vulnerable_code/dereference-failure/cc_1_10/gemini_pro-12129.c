//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert_at_beginning(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void insert_at_position(int data, int position) {
    if (position == 1) {
        insert_at_beginning(data);
        return;
    }

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    int count = 1;
    node *temp = head;
    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (count == position - 1) {
        new_node->next = temp->next;
        temp->next = new_node;
    } else {
        printf("Invalid position!\n");
    }
}

void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void delete_at_position(int position) {
    if (position == 1) {
        delete_at_beginning();
        return;
    }

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    int count = 1;
    node *temp = head;
    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (count == position - 1) {
        node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    } else {
        printf("Invalid position!\n");
    }
}

void print_list() {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(10);
    insert_at_beginning(20);
    insert_at_end(30);
    insert_at_end(40);
    insert_at_position(50, 3);

    print_list();

    delete_at_beginning();
    delete_at_end();
    delete_at_position(2);

    print_list();

    return 0;
}