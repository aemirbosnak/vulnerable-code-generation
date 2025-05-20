//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music_library {
    char *artist;
    char *album;
    int year;
    char *genre;
    struct music_library *next;
} music_library_t;

music_library_t *create_library(void) {
    return NULL;
}

void add_song(music_library_t **library, char *artist, char *album, int year, char *genre) {
    music_library_t *new_song = malloc(sizeof(music_library_t));
    new_song->artist = artist;
    new_song->album = album;
    new_song->year = year;
    new_song->genre = genre;
    new_song->next = *library;
    *library = new_song;
}

void print_library(music_library_t *library) {
    while (library != NULL) {
        printf("%s - %s (%d) [%s]\n", library->artist, library->album, library->year, library->genre);
        library = library->next;
    }
}

void free_library(music_library_t *library) {
    while (library != NULL) {
        music_library_t *next = library->next;
        free(library->artist);
        free(library->album);
        free(library->genre);
        free(library);
        library = next;
    }
}

int main(void) {
    music_library_t *library = create_library();
    add_song(&library, "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967, "Rock");
    add_song(&library, "Led Zeppelin", "Led Zeppelin IV", 1971, "Hard Rock");
    add_song(&library, "Bob Dylan", "Blood on the Tracks", 1975, "Folk Rock");
    add_song(&library, "The Rolling Stones", "Exile on Main St.", 1972, "Rock");
    add_song(&library, "Pink Floyd", "The Dark Side of the Moon", 1973, "Progressive Rock");
    print_library(library);
    free_library(library);
    return 0;
}