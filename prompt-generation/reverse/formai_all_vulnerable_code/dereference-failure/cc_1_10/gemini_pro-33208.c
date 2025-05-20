//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} Song;

typedef struct {
    Song *songs;
    int num_songs;
} Library;

Library *create_library() {
    Library *library = malloc(sizeof(Library));
    library->songs = NULL;
    library->num_songs = 0;
    return library;
}

void add_song(Library *library, Song *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(Song));
    library->songs[library->num_songs] = *song;
    library->num_songs++;
}

void print_library(Library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s - %s (%s, %d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year);
    }
}

int main() {
    Library *library = create_library();

    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975};
    Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971};
    Song song3 = {"Hotel California", "Eagles", "Hotel California", 1976};

    add_song(library, &song1);
    add_song(library, &song2);
    add_song(library, &song3);

    print_library(library);

    return 0;
}