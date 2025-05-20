//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node for the linked list
struct node {
    char *title;
    char *artist;
    char *album;
    int year;
    struct node *next;
};

// Define the head of the linked list
struct node *head = NULL;

// Function to create a new node
struct node *create_node(char *title, char *artist, char *album, int year) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->title = malloc(strlen(title) + 1);
    strcpy(new_node->title, title);
    new_node->artist = malloc(strlen(artist) + 1);
    strcpy(new_node->artist, artist);
    new_node->album = malloc(strlen(album) + 1);
    strcpy(new_node->album, album);
    new_node->year = year;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node to the linked list
void add_node(char *title, char *artist, char *album, int year) {
    struct node *new_node = create_node(title, artist, album, year);
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to print the linked list
void print_list() {
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%s by %s from the album %s (%d)\n",
               current_node->title, current_node->artist, current_node->album, current_node->year);
        current_node = current_node->next;
    }
}

// Function to free the linked list
void free_list() {
    struct node *current_node = head;
    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node->title);
        free(current_node->artist);
        free(current_node->album);
        free(current_node);
        current_node = next_node;
    }
}

// Main function
int main() {
    // Add some songs to the library
    add_node("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
    add_node("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
    add_node("Hotel California", "Eagles", "Hotel California", 1976);
    add_node("Imagine", "John Lennon", "Imagine", 1971);
    add_node("Strawberry Fields Forever", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967);

    // Print the library
    print_list();

    // Free the library
    free_list();

    return 0;
}