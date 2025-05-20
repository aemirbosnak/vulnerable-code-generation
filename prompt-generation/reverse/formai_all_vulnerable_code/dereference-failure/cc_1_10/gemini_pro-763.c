//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
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
} music_entry;

// Create a new music library entry
music_entry *create_entry(char *title, char *artist, char *album, int year) {
    music_entry *entry = (music_entry *)malloc(sizeof(music_entry));
    entry->title = strdup(title);
    entry->artist = strdup(artist);
    entry->album = strdup(album);
    entry->year = year;
    entry->next = NULL;
    return entry;
}

// Insert a new music library entry into the linked list
void insert_entry(music_entry **head, music_entry *new_entry) {
    if (*head == NULL) {
        *head = new_entry;
    } else {
        music_entry *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

// Print the music library
void print_library(music_entry *head) {
    music_entry *current = head;
    while (current != NULL) {
        printf("%s - %s (%s, %d)\n", current->title, current->artist, current->album, current->year);
        current = current->next;
    }
}

// Free the memory allocated for the music library
void free_library(music_entry *head) {
    music_entry *current = head;
    while (current != NULL) {
        music_entry *next = current->next;
        free(current->title);
        free(current->artist);
        free(current->album);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a new music library
    music_entry *head = NULL;

    // Insert some music library entries into the linked list
    insert_entry(&head, create_entry("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975));
    insert_entry(&head, create_entry("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971));
    insert_entry(&head, create_entry("Hotel California", "The Eagles", "Hotel California", 1976));
    insert_entry(&head, create_entry("Imagine", "John Lennon", "Imagine", 1971));
    insert_entry(&head, create_entry("Hey Jude", "The Beatles", "Hey Jude", 1968));

    // Print the music library
    print_library(head);

    // Free the memory allocated for the music library
    free_library(head);

    return 0;
}