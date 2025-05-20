//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to represent a "network node"
struct node {
    int id; // unique node ID
    char name[50]; // node name
    struct node *next; // pointer to next node
};

// Define a function to create a new node
struct node* create_node(int id, char name[]) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

// Define a function to add a node to the network
void add_node(struct node** head_ref, int id, char name[]) {
    struct node* new_node = create_node(id, name);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Define a function to print the network
void print_network(struct node* head) {
    while (head != NULL) {
        printf("%d: %s\n", head->id, head->name);
        head = head->next;
    }
}

int main() {
    struct node* head = NULL;

    // Add nodes to the network
    add_node(&head, 1, "Node 1");
    add_node(&head, 2, "Node 2");
    add_node(&head, 3, "Node 3");
    add_node(&head, 4, "Node 4");

    // Print the network
    print_network(head);

    return 0;
}