//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: peaceful
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
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_at_position(int data, int position) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (position == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        struct node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty!\n");
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
        printf("List is empty!\n");
        return;
    }
    if (position == 1) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    } else {
        struct node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

void display_list() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Inserting at beginning
    insert_at_beginning(10);
    insert_at_beginning(20);
    insert_at_beginning(30);

    // Inserting at end
    insert_at_end(40);
    insert_at_end(50);
    insert_at_end(60);

    // Inserting at position
    insert_at_position(70, 4);
    insert_at_position(80, 6);

    // Displaying the list
    printf("The list is: ");
    display_list();

    // Deleting at beginning
    delete_at_beginning();
    delete_at_beginning();

    // Deleting at end
    delete_at_end();
    delete_at_end();

    // Deleting at position
    delete_at_position(3);
    delete_at_position(5);

    // Displaying the list again
    printf("The list after deletions is: ");
    display_list();

    return 0;
}