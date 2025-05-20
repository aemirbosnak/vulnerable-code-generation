//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Add a new node to the front of the list
void push(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// Delete a node from the front of the list
void pop() {
    if (head == NULL) {
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

// Insert a new node after a given node
void insert_after(struct node *prev_node, int data) {
    if (prev_node == NULL) {
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Delete a node from the list
void delete_node(struct node *node) {
    if (node == NULL) {
        return;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != node) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = node->next;
    }
    free(node);
}

// Print the list
void print_list() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Get the length of the list
int get_length() {
    struct node *temp = head;
    int length = 0;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Get the nth node from the list
struct node *get_nth_node(int n) {
    struct node *temp = head;
    int count = 0;
    while (temp != NULL) {
        if (count == n) {
            return temp;
        }
        count++;
        temp = temp->next;
    }
    return NULL;
}

// Reverse the list
void reverse_list() {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Main function
int main() {
    // Create a linked list
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    // Print the list
    print_list();

    // Get the length of the list
    int length = get_length();
    printf("Length of the list: %d\n", length);

    // Get the nth node from the list
    struct node *nth_node = get_nth_node(2);
    printf("Nth node: %d\n", nth_node->data);

    // Reverse the list
    reverse_list();

    // Print the list
    print_list();

    return 0;
}