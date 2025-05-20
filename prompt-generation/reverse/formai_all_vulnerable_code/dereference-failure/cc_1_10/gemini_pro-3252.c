//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Insert at the beginning of the list
node *insert_beginning(node *head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

// Insert at the end of the list
node *insert_end(node *head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        return head;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Insert after a given node
node *insert_after(node *head, int data, int after) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    node *temp = head;
    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return head;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Delete the first occurrence of a node
node *delete_node(node *head, int data) {
    node *temp = head;
    node *prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return head;
    }
    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    return head;
}

// Reverse the list
node *reverse_list(node *head) {
    node *prev = NULL;
    node *current = head;
    node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// Print the list
void print_list(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    head = insert_beginning(head, 1);
    head = insert_end(head, 2);
    head = insert_end(head, 3);
    head = insert_after(head, 4, 2);
    head = delete_node(head, 3);
    head = reverse_list(head);
    print_list(head);
    return 0;
}