//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with a given value
struct node* new_node(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void print_list(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse the linked list
struct node* reverse_list(struct node* head) {
    struct node* current = head;
    struct node* previous = NULL;

    while (current != NULL) {
        struct node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

// Function to find the middle node of the linked list
struct node* find_middle(struct node* head) {
    int count = 0;
    struct node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    current = head;
    count /= 2;

    while (count-- > 0) {
        current = current->next;
    }

    return current;
}

int main() {
    struct node* head = NULL;

    // Create a linked list with the following nodes:
    // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);
    head->next->next->next->next = new_node(5);
    head->next->next->next->next->next = new_node(6);
    head->next->next->next->next->next->next = new_node(7);
    head->next->next->next->next->next->next->next = new_node(8);
    head->next->next->next->next->next->next->next->next = new_node(9);
    head->next->next->next->next->next->next->next->next->next = new_node(10);

    // Print the linked list
    print_list(head);

    // Reverse the linked list
    head = reverse_list(head);

    // Find the middle node of the linked list
    struct node* middle = find_middle(head);

    // Print the middle node
    printf("Middle node: %d\n", middle->data);

    return 0;
}