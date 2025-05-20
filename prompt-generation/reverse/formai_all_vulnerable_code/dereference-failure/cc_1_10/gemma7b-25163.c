//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for a music library entry
typedef struct MusicEntry {
    char title[50];
    char artist[50];
    char genre[20];
    int year;
    struct MusicEntry* next;
} MusicEntry;

// Create a linked list of music library entries
MusicEntry* head = NULL;

// Function to add a new music entry to the library
void addMusicEntry(char* title, char* artist, char* genre, int year) {
    MusicEntry* newEntry = (MusicEntry*)malloc(sizeof(MusicEntry));
    strcpy(newEntry->title, title);
    strcpy(newEntry->artist, artist);
    strcpy(newEntry->genre, genre);
    newEntry->year = year;
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        MusicEntry* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEntry;
    }
}

// Function to search for a music entry by title
MusicEntry* searchMusicEntryByTitle(char* title) {
    MusicEntry* currentEntry = head;
    while (currentEntry) {
        if (strcmp(currentEntry->title, title) == 0) {
            return currentEntry;
        }
        currentEntry = currentEntry->next;
    }
    return NULL;
}

// Function to search for a music entry by artist
MusicEntry* searchMusicEntryByArtist(char* artist) {
    MusicEntry* currentEntry = head;
    while (currentEntry) {
        if (strcmp(currentEntry->artist, artist) == 0) {
            return currentEntry;
        }
        currentEntry = currentEntry->next;
    }
    return NULL;
}

// Function to search for a music entry by genre
MusicEntry* searchMusicEntryByGenre(char* genre) {
    MusicEntry* currentEntry = head;
    while (currentEntry) {
        if (strcmp(currentEntry->genre, genre) == 0) {
            return currentEntry;
        }
        currentEntry = currentEntry->next;
    }
    return NULL;
}

// Function to print all music entries
void printMusicEntries() {
    MusicEntry* currentEntry = head;
    while (currentEntry) {
        printf("%s by %s, %s, %d\n", currentEntry->title, currentEntry->artist, currentEntry->genre, currentEntry->year);
        currentEntry = currentEntry->next;
    }
}

int main() {
    // Add some music entries to the library
    addMusicEntry("Bohemian Rhapsody", "Queen", "Rock", 1975);
    addMusicEntry("Thriller", "Michael Jackson", "Pop", 1982);
    addMusicEntry("Stairway to Heaven", "Led Zeppelin", "Rock", 1969);
    addMusicEntry("Back in the U.S.A.", "Bruce Springsteen", "Rock", 1984);

    // Search for a music entry by title
    MusicEntry* entry = searchMusicEntryByTitle("Bohemian Rhapsody");
    if (entry) {
        printf("Found entry: %s by %s, %s, %d\n", entry->title, entry->artist, entry->genre, entry->year);
    } else {
        printf("Entry not found.\n");
    }

    // Search for a music entry by artist
    entry = searchMusicEntryByArtist("Michael Jackson");
    if (entry) {
        printf("Found entry: %s by %s, %s, %d\n", entry->title, entry->artist, entry->genre, entry->year);
    } else {
        printf("Entry not found.\n");
    }

    // Search for a music entry by genre
    entry = searchMusicEntryByGenre("Rock");
    if (entry) {
        printf("Found entry: %s by %s, %s, %d\n", entry->title, entry->artist, entry->genre, entry->year);
    } else {
        printf("Entry not found.\n");
    }

    // Print all music entries
    printMusicEntries();

    return 0;
}