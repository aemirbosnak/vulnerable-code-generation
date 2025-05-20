//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
// A performance-critical component in C designed for efficiency and real-time execution.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Custom data structure for efficient memory management
typedef struct {
    int data;
    struct Node *next;
} Node;

// Function to initialize a linked list
Node *init_list() {
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

// Function to insert an element at the end of the linked list
void insert(Node *head, int data) {
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    current->next = new_node;
}

// Function to search for an element in the linked list
int search(Node *head, int data) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to perform a specific computation on the data in the linked list
int compute(Node *head) {
    int sum = 0;
    Node *current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

// Performance testing function to measure execution time
void test_performance(Node *head, int num_iterations) {
    clock_t start = clock();
    for (int i = 0; i < num_iterations; i++) {
        compute(head);
    }
    clock_t end = clock();
    double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time for %d iterations: %f seconds\n", num_iterations, time_elapsed);
}

int main() {
    // Create a linked list and insert some data
    Node *head = init_list();
    for (int i = 0; i < 100000; i++) {
        insert(head, rand() % 1000);
    }

    // Perform performance testing
    test_performance(head, 1000);
    test_performance(head, 10000);
    test_performance(head, 100000);

    return 0;
}