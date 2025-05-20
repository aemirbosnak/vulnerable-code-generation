//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: standalone
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

// Function to insert a new music library item at the end
void insertAtEnd(MusicLibrary** head, MusicLibrary* newMusic) {
    if (*head == NULL) {
        *head = newMusic;
    } else {
        (*head)->next = newMusic;
        *head = newMusic;
    }
}

// Function to search for a music library item by title
MusicLibrary* searchByTitle(MusicLibrary* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to search for a music library item by artist
MusicLibrary* searchByArtist(MusicLibrary* head, char* artist) {
    while (head) {
        if (strcmp(head->artist, artist) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to search for a music library item by genre
MusicLibrary* searchByGenre(MusicLibrary* head, char* genre) {
    while (head) {
        if (strcmp(head->genre, genre) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to print the music library
void printMusicLibrary(MusicLibrary* head) {
    while (head) {
        printf("%s - %s (%d) - %s\n", head->title, head->artist, head->year, head->genre);
        head = head->next;
    }
}

int main() {
    MusicLibrary* musicLibrary = NULL;

    // Insert some music library items
    MusicLibrary* newMusic1 = malloc(sizeof(MusicLibrary));
    strcpy(newMusic1->title, "The Darkest Passenger");
    strcpy(newMusic1->artist, "The Mars Volta");
    strcpy(newMusic1->genre, "Rock");
    newMusic1->year = 2003;
    insertAtEnd(&musicLibrary, newMusic1);

    MusicLibrary* newMusic2 = malloc(sizeof(MusicLibrary));
    strcpy(newMusic2->title, "Thriller");
    strcpy(newMusic2->artist, "Michael Jackson");
    strcpy(newMusic2->genre, "Pop");
    newMusic2->year = 1987;
    insertAtEnd(&musicLibrary, newMusic2);

    MusicLibrary* newMusic3 = malloc(sizeof(MusicLibrary));
    strcpy(newMusic3->title, "Sgt. Pepper's Lonely Hearts Club Band");
    strcpy(newMusic3->artist, "The Beatles");
    strcpy(newMusic3->genre, "Rock");
    newMusic3->year = 1967;
    insertAtEnd(&musicLibrary, newMusic3);

    // Search for music library item by title
    MusicLibrary* foundMusic = searchByTitle(musicLibrary, "The Darkest Passenger");
    if (foundMusic) {
        printf("Found music library item: %s - %s (%d) - %s\n", foundMusic->title, foundMusic->artist, foundMusic->year, foundMusic->genre);
    } else {
        printf("Music library item not found.\n");
    }

    // Search for music library item by artist
    foundMusic = searchByArtist(musicLibrary, "The Mars Volta");
    if (foundMusic) {
        printf("Found music library item: %s - %s (%d) - %s\n", foundMusic->title, foundMusic->artist, foundMusic->year, foundMusic->genre);
    } else {
        printf("Music library item not found.\n");
    }

    // Search for music library item by genre
    foundMusic = searchByGenre(musicLibrary, "Rock");
    if (foundMusic) {
        printf("Found music library item: %s - %s (%d) - %s\n", foundMusic->title, foundMusic->artist, foundMusic->year, foundMusic->genre);
    } else {
        printf("Music library item not found.\n");
    }

    // Print the music library
    printMusicLibrary(musicLibrary);

    return 0;
}