//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music library information
typedef struct MusicLibrary {
    char title[255];
    char artist[255];
    char genre[255];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Create a linked list to store music library information
MusicLibrary* head = NULL;

// Function to insert a new music library item into the linked list
void insertMusicItem(char* title, char* artist, char* genre, int year) {
    MusicLibrary* newMusicItem = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    strcpy(newMusicItem->title, title);
    strcpy(newMusicItem->artist, artist);
    strcpy(newMusicItem->genre, genre);
    newMusicItem->year = year;
    newMusicItem->next = NULL;

    if (head == NULL) {
        head = newMusicItem;
    } else {
        MusicLibrary* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newMusicItem;
    }
}

// Function to search for a music library item by title
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

// Function to search for a music library item by artist
MusicLibrary* searchMusicItemByArtist(char* artist) {
    MusicLibrary* currentMusicItem = head;
    while (currentMusicItem) {
        if (strcmp(currentMusicItem->artist, artist) == 0) {
            return currentMusicItem;
        }
        currentMusicItem = currentMusicItem->next;
    }
    return NULL;
}

// Function to search for a music library item by genre
MusicLibrary* searchMusicItemByGenre(char* genre) {
    MusicLibrary* currentMusicItem = head;
    while (currentMusicItem) {
        if (strcmp(currentMusicItem->genre, genre) == 0) {
            return currentMusicItem;
        }
        currentMusicItem = currentMusicItem->next;
    }
    return NULL;
}

// Function to search for a music library item by year
MusicLibrary* searchMusicItemByYear(int year) {
    MusicLibrary* currentMusicItem = head;
    while (currentMusicItem) {
        if (currentMusicItem->year == year) {
            return currentMusicItem;
        }
        currentMusicItem = currentMusicItem->next;
    }
    return NULL;
}

// Main function
int main() {
    insertMusicItem("The Dark Side of the Moon", "Pink Floyd", "Rock", 1973);
    insertMusicItem("Thriller", "Michael Jackson", "Pop", 1982);
    insertMusicItem("Stairway to Heaven", "Led Zeppelin", "Rock", 1969);
    insertMusicItem("Bohemian Rhapsody", "Queen", "Rock", 1975);

    MusicLibrary* searchResult = searchMusicItemByTitle("The Dark Side of the Moon");
    if (searchResult) {
        printf("Title: %s\n", searchResult->title);
        printf("Artist: %s\n", searchResult->artist);
        printf("Genre: %s\n", searchResult->genre);
        printf("Year: %d\n", searchResult->year);
    } else {
        printf("No music item found.\n");
    }

    return 0;
}