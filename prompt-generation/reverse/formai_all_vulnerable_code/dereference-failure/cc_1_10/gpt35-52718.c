//FormAI DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int input;

    printf("Welcome to the Curious Linked List Visualizer!\n");
    printf("Please enter a list of integers to add to the list:\n");

    while (scanf("%d", &input) == 1) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = input;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    printf("\n\n");
    printf("Here is a visualization of your linked list:\n");

    Node* current_node = head;
    int node_count = 0;

    while (current_node != NULL) {
        printf("Node %d\n", ++node_count);
        printf("---------------------\n");
        printf("|      DATA: %-8d|\n", current_node->data);
        printf("|  NEXT NODE: %-8p|\n", (void*)current_node->next);
        printf("---------------------\n\n");

        current_node = current_node->next;
    }

    printf("Thank you for using the Curious Linked List Visualizer!\n");

    return 0;
}