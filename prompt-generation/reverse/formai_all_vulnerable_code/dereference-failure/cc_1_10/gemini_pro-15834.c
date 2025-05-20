//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
    char *title;
    char *artist;
    char *album;
    int year;
    struct node *next;
} node;

// Define the library structure
typedef struct library {
    node *head;
    node *tail;
} library;

// Create a new library
library *create_library() {
    library *new_library = malloc(sizeof(library));
    new_library->head = NULL;
    new_library->tail = NULL;
    return new_library;
}

// Add a new node to the library
void add_node(library *library, char *title, char *artist, char *album, int year) {
    // Create a new node
    node *new_node = malloc(sizeof(node));
    new_node->title = strdup(title);
    new_node->artist = strdup(artist);
    new_node->album = strdup(album);
    new_node->year = year;
    new_node->next = NULL;

    // If the library is empty, set the head and tail to the new node
    if (library->head == NULL) {
        library->head = new_node;
        library->tail = new_node;
    } else {
        // Otherwise, add the new node to the end of the library
        library->tail->next = new_node;
        library->tail = new_node;
    }
}

// Print the library
void print_library(library *library) {
    node *current_node = library->head;

    while (current_node != NULL) {
        printf("%s - %s - %s - %d\n", current_node->title, current_node->artist, current_node->album, current_node->year);
        current_node = current_node->next;
    }
}

// Free the library
void free_library(library *library) {
    node *current_node = library->head;

    while (current_node != NULL) {
        node *next_node = current_node->next;
        free(current_node->title);
        free(current_node->artist);
        free(current_node->album);
        free(current_node);
        current_node = next_node;
    }

    free(library);
}

int main() {
    // Create a new library
    library *my_library = create_library();

    // Add some nodes to the library
    add_node(my_library, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
    add_node(my_library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
    add_node(my_library, "Hotel California", "Eagles", "Hotel California", 1976);
    add_node(my_library, "Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991);
    add_node(my_library, "Imagine", "John Lennon", "Imagine", 1971);

    // Print the library
    print_library(my_library);

    // Free the library
    free_library(my_library);

    return 0;
}