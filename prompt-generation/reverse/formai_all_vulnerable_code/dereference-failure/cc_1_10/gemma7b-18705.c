//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Music Library Management System structure
typedef struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Create a linked list of music library items
MusicLibrary* head = NULL;

// Insert a new music library item into the linked list
void insertMusicItem(char* title, char* artist, char* genre, int year) {
    MusicLibrary* newMusicItem = malloc(sizeof(MusicLibrary));
    strcpy(newMusicItem->title, title);
    strcpy(newMusicItem->artist, artist);
    strcpy(newMusicItem->genre, genre);
    newMusicItem->year = year;
    newMusicItem->next = NULL;

    if (head == NULL) {
        head = newMusicItem;
    } else {
        MusicLibrary* currentMusicItem = head;
        while (currentMusicItem->next != NULL) {
            currentMusicItem = currentMusicItem->next;
        }
        currentMusicItem->next = newMusicItem;
    }
}

// Search for a music library item by title
MusicLibrary* searchMusicItemByTitle(char* title) {
    MusicLibrary* currentMusicItem = head;
    while (currentMusicItem) {
        if (strcmp(currentMusicItem->title, title) == 0) {
            return currentMusicItem;
        }
        currentMusicItem = currentMusicItem->next;
    }
    return NULL;
}

// Delete a music library item by title
void deleteMusicItemByTitle(char* title) {
    MusicLibrary* currentMusicItem = head;
    MusicLibrary* previousMusicItem = NULL;

    while (currentMusicItem) {
        if (strcmp(currentMusicItem->title, title) == 0) {
            if (previousMusicItem) {
                previousMusicItem->next = currentMusicItem->next;
            } else {
                head = currentMusicItem->next;
            }
            free(currentMusicItem);
            return;
        }
        previousMusicItem = currentMusicItem;
        currentMusicItem = currentMusicItem->next;
    }

    return;
}

// Print the music library items
void printMusicLibraryItems() {
    MusicLibrary* currentMusicItem = head;
    while (currentMusicItem) {
        printf("%s by %s (%d) - %s\n", currentMusicItem->title, currentMusicItem->artist, currentMusicItem->year, currentMusicItem->genre);
        currentMusicItem = currentMusicItem->next;
    }
}

int main() {
    // Insert some music library items
    insertMusicItem("The Wall", "Pink Floyd", "Rock", 1979);
    insertMusicItem("Thriller", "Michael Jackson", "Pop", 1987);
    insertMusicItem("Sgt. Pepper's Lonely Hearts Club Band", "The Beatles", "Rock", 1967);

    // Print the music library items
    printMusicLibraryItems();

    // Search for a music library item by title
    MusicLibrary* musicItem = searchMusicItemByTitle("The Wall");
    if (musicItem) {
        printf("Found music item: %s by %s (%d) - %s\n", musicItem->title, musicItem->artist, musicItem->year, musicItem->genre);
    }

    // Delete a music library item by title
    deleteMusicItemByTitle("Thriller");

    // Print the music library items after deletion
    printMusicLibraryItems();

    return 0;
}