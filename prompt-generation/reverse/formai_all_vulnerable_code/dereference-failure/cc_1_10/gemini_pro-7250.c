//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I did not have to add any type annotation to this program, I prefer to avoid when the code is clear enough
struct node {
    int data;
    struct node *next;
};

// Recursive function to insert a new node at the beginning of a linked list
struct node *insert_at_beginning(struct node *head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// Recursive function to insert a new node at the end of a linked list
struct node *insert_at_end(struct node *head, int data) {
    if (head == NULL) {
        return insert_at_beginning(head, data);
    }
    head->next = insert_at_end(head->next, data);
    return head;
}

// Recursive function to delete a node from a linked list
struct node *delete_node(struct node *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == data) {
        struct node *new_head = head->next;
        free(head);
        return new_head;
    }
    head->next = delete_node(head->next, data);
    return head;
}

// Recursive function to search for a node in a linked list
struct node *search_node(struct node *head, int data) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == data) {
        return head;
    }
    return search_node(head->next, data);
}

// Recursive function to print a linked list
void print_linked_list(struct node *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    print_linked_list(head->next);
}

// Recursive function to free a linked list
void free_linked_list(struct node *head) {
    if (head == NULL) {
        return;
    }
    free_linked_list(head->next);
    free(head);
}

int main() {
    struct node *head = NULL;
    
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);

    print_linked_list(head);

    head = delete_node(head, 2);
    head = delete_node(head, 4);

    print_linked_list(head);

    struct node *found_node = search_node(head, 3);
    if (found_node == NULL) {
        printf("Node not found\n");
    } else {
        printf("Node found: %d\n", found_node->data);
    }

    free_linked_list(head);

    return 0;
}