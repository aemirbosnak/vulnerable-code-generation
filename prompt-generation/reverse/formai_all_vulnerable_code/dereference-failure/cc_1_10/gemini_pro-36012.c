//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for storing music library data
typedef struct node {
    char *title;
    char *artist;
    char *album;
    struct node *next;
} node_t;

// Head and tail pointers for the music library linked list
node_t *head = NULL;
node_t *tail = NULL;

// Function to add a new song to the music library
void add_song(char *title, char *artist, char *album) {
    // Create a new node
    node_t *new_node = malloc(sizeof(node_t));

    // Initialize the new node's data
    new_node->title = strdup(title);
    new_node->artist = strdup(artist);
    new_node->album = strdup(album);
    new_node->next = NULL;

    // Append the new node to the end of the linked list
    if (tail == NULL) {
        head = new_node;
    } else {
        tail->next = new_node;
    }
    tail = new_node;
}

// Function to remove a song from the music library
void remove_song(char *title) {
    // Find the song to be removed
    node_t *current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            break;
        }
        current = current->next;
    }

    // If the song was found, remove it from the linked list
    if (current != NULL) {
        if (current == head) {
            head = current->next;
        } else {
            // Find the previous node
            node_t *previous = head;
            while (previous->next != current) {
                previous = previous->next;
            }

            // Unlink the current node from the linked list
            previous->next = current->next;
        }

        // Free the memory allocated for the song
        free(current->title);
        free(current->artist);
        free(current->album);
        free(current);
    }
}

// Function to print the music library
void print_library() {
    node_t *current = head;
    while (current != NULL) {
        printf("%s - %s (%s)\n", current->title, current->artist, current->album);
        current = current->next;
    }
}

// Main function
int main() {
    // Add some songs to the music library
    add_song("Bohemian Rhapsody", "Queen", "A Night at the Opera");
    add_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV");
    add_song("Hotel California", "The Eagles", "Hotel California");
    add_song("Imagine", "John Lennon", "Imagine");
    add_song("Smells Like Teen Spirit", "Nirvana", "Nevermind");

    // Print the music library
    printf("Music Library:\n");
    print_library();

    // Remove a song from the music library
    remove_song("Imagine");

    // Print the updated music library
    printf("\nUpdated Music Library:\n");
    print_library();

    return 0;
}