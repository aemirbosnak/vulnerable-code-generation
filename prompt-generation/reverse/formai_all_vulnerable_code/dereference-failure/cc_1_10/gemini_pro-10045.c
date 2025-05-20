//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
} Song;

typedef struct {
    Song **songs;
    int num_songs;
} Library;

Library *create_library() {
    Library *library = malloc(sizeof(Library));
    library->songs = malloc(0);
    library->num_songs = 0;
    return library;
}

void add_song_to_library(Library *library, Song *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(Song *));
    library->songs[library->num_songs++] = song;
}

void print_library(Library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s\n", library->songs[i]->title);
        printf("%s\n", library->songs[i]->artist);
        printf("%s\n", library->songs[i]->album);
        printf("%d\n\n", library->songs[i]->year);
    }
}

Song *create_song(char *title, char *artist, char *album, int year) {
    Song *song = malloc(sizeof(Song));
    song->title = title;
    song->artist = artist;
    song->album = album;
    song->year = year;
    return song;
}

int main() {
    Library *library = create_library();
    add_song_to_library(library, create_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975));
    add_song_to_library(library, create_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971));
    add_song_to_library(library, create_song("Imagine", "John Lennon", "Imagine", 1971));
    add_song_to_library(library, create_song("Hotel California", "Eagles", "Hotel California", 1976));
    add_song_to_library(library, create_song("Thriller", "Michael Jackson", "Thriller", 1982));
    print_library(library);
    return 0;
}