//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a music library entry
typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    int track;
} MusicEntry;

// Node in a linked list of music library entries
typedef struct MusicNode {
    MusicEntry *entry;
    struct MusicNode *next;
} MusicNode;

// Function to create a new music library entry
MusicEntry *create_music_entry(char *title, char *artist, char *album, int year, int track) {
    MusicEntry *entry = malloc(sizeof(MusicEntry));
    entry->title = strdup(title);
    entry->artist = strdup(artist);
    entry->album = strdup(album);
    entry->year = year;
    entry->track = track;
    return entry;
}

// Function to create a new music node
MusicNode *create_music_node(MusicEntry *entry) {
    MusicNode *node = malloc(sizeof(MusicNode));
    node->entry = entry;
    node->next = NULL;
    return node;
}

// Function to add a music entry to a linked list
void add_music_entry(MusicNode **head, MusicEntry *entry) {
    MusicNode *new_node = create_music_node(entry);
    if (*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        *head = new_node;
    }
}

// Function to print a music entry
void print_music_entry(MusicEntry *entry) {
    printf("%s by %s from the album %s (%d)\n", entry->title, entry->artist, entry->album, entry->year);
}

// Function to print a linked list of music entries
void print_music_library(MusicNode *head) {
    MusicNode *current = head;
    while (current != NULL) {
        print_music_entry(current->entry);
        current = current->next;
    }
}

// Function to free a music entry
void free_music_entry(MusicEntry *entry) {
    free(entry->title);
    free(entry->artist);
    free(entry->album);
    free(entry);
}

// Function to free a linked list of music entries
void free_music_library(MusicNode *head) {
    MusicNode *current = head;
    while (current != NULL) {
        MusicNode *next = current->next;
        free_music_entry(current->entry);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create a linked list of music entries
    MusicNode *head = NULL;
    add_music_entry(&head, create_music_entry("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1));
    add_music_entry(&head, create_music_entry("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4));
    add_music_entry(&head, create_music_entry("Hotel California", "Eagles", "Hotel California", 1976, 3));
    add_music_entry(&head, create_music_entry("Thriller", "Michael Jackson", "Thriller", 1982, 1));
    add_music_entry(&head, create_music_entry("Imagine", "John Lennon", "Imagine", 1971, 3));

    // Print the linked list of music entries
    print_music_library(head);

    // Free the linked list of music entries
    free_music_library(head);

    return 0;
}