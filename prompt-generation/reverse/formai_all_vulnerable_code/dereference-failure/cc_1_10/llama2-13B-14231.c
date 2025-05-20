//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the simulation parameters
#define N 1000
#define M 10
#define K 5

// Define the data types
typedef struct node {
    int value;
    struct node* next;
} node_t;

// Define the simulation functions
void init_list(node_t** head_ref);
void insert_node(node_t** head_ref, int value);
void print_list(node_t* head);
void delete_node(node_t** head_ref, int value);

// Define the simulation variables
node_t* head = NULL;
int count = 0;

int main() {
    srand(time(NULL));

    // Initialize the list
    init_list(&head);

    // Insert some nodes
    for (int i = 0; i < N; i++) {
        insert_node(&head, rand() % M);
    }

    // Print the list
    print_list(head);

    // Delete some nodes
    for (int i = 0; i < K; i++) {
        delete_node(&head, rand() % M);
    }

    // Print the list again
    print_list(head);

    return 0;
}

// Function to initialize the list
void init_list(node_t** head_ref) {
    *head_ref = NULL;
    count = 0;
}

// Function to insert a node
void insert_node(node_t** head_ref, int value) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        head = new_node;
    } else {
        (*head_ref)->next = new_node;
    }

    count++;
}

// Function to print the list
void print_list(node_t* head) {
    printf("List: \n");
    node_t* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Function to delete a node
void delete_node(node_t** head_ref, int value) {
    node_t* current = head;
    node_t* previous = NULL;

    while (current != NULL) {
        if (current->value == value) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            count--;
            return;
        }

        previous = current;
        current = current->next;
    }
}