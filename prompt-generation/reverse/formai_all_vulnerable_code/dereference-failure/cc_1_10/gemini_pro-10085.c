//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Insert a node at the beginning of the list
struct node *insert_at_beginning(struct node *head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// Insert a node at the end of the list
struct node *insert_at_end(struct node *head, int data) {
    if (head == NULL) {
        return insert_at_beginning(head, data);
    } else {
        head->next = insert_at_end(head->next, data);
        return head;
    }
}

// Insert a node after a given node
struct node *insert_after_node(struct node *head, int data, int after_data) {
    if (head == NULL) {
        return NULL;
    } else if (head->data == after_data) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = head->next;
        head->next = new_node;
        return head;
    } else {
        head->next = insert_after_node(head->next, data, after_data);
        return head;
    }
}

// Delete a node from the beginning of the list
struct node *delete_at_beginning(struct node *head) {
    if (head == NULL) {
        return NULL;
    } else {
        struct node *new_head = head->next;
        free(head);
        return new_head;
    }
}

// Delete a node from the end of the list
struct node *delete_at_end(struct node *head) {
    if (head == NULL) {
        return NULL;
    } else if (head->next == NULL) {
        free(head);
        return NULL;
    } else {
        head->next = delete_at_end(head->next);
        return head;
    }
}

// Delete a node after a given node
struct node *delete_after_node(struct node *head, int after_data) {
    if (head == NULL) {
        return NULL;
    } else if (head->data == after_data) {
        if (head->next == NULL) {
            return head;
        } else {
            struct node *new_next = head->next->next;
            free(head->next);
            head->next = new_next;
            return head;
        }
    } else {
        head->next = delete_after_node(head->next, after_data);
        return head;
    }
}

// Print the list
void print_list(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printf("%d ", head->data);
        print_list(head->next);
    }
}

// Main function
int main() {
    struct node *head = NULL;

    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_after_node(head, 3, 1);
    head = insert_at_beginning(head, 4);
    head = insert_at_end(head, 5);
    head = insert_after_node(head, 6, 4);

    print_list(head);
    printf("\n");

    head = delete_at_beginning(head);
    head = delete_at_end(head);
    head = delete_after_node(head, 4);
    head = delete_at_beginning(head);
    head = delete_at_end(head);

    print_list(head);
    printf("\n");

    return 0;
}