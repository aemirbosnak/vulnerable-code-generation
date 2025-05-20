//Gemma-7B DATASET v1.0 Category: Educational ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define a linked list node
struct node {
    int data;
    struct node* next;
};

// Calculate the factorial of a number recursively
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Insert a number into a linked list
void insert(struct node** head, int num) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

// Search for a number in a linked list
struct node* search(struct node* head, int num) {
    while (head) {
        if (head->data == num) {
            return head;
        } else if (head->data < num) {
            head = head->next;
        }
    }

    return NULL;
}

int main() {
    struct node* head = NULL;

    insert(head, 5);
    insert(head, 10);
    insert(head, 15);
    insert(head, 20);

    struct node* found_node = search(head, 15);

    if (found_node) {
        printf("Found node: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}