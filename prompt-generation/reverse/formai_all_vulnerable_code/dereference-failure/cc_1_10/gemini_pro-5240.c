//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
// Ada Lovelace's Analytical Engine
    // Visualize Data Structures

    // Header
    #include <stdio.h>
    #include <stdlib.h>

    // Data Structures
    typedef struct node {
        int data;
        struct node *next;
    } node;

    // Functions
    node *create_node(int data) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = NULL;
        return new_node;
    }

    void insert_node(node **head, node *new_node) {
        if (*head == NULL) {
            *head = new_node;
        } else {
            node *current_node = *head;
            while (current_node->next != NULL) {
                current_node = current_node->next;
            }
            current_node->next = new_node;
        }
    }

    void delete_node(node **head, int data) {
        if (*head == NULL) {
            printf("List is empty\n");
        } else {
            node *current_node = *head;
            node *previous_node = NULL;
            while (current_node != NULL && current_node->data != data) {
                previous_node = current_node;
                current_node = current_node->next;
            }
            if (current_node == NULL) {
                printf("Node not found\n");
            } else {
                if (previous_node == NULL) {
                    *head = current_node->next;
                } else {
                    previous_node->next = current_node->next;
                }
                free(current_node);
            }
        }
    }

    void print_list(node *head) {
        if (head == NULL) {
            printf("List is empty\n");
        } else {
            node *current_node = head;
            while (current_node != NULL) {
                printf("%d ", current_node->data);
                current_node = current_node->next;
            }
            printf("\n");
        }
    }

    // Main
    int main() {
        // Create a linked list
        node *head = NULL;
        insert_node(&head, create_node(1));
        insert_node(&head, create_node(2));
        insert_node(&head, create_node(3));
        insert_node(&head, create_node(4));
        insert_node(&head, create_node(5));

        // Print the linked list
        printf("Linked List: ");
        print_list(head);

        // Delete a node from the linked list
        delete_node(&head, 3);

        // Print the linked list
        printf("Linked List after deleting node with data 3: ");
        print_list(head);

        return 0;
    }