//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

// Structure to represent a node in the graph
typedef struct node {
    int label;   // Label of the node
    int degree;  // Degree of the node (number of edges incident on it)
    struct node *next;  // Pointer to the next node in the list
} Node;

// Function to create a new node
Node *new_node(int label) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->label = label;
    node->degree = 0;
    node->next = NULL;
    return node;
}

// Function to add an edge to the graph
void add_edge(Node *u, Node *v) {
    // Check if the nodes are already connected
    if (u->degree == 0 || v->degree == 0) {
        u->degree++;
        v->degree++;
        u->next = v;
        v->next = u;
    }
}

// Function to print the graph
void print_graph(Node *root) {
    if (root == NULL) {
        printf("The graph is empty.\n");
        return;
    }

    printf("The graph contains the following nodes:\n");
    Node *current = root;
    while (current != NULL) {
        printf("%d: ", current->label);
        if (current->degree > 0) {
            printf("connected to ");
            Node *next = current->next;
            while (next != NULL) {
                printf("%d, ", next->label);
                next = next->next;
            }
            printf("\n");
        }
        current = current->next;
    }
}

// Main function
int main() {
    // Create the root node
    Node *root = new_node(1);

    // Add edges to the graph
    add_edge(root, new_node(2));
    add_edge(root, new_node(3));
    add_edge(new_node(2), new_node(4));
    add_edge(new_node(3), new_node(5));
    add_edge(new_node(4), new_node(6));
    add_edge(new_node(5), new_node(7));
    add_edge(new_node(6), new_node(8));
    add_edge(new_node(7), new_node(9));
    add_edge(new_node(8), new_node(10));

    // Print the graph
    print_graph(root);

    return 0;
}