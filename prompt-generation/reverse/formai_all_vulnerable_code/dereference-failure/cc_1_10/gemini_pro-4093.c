//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_number;
} song_t;

typedef struct library {
    song_t *songs;
    int num_songs;
} library_t;

void add_song(library_t *library, song_t song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(song_t));
    library->songs[library->num_songs] = song;
    library->num_songs++;
}

void print_library(library_t *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("Title: %s\n", library->songs[i].title);
        printf("Artist: %s\n", library->songs[i].artist);
        printf("Album: %s\n", library->songs[i].album);
        printf("Year: %d\n", library->songs[i].year);
        printf("Track Number: %d\n", library->songs[i].track_number);
        printf("\n");
    }
}

void free_library(library_t *library) {
    free(library->songs);
    free(library);
}

int main() {
    library_t *library = malloc(sizeof(library_t));
    library->songs = NULL;
    library->num_songs = 0;

    song_t song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    song_t song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 1};
    song_t song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 3};

    add_song(library, song1);
    add_song(library, song2);
    add_song(library, song3);

    print_library(library);

    free_library(library);

    return 0;
}