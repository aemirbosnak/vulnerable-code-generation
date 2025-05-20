//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Music Library Management System (MLMS) structure
typedef struct MusicLibrary {
    char title[255];
    char artist[255];
    char genre[255];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Create a new music library item
MusicLibrary* createMusicItem() {
    MusicLibrary* item = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    item->next = NULL;
    return item;
}

// Insert a music library item into the list
void insertMusicItem(MusicLibrary* head, MusicLibrary* item) {
    if (head == NULL) {
        head = item;
    } else {
        item->next = head;
        head = item;
    }
}

// Search for a music library item by title
MusicLibrary* searchMusicItemByTitle(MusicLibrary* head, char* title) {
    MusicLibrary* item = head;
    while (item) {
        if (strcmp(item->title, title) == 0) {
            return item;
        }
        item = item->next;
    }
    return NULL;
}

// Print all music library items
void printMusicItems(MusicLibrary* head) {
    MusicLibrary* item = head;
    while (item) {
        printf("%s by %s (%d) - %s\n", item->title, item->artist, item->year, item->genre);
        item = item->next;
    }
}

int main() {
    // Create a new music library
    MusicLibrary* head = NULL;

    // Insert some music library items
    insertMusicItem(head, createMusicItem());
    insertMusicItem(head, createMusicItem());
    insertMusicItem(head, createMusicItem());

    // Search for a music library item by title
    MusicLibrary* item = searchMusicItemByTitle(head, "The Song");

    // Print the item
    if (item) {
        printf("%s by %s (%d) - %s\n", item->title, item->artist, item->year, item->genre);
    } else {
        printf("No item found\n");
    }

    // Print all music library items
    printMusicItems(head);

    return 0;
}