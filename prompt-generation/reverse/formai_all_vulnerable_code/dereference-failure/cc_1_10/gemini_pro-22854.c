//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *artist;
    char *title;
    int year;
    struct node *next;
} node_t;

// Configuration options
#define MAX_ARTISTS 100
#define MAX_TITLES 100
#define MAX_YEARS 100

// Function prototypes
node_t *create_node(char *artist, char *title, int year);
void add_node(node_t **head, node_t *new_node);
void print_list(node_t *head);
void free_list(node_t *head);

int main() {
    // Create a new head node
    node_t *head = NULL;

    // Add some nodes to the list
    add_node(&head, create_node("The Beatles", "Yesterday", 1965));
    add_node(&head, create_node("The Rolling Stones", "Paint It Black", 1966));
    add_node(&head, create_node("Bob Dylan", "Blowin' in the Wind", 1963));

    // Print the list
    print_list(head);

    // Free the list
    free_list(head);

    return 0;
}

// Create a new node
node_t *create_node(char *artist, char *title, int year) {
    // Allocate memory for the new node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc() failed\n");
        exit(1);
    }

    // Copy the artist, title, and year into the new node
    new_node->artist = strdup(artist);
    new_node->title = strdup(title);
    new_node->year = year;
    new_node->next = NULL;

    // Return the new node
    return new_node;
}

// Add a new node to the list
void add_node(node_t **head, node_t *new_node) {
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Otherwise, add the new node to the end of the list
    node_t *current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// Print the list
void print_list(node_t *head) {
    // Print the header
    printf("%-20s %-20s %-4s\n", "Artist", "Title", "Year");

    // Print each node in the list
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%-20s %-20s %-4d\n", current_node->artist, current_node->title, current_node->year);
        current_node = current_node->next;
    }
}

// Free the list
void free_list(node_t *head) {
    // Free each node in the list
    node_t *current_node = head;
    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node->artist);
        free(current_node->title);
        free(current_node);
        current_node = next_node;
    }
}