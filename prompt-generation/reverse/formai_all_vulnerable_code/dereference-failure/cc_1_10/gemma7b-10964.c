//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the Music Library Management System (MLMS) structure
typedef struct MusicLibrary {
    char title[255];
    char artist[255];
    char genre[255];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a new music entry into the library
void insertMusic(MusicLibrary** head) {
    MusicLibrary* newMusic = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    printf("Enter the title: ");
    scanf("%s", newMusic->title);
    printf("Enter the artist: ");
    scanf("%s", newMusic->artist);
    printf("Enter the genre: ");
    scanf("%s", newMusic->genre);
    printf("Enter the year: ");
    scanf("%d", &newMusic->year);
    newMusic->next = NULL;

    if (*head == NULL) {
        *head = newMusic;
    } else {
        (*head)->next = newMusic;
    }
}

// Function to search for music by title
MusicLibrary* searchMusicByTitle(MusicLibrary* head, char* title) {
    MusicLibrary* current = head;
    while (current) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to search for music by artist
MusicLibrary* searchMusicByArtist(MusicLibrary* head, char* artist) {
    MusicLibrary* current = head;
    while (current) {
        if (strcmp(current->artist, artist) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to search for music by genre
MusicLibrary* searchMusicByGenre(MusicLibrary* head, char* genre) {
    MusicLibrary* current = head;
    while (current) {
        if (strcmp(current->genre, genre) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete music from the library
void deleteMusic(MusicLibrary* head, char* title) {
    MusicLibrary* current = head;
    MusicLibrary* previous = NULL;

    while (current) {
        if (strcmp(current->title, title) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Music not found.\n");
}

int main() {
    MusicLibrary* head = NULL;

    // Insert some music into the library
    insertMusic(&head);
    insertMusic(&head);
    insertMusic(&head);

    // Search for music by title
    MusicLibrary* music = searchMusicByTitle(head, "Song 1");
    if (music) {
        printf("Title: %s\n", music->title);
        printf("Artist: %s\n", music->artist);
        printf("Genre: %s\n", music->genre);
        printf("Year: %d\n", music->year);
    }

    // Search for music by artist
    music = searchMusicByArtist(head, "Artist 1");
    if (music) {
        printf("Title: %s\n", music->title);
        printf("Artist: %s\n", music->artist);
        printf("Genre: %s\n", music->genre);
        printf("Year: %d\n", music->year);
    }

    // Search for music by genre
    music = searchMusicByGenre(head, "Rock");
    if (music) {
        printf("Title: %s\n", music->title);
        printf("Artist: %s\n", music->artist);
        printf("Genre: %s\n", music->genre);
        printf("Year: %d\n", music->year);
    }

    // Delete music from the library
    deleteMusic(head, "Song 1");

    return 0;
}