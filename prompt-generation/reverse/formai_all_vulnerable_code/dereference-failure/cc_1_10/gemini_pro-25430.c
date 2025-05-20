//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    int track;
} Song;

typedef struct {
    Song *songs;
    int numSongs;
} Library;

Library *createLibrary() {
    Library *library = malloc(sizeof(Library));
    library->songs = NULL;
    library->numSongs = 0;
    return library;
}

void addSong(Library *library, Song *song) {
    library->songs = realloc(library->songs, (library->numSongs + 1) * sizeof(Song));
    library->songs[library->numSongs] = *song;
    library->numSongs++;
}

void printLibrary(Library *library) {
    for (int i = 0; i < library->numSongs; i++) {
        printf("%s - %s (%s, %d, track %d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year, library->songs[i].track);
    }
}

void freeLibrary(Library *library) {
    for (int i = 0; i < library->numSongs; i++) {
        free(library->songs[i].title);
        free(library->songs[i].artist);
        free(library->songs[i].album);
    }
    free(library->songs);
    free(library);
}

int main() {
    Library *library = createLibrary();

    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    addSong(library, &song1);

    Song song2 = {"Imagine", "John Lennon", "Imagine", 1971, 1};
    addSong(library, &song2);

    Song song3 = {"Strawberry Fields Forever", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967, 7};
    addSong(library, &song3);

    printLibrary(library);

    freeLibrary(library);

    return 0;
}