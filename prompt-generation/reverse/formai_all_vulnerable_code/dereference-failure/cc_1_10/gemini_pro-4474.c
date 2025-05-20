//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library entry
typedef struct music_entry {
    char *title;
    char *artist;
    char *album;
    int year;
    struct music_entry *next;
} music_entry_t;

// Create a new music library entry
music_entry_t *create_entry(char *title, char *artist, char *album, int year) {
    music_entry_t *new_entry = malloc(sizeof(music_entry_t));
    new_entry->title = strdup(title);
    new_entry->artist = strdup(artist);
    new_entry->album = strdup(album);
    new_entry->year = year;
    new_entry->next = NULL;
    return new_entry;
}

// Free a music library entry
void free_entry(music_entry_t *entry) {
    free(entry->title);
    free(entry->artist);
    free(entry->album);
    free(entry);
}

// Add a new music library entry to the end of a linked list
void add_entry(music_entry_t **head, music_entry_t *new_entry) {
    if (*head == NULL) {
        *head = new_entry;
    } else {
        music_entry_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

// Print a music library entry
void print_entry(music_entry_t *entry) {
    printf("%s by %s from the album %s (%d)\n", entry->title, entry->artist, entry->album, entry->year);
}

// Print a linked list of music library entries
void print_list(music_entry_t *head) {
    music_entry_t *current = head;
    while (current != NULL) {
        print_entry(current);
        current = current->next;
    }
}

// Free a linked list of music library entries
void free_list(music_entry_t *head) {
    music_entry_t *current = head;
    while (current != NULL) {
        music_entry_t *next = current->next;
        free_entry(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a new music library
    music_entry_t *head = NULL;

    // Add some entries to the library
    add_entry(&head, create_entry("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975));
    add_entry(&head, create_entry("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971));
    add_entry(&head, create_entry("Hotel California", "Eagles", "Hotel California", 1976));
    add_entry(&head, create_entry("Imagine", "John Lennon", "Imagine", 1971));
    add_entry(&head, create_entry("What a Wonderful World", "Louis Armstrong", "The Complete Hot Five and Hot Seven Recordings", 1928));

    // Print the library
    print_list(head);

    // Free the library
    free_list(head);

    return 0;
}