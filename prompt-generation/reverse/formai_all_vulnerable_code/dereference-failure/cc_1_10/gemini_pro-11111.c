//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char *title;
    char *artist;
    char *album;
    int year;
    int track;
};

struct playlist {
    char *name;
    struct song *songs;
    int num_songs;
};

struct library {
    struct playlist *playlists;
    int num_playlists;
};

struct library *create_library() {
    struct library *library = malloc(sizeof(struct library));
    library->playlists = NULL;
    library->num_playlists = 0;
    return library;
}

void add_playlist(struct library *library, char *name) {
    library->playlists = realloc(library->playlists, (library->num_playlists + 1) * sizeof(struct playlist));
    library->playlists[library->num_playlists].name = strdup(name);
    library->playlists[library->num_playlists].songs = NULL;
    library->playlists[library->num_playlists].num_songs = 0;
    library->num_playlists++;
}

void add_song(struct library *library, char *playlist_name, char *title, char *artist, char *album, int year, int track) {
    int i;
    for (i = 0; i < library->num_playlists; i++) {
        if (strcmp(library->playlists[i].name, playlist_name) == 0) {
            library->playlists[i].songs = realloc(library->playlists[i].songs, (library->playlists[i].num_songs + 1) * sizeof(struct song));
            library->playlists[i].songs[library->playlists[i].num_songs].title = strdup(title);
            library->playlists[i].songs[library->playlists[i].num_songs].artist = strdup(artist);
            library->playlists[i].songs[library->playlists[i].num_songs].album = strdup(album);
            library->playlists[i].songs[library->playlists[i].num_songs].year = year;
            library->playlists[i].songs[library->playlists[i].num_songs].track = track;
            library->playlists[i].num_songs++;
            break;
        }
    }
}

void print_library(struct library *library) {
    int i, j;
    for (i = 0; i < library->num_playlists; i++) {
        printf("%s:\n", library->playlists[i].name);
        for (j = 0; j < library->playlists[i].num_songs; j++) {
            printf("    %d. %s (%s, %s, %d)\n", library->playlists[i].songs[j].track, library->playlists[i].songs[j].title, library->playlists[i].songs[j].artist, library->playlists[i].songs[j].album, library->playlists[i].songs[j].year);
        }
    }
}

void free_library(struct library *library) {
    int i, j;
    for (i = 0; i < library->num_playlists; i++) {
        for (j = 0; j < library->playlists[i].num_songs; j++) {
            free(library->playlists[i].songs[j].title);
            free(library->playlists[i].songs[j].artist);
            free(library->playlists[i].songs[j].album);
        }
        free(library->playlists[i].songs);
        free(library->playlists[i].name);
    }
    free(library->playlists);
    free(library);
}

int main() {
    struct library *library = create_library();

    add_playlist(library, "Classical");
    add_song(library, "Classical", "Symphony No. 5", "Beethoven", "Symphony No. 5", 1808, 1);
    add_song(library, "Classical", "Piano Concerto No. 1", "Tchaikovsky", "Piano Concerto No. 1", 1875, 1);

    add_playlist(library, "Rock");
    add_song(library, "Rock", "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1);
    add_song(library, "Rock", "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4);

    add_playlist(library, "Pop");
    add_song(library, "Pop", "Thriller", "Michael Jackson", "Thriller", 1982, 1);
    add_song(library, "Pop", "Like a Prayer", "Madonna", "Like a Prayer", 1989, 1);

    print_library(library);

    free_library(library);

    return 0;
}