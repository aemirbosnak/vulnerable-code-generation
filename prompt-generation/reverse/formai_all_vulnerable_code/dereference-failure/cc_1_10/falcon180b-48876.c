//Falcon-180B DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} node_t;

int main() {
    node_t* head = NULL;
    node_t* curr = NULL;
    char input[MAX_SIZE];
    int count = 0;

    // Allocate memory for head node
    head = (node_t*) malloc(sizeof(node_t));
    if (head == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Initialize head node
    strcpy(head->data, "Head");
    head->next = NULL;

    // Read input strings and add to linked list
    while (1) {
        printf("Enter string (enter 'done' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        // Allocate memory for new node
        curr = (node_t*) malloc(sizeof(node_t));
        if (curr == NULL) {
            printf("Error: Memory allocation failed.\n");
            return 1;
        }

        // Copy input string to new node
        strcpy(curr->data, input);
        curr->next = NULL;

        // Add new node to linked list
        if (head == NULL) {
            head = curr;
        } else {
            curr->next = head;
            head = curr;
        }

        // Increment count of nodes
        count++;
    }

    // Print linked list
    printf("\nLinked list:\n");
    curr = head;
    while (curr!= NULL) {
        printf("Node %d: %s\n", count, curr->data);
        curr = curr->next;
        count++;
    }

    // Free memory for linked list
    curr = head;
    while (curr!= NULL) {
        head = curr->next;
        free(curr);
        curr = head;
    }

    return 0;
}