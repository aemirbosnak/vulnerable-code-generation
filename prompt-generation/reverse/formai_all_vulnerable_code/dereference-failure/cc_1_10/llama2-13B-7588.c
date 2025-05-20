//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_STRING 100

typedef struct node {
    char name[MAX_STRING];
    int age;
    struct node* next;
} node_t;

node_t* create_node(char* name, int age) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->next = NULL;
    return new_node;
}

void print_nodes(node_t* head) {
    while (head != NULL) {
        printf("%s %d\n", head->name, head->age);
        head = head->next;
    }
}

int main() {
    node_t* head = NULL;

    // Create some nodes
    head = create_node("Alice", 25);
    head = create_node("Bob", 30);
    head = create_node("Charlie", 35);

    // Add some edges
    head->next = create_node("David", 20);
    head->next->next = create_node("Eve", 25);

    // Print the nodes
    print_nodes(head);

    // Remove a node
    head = head->next;
    free(head);

    // Print the nodes again
    print_nodes(head);

    return 0;
}