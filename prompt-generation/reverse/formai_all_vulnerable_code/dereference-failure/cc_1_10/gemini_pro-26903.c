//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_at_position(int data, int position) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;

    if (position == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void delete_at_position(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }

    struct node *to_delete = temp->next;
    temp->next = temp->next->next;
    free(to_delete);
}

void print_list() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Insert some values into the list
    insert_at_beginning(10);
    insert_at_beginning(20);
    insert_at_end(30);
    insert_at_position(40, 3);
    insert_at_position(50, 5);

    // Print the list
    print_list();  // Output: 20 10 30 40 50

    // Delete some values from the list
    delete_at_beginning();
    delete_at_end();
    delete_at_position(3);

    // Print the list
    print_list();  // Output: 10 30 50

    return 0;
}