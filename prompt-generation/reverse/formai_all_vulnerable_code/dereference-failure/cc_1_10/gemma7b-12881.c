//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music library information
typedef struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Create a linked list to store the music library
MusicLibrary* head = NULL;

// Function to add a new music entry to the library
void addMusicEntry(char* title, char* artist, char* genre, int year) {
    MusicLibrary* newMusic = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    strcpy(newMusic->title, title);
    strcpy(newMusic->artist, artist);
    strcpy(newMusic->genre, genre);
    newMusic->year = year;
    newMusic->next = NULL;

    if (head == NULL) {
        head = newMusic;
    } else {
        MusicLibrary* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newMusic;
    }
}

// Function to search the music library for a particular title
MusicLibrary* searchMusicByTitle(char* title) {
    MusicLibrary* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to display all music entries
void displayMusicLibrary() {
    MusicLibrary* temp = head;
    while (temp) {
        printf("%s by %s, %s, %d\n", temp->title, temp->artist, temp->genre, temp->year);
        temp = temp->next;
    }
}

// Main function
int main() {
    // Add some music entries to the library
    addMusicEntry("The Darkest Hour", "The Who", "Rock", 1969);
    addMusicEntry("Stairway to Heaven", "Led Zeppelin", "Rock", 1969);
    addMusicEntry("Yesterday", "The Beatles", "Pop", 1967);

    // Search for music by title
    MusicLibrary* music = searchMusicByTitle("Stairway to Heaven");
    if (music) {
        printf("%s by %s, %s, %d\n", music->title, music->artist, music->genre, music->year);
    } else {
        printf("No music found with that title.\n");
    }

    // Display all music entries
    displayMusicLibrary();

    return 0;
}