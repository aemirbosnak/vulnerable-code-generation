//GEMINI-pro DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node for a decentralized data structure
struct node {
    char *data;
    struct node *next;
};

// Define a decentralized data structure
struct decentralized_data_structure {
    struct node *head;
};

// Create a new node
struct node *create_node(char *data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = strdup(data);
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of a decentralized data structure
void insert_node(struct decentralized_data_structure *dds, char *data) {
    struct node *new_node = create_node(data);
    new_node->next = dds->head;
    dds->head = new_node;
}

// Print the data in a decentralized data structure
void print_dds(struct decentralized_data_structure *dds) {
    struct node *current_node = dds->head;
    while (current_node != NULL) {
        printf("%s\n", current_node->data);
        current_node = current_node->next;
    }
}

// Free the memory allocated for a decentralized data structure
void free_dds(struct decentralized_data_structure *dds) {
    struct node *current_node = dds->head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node->data);
        free(current_node);
        current_node = next_node;
    }
}

// Main function
int main() {
    // Create a decentralized data structure
    struct decentralized_data_structure dds;
    dds.head = NULL;

    // Insert some data into the decentralized data structure
    insert_node(&dds, "Hello");
    insert_node(&dds, "World");
    insert_node(&dds, "!");

    // Print the data in the decentralized data structure
    print_dds(&dds);

    // Free the memory allocated for the decentralized data structure
    free_dds(&dds);

    return 0;
}