//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the music library
typedef struct {
    char title[100];
    char artist[100];
    char genre[50];
    int duration;
} Music;

// Function to add a song to the library
void addSong(Music* library, int size, int index, char* title, char* artist, char* genre, int duration) {
    strcpy(library[index].title, title);
    strcpy(library[index].artist, artist);
    strcpy(library[index].genre, genre);
    library[index].duration = duration;
}

// Function to search for a song by title
int searchByTitle(Music* library, int size, char* title) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(library[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to search for a song by artist
int searchByArtist(Music* library, int size, char* artist) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(library[i].artist, artist) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to search for a song by genre
int searchByGenre(Music* library, int size, char* genre) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(library[i].genre, genre) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to print the library
void printLibrary(Music* library, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Title: %s\nArtist: %s\nGenre: %s\nDuration: %d seconds\n\n", library[i].title, library[i].artist, library[i].genre, library[i].duration);
    }
}

// Main function
int main() {
    int size = 0;
    Music* library = (Music*)malloc(sizeof(Music));

    // Add songs to the library
    addSong(library, size, 0, "Bohemian Rhapsody", "Queen", "Rock", 183);
    addSong(library, size, 1, "Stairway to Heaven", "Led Zeppelin", "Rock", 439);
    addSong(library, size, 2, "Thriller", "Michael Jackson", "Pop", 254);

    // Print the library
    printLibrary(library, size);

    // Search for a song by title
    int index = searchByTitle(library, size, "Thriller");
    if (index!= -1) {
        printf("Found song by title: %s\n", library[index].title);
    } else {
        printf("Song not found.\n");
    }

    // Search for a song by artist
    index = searchByArtist(library, size, "Michael Jackson");
    if (index!= -1) {
        printf("Found song by artist: %s\n", library[index].title);
    } else {
        printf("Song not found.\n");
    }

    // Search for a song by genre
    index = searchByGenre(library, size, "Pop");
    if (index!= -1) {
        printf("Found song by genre: %s\n", library[index].title);
    } else {
        printf("Song not found.\n");
    }

    // Free memory
    free(library);
    return 0;
}