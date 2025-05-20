//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: romantic
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

// Create a new music library item
MusicLibrary* createMusicLibraryItem(char* title, char* artist, char* genre, int year) {
    MusicLibrary* newMusicLibraryItem = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    strcpy(newMusicLibraryItem->title, title);
    strcpy(newMusicLibraryItem->artist, artist);
    strcpy(newMusicLibraryItem->genre, genre);
    newMusicLibraryItem->year = year;
    newMusicLibraryItem->next = NULL;
    return newMusicLibraryItem;
}

// Insert a new music library item into the head of the list
void insertMusicLibraryItem(MusicLibrary** head, MusicLibrary* newMusicLibraryItem) {
    if (*head == NULL) {
        *head = newMusicLibraryItem;
    } else {
        (*head)->next = newMusicLibraryItem;
        *head = newMusicLibraryItem;
    }
}

// Print all music library items
void printMusicLibraryItems(MusicLibrary* head) {
    MusicLibrary* currentMusicLibraryItem = head;
    while (currentMusicLibraryItem) {
        printf("%s by %s (%d) - %s\n", currentMusicLibraryItem->title, currentMusicLibraryItem->artist, currentMusicLibraryItem->year, currentMusicLibraryItem->genre);
        currentMusicLibraryItem = currentMusicLibraryItem->next;
    }
}

int main() {
    MusicLibrary* musicLibrary = NULL;
    insertMusicLibraryItem(&musicLibrary, createMusicLibraryItem("The Sound of Music", "Julie Andrews", "Musical", 1965));
    insertMusicLibraryItem(&musicLibrary, createMusicLibraryItem("Thriller", "Michael Jackson", "Pop", 1982));
    insertMusicLibraryItem(&musicLibrary, createMusicLibraryItem("Bohemian Rhapsody", "Queen", "Rock", 1975));
    insertMusicLibraryItem(&musicLibrary, createMusicLibraryItem("Happy Together", "The Turtles", "Pop", 1967));

    printMusicLibraryItems(musicLibrary);

    return 0;
}