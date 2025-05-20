//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track_number;
};

struct library {
    struct song *songs;
    int num_songs;
    int capacity;
};

struct library *create_library(int capacity) {
    struct library *library = malloc(sizeof(struct library));
    library->songs = malloc(sizeof(struct song) * capacity);
    library->num_songs = 0;
    library->capacity = capacity;
    return library;
}

void destroy_library(struct library *library) {
    free(library->songs);
    free(library);
}

void add_song(struct library *library, struct song song) {
    if (library->num_songs == library->capacity) {
        library->capacity *= 2;
        library->songs = realloc(library->songs, sizeof(struct song) * library->capacity);
    }
    library->songs[library->num_songs] = song;
    library->num_songs++;
}

void print_library(struct library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s\n", library->songs[i].title);
        printf("%s\n", library->songs[i].artist);
        printf("%s\n", library->songs[i].album);
        printf("%d\n", library->songs[i].year);
        printf("%d\n", library->songs[i].track_number);
        printf("\n");
    }
}

int main() {
    struct library *library = create_library(10);

    struct song song1 = {"Song 1", "Artist 1", "Album 1", 2020, 1};
    add_song(library, song1);

    struct song song2 = {"Song 2", "Artist 2", "Album 2", 2021, 2};
    add_song(library, song2);

    struct song song3 = {"Song 3", "Artist 3", "Album 3", 2022, 3};
    add_song(library, song3);

    print_library(library);

    destroy_library(library);

    return 0;
}