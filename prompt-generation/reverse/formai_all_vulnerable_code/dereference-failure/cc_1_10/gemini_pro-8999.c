//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a linked list
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of a linked list
struct node *insert_at_beginning(struct node *head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a node at the end of a linked list
struct node *insert_at_end(struct node *head, int data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    struct node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}

// Function to insert a node at a specific position in a linked list
struct node *insert_at_position(struct node *head, int data, int position) {
    struct node *new_node = create_node(data);
    if (position == 1) {
        new_node->next = head;
        head = new_node;
        return head;
    }
    struct node *current_node = head;
    int current_position = 1;
    while (current_node != NULL && current_position < position) {
        current_node = current_node->next;
        current_position++;
    }
    if (current_node == NULL) {
        return head;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    return head;
}

// Function to delete a node from the beginning of a linked list
struct node *delete_from_beginning(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *new_head = head->next;
    free(head);
    return new_head;
}

// Function to delete a node from the end of a linked list
struct node *delete_from_end(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *current_node = head;
    struct node *previous_node = NULL;
    while (current_node->next != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (previous_node == NULL) {
        head = NULL;
    } else {
        previous_node->next = NULL;
    }
    free(current_node);
    return head;
}

// Function to delete a node from a specific position in a linked list
struct node *delete_from_position(struct node *head, int position) {
    if (head == NULL) {
        return NULL;
    }
    struct node *current_node = head;
    struct node *previous_node = NULL;
    int current_position = 1;
    while (current_node != NULL && current_position < position) {
        previous_node = current_node;
        current_node = current_node->next;
        current_position++;
    }
    if (current_node == NULL) {
        return head;
    }
    if (previous_node == NULL) {
        head = current_node->next;
    } else {
        previous_node->next = current_node->next;
    }
    free(current_node);
    return head;
}

// Function to print a linked list
void print_linked_list(struct node *head) {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Function to find the length of a linked list
int find_length(struct node *head) {
    struct node *current_node = head;
    int length = 0;
    while (current_node != NULL) {
        length++;
        current_node = current_node->next;
    }
    return length;
}

// Function to find the middle of a linked list
struct node *find_middle(struct node *head) {
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    return slow_ptr;
}

// Function to reverse a linked list
struct node *reverse(struct node *head) {
    struct node *previous_node = NULL;
    struct node *current_node = head;
    struct node *next_node = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    head = previous_node;
    return head;
}

int main() {
    struct node *head = NULL;
    head = insert_at_end(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);
    print_linked_list(head);
    head = delete_from_beginning(head);
    print_linked_list(head);
    head = delete_from_end(head);
    print_linked_list(head);
    head = delete_from_position(head, 3);
    print_linked_list(head);
    int length = find_length(head);
    printf("Length of the linked list: %d\n", length);
    struct node *middle_node = find_middle(head);
    printf("Middle of the linked list: %d\n", middle_node->data);
    head = reverse(head);
    print_linked_list(head);
    return 0;
}