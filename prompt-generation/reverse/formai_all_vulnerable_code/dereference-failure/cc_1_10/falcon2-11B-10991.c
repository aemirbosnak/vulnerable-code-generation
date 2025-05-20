//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int length;
} Song;

typedef struct {
    Song* songs;
    int num_songs;
    int capacity;
} Library;

void add_song(Library* lib, const char* title, const char* artist, const char* genre) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    strncpy(new_song->title, title, MAX_TITLE_LENGTH);
    strncpy(new_song->artist, artist, MAX_ARTIST_LENGTH);
    strncpy(new_song->genre, genre, MAX_GENRE_LENGTH);
    new_song->length = strlen(new_song->title) + strlen(new_song->artist) + strlen(new_song->genre);
    if (lib->num_songs == lib->capacity) {
        lib->capacity *= 2;
        lib->songs = (Song*)realloc(lib->songs, lib->capacity * sizeof(Song));
    }
    lib->songs[lib->num_songs++] = *new_song;
}

void display_songs(Library* lib) {
    printf("Library Contents:\n");
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%d) %s - %s (%s)\n", i + 1, lib->songs[i].title, lib->songs[i].artist, lib->songs[i].genre);
    }
}

int main() {
    Library library;
    library.num_songs = 0;
    library.capacity = 10;
    library.songs = (Song*)malloc(library.capacity * sizeof(Song));

    add_song(&library, "Bohemian Rhapsody", "Queen", "Rock");
    add_song(&library, "Imagine", "John Lennon", "Pop");
    add_song(&library, "Hotel California", "Eagles", "Rock");

    display_songs(&library);

    return 0;
}