//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a linked list node
struct node {
    int data;
    struct node *next;
};

// Function to create a new linked list
struct node* new_list(int size) {
    struct node* head = NULL;
    for (int i = 0; i < size; i++) {
        struct node* new_node = malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }
    return head;
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

// Function to find the middle element of the linked list
struct node* find_middle(struct node* head) {
    struct node* slow = head;
    struct node* fast = head->next->next;

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    struct node* head = new_list(10);
    print_list(head);

    head = reverse_list(head);
    print_list(head);

    struct node* middle = find_middle(head);
    printf("Middle element: %d\n", middle->data);

    return 0;
}