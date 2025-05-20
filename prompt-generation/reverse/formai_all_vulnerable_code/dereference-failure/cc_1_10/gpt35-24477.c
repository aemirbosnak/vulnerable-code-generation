//FormAI DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
Node* insert_beginning(Node* head, int data) {
    Node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    return head;
}

// Function to delete a node with a given data from the linked list
Node* delete_node(Node* head, int data) {
    Node* current_node = head;
    Node* prev_node = NULL;
    while (current_node != NULL) {
        if (current_node->data == data) {
            if (prev_node == NULL) { // the node to be deleted is the head node
                head = head->next;
            } else {
                prev_node->next = current_node->next;
            }
            free(current_node);
            return head;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
    return head; // the node with the given data was not found in the linked list
}

// Function to visualize the linked list as a horizontal bar chart
void visualize_linked_list(Node* head) {
    char* bar = "====";
    Node* current_node = head;
    printf("\n");
    while (current_node != NULL) {
        printf("%d: ", current_node->data);
        for (int i = 0; i < current_node->data; i++) {
            printf("%s", bar);
        }
        printf("\n");
        current_node = current_node->next;
    }
}

int main() {
    Node* linked_list = NULL;
    linked_list = insert_beginning(linked_list, 5);
    linked_list = insert_beginning(linked_list, 3);
    linked_list = insert_beginning(linked_list, 2);
    linked_list = insert_beginning(linked_list, 1);
    linked_list = insert_beginning(linked_list, 4);
    visualize_linked_list(linked_list);
    linked_list = delete_node(linked_list, 3);
    linked_list = delete_node(linked_list, 4);
    linked_list = delete_node(linked_list, 7);
    visualize_linked_list(linked_list);
    return 0;
}