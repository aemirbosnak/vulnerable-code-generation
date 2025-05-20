//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *artist;
    int year;
    int bpm;
    char *genre;
} song;

typedef struct {
    song *songs;
    int num_songs;
} library;

library *create_library() {
    library *lib = (library *) malloc(sizeof(library));
    lib->songs = (song *) malloc(0);
    lib->num_songs = 0;
    return lib;
}

void add_song(library *lib, song *s) {
    lib->songs = (song *) realloc(lib->songs, (lib->num_songs + 1) * sizeof(song));
    lib->songs[lib->num_songs++] = *s;
}

void print_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s - %s (%d bpm, %d, %s)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].bpm, lib->songs[i].year, lib->songs[i].genre);
    }
}

void free_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        free(lib->songs[i].title);
        free(lib->songs[i].artist);
        free(lib->songs[i].genre);
    }
    free(lib->songs);
    free(lib);
}

int main() {
    library *lib = create_library();
    
    song s1 = {"Bohemian Rhapsody", "Queen", 1975, 141, "Rock"};
    song s2 = {"Stairway to Heaven", "Led Zeppelin", 1971, 120, "Rock"};
    song s3 = {"Hotel California", "Eagles", 1976, 130, "Rock"};
    song s4 = {"Thriller", "Michael Jackson", 1982, 120, "Pop"};
    song s5 = {"Billie Jean", "Michael Jackson", 1982, 105, "Pop"};
    
    add_song(lib, &s1);
    add_song(lib, &s2);
    add_song(lib, &s3);
    add_song(lib, &s4);
    add_song(lib, &s5);
    
    print_library(lib);
    
    free_library(lib);
    
    return 0;
}