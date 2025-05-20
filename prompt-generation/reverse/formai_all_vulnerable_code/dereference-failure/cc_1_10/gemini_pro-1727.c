//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
// Linus Torvalds: "Talk is cheap. Show me the code."

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A simple linked list node
struct node {
    int data;
    struct node *next;
};

// Create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the list
struct node *insert_at_beginning(struct node *head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Insert a new node at the end of the list
struct node *insert_at_end(struct node *head, int data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

// Insert a new node after a given node
struct node *insert_after(struct node *head, int data, int after_data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == after_data) {
            new_node->next = temp->next;
            temp->next = new_node;
            return head;
        }
        temp = temp->next;
    }
    printf("Node with data %d not found\n", after_data);
    free(new_node);
    return head;
}

// Delete a node from the beginning of the list
struct node *delete_from_beginning(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete a node from the end of the list
struct node *delete_from_end(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
    return head;
}

// Delete a node from the list after a given node
struct node *delete_after(struct node *head, int after_data) {
    if (head == NULL) {
        return NULL;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL) {
        if (temp->data == after_data) {
            if (temp->next == NULL) {
                printf("Node with data %d not found\n", after_data);
                return head;
            }
            prev = temp;
            temp = temp->next;
            break;
        }
        temp = temp->next;
    }
    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    return head;
}

// Print the list
void print_list(struct node *head) {
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create an empty list
    struct node *head = NULL;

    // Insert some nodes into the list
    head = insert_at_beginning(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_after(head, 4, 2);

    // Print the list
    print_list(head);

    // Delete a node from the beginning of the list
    head = delete_from_beginning(head);

    // Print the list
    print_list(head);

    // Delete a node from the end of the list
    head = delete_from_end(head);

    // Print the list
    print_list(head);

    // Delete a node from the list after a given node
    head = delete_after(head, 2);

    // Print the list
    print_list(head);

    return 0;
}