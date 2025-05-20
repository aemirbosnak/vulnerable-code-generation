//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The ultimate embodiment of musical joy
struct Song {
    char *title;
    char *artist;
    char *album;
    int year;
    int duration; // in seconds
};

// A symphony of songs
struct Playlist {
    char *name;
    // We're not limiting the playlist size, go wild!
    struct Song **songs;
    int num_songs;
};

// Our beloved music library
struct Library {
    // A harmonious array of playlists
    struct Playlist **playlists;
    int num_playlists;
};

// A Grand Symphony of Functions

// Create a new song, the essence of melody
struct Song *create_song(char *title, char *artist, char *album, int year, int duration) {
    struct Song *song = malloc(sizeof(struct Song));
    song->title = strdup(title);
    song->artist = strdup(artist);
    song->album = strdup(album);
    song->year = year;
    song->duration = duration;
    return song;
}

// Construct a playlist, a dance of songs
struct Playlist *create_playlist(char *name) {
    struct Playlist *playlist = malloc(sizeof(struct Playlist));
    playlist->name = strdup(name);
    playlist->songs = malloc(0); // Initializing with an empty array
    playlist->num_songs = 0;
    return playlist;
}

// Establish our music library, the sanctuary of melodies
struct Library *create_library() {
    struct Library *library = malloc(sizeof(struct Library));
    library->playlists = malloc(0);
    library->num_playlists = 0;
    return library;
}

// Add a song to the playlist, a harmonious union
void add_song_to_playlist(struct Playlist *playlist, struct Song *song) {
    playlist->songs = realloc(playlist->songs, (playlist->num_songs + 1) * sizeof(struct Song *));
    playlist->songs[playlist->num_songs++] = song;
}

// Add a playlist to the library, expanding our musical horizons
void add_playlist_to_library(struct Library *library, struct Playlist *playlist) {
    library->playlists = realloc(library->playlists, (library->num_playlists + 1) * sizeof(struct Playlist *));
    library->playlists[library->num_playlists++] = playlist;
}

// Print the playlist, a serenade of song titles
void print_playlist(struct Playlist *playlist) {
    printf("Playlist: %s\n", playlist->name);
    for (int i = 0; i < playlist->num_songs; i++) {
        printf("\t%s\n", playlist->songs[i]->title);
    }
}

// Print the library, a grand symphony of playlists
void print_library(struct Library *library) {
    printf("Library:\n");
    for (int i = 0; i < library->num_playlists; i++) {
        print_playlist(library->playlists[i]);
    }
}

// Tear down the library, a bittersweet farewell to melodies
void destroy_library(struct Library *library) {
    for (int i = 0; i < library->num_playlists; i++) {
        free(library->playlists[i]->name);
        for (int j = 0; j < library->playlists[i]->num_songs; j++) {
            free(library->playlists[i]->songs[j]->title);
            free(library->playlists[i]->songs[j]->artist);
            free(library->playlists[i]->songs[j]->album);
            free(library->playlists[i]->songs[j]);
        }
        free(library->playlists[i]->songs);
        free(library->playlists[i]);
    }
    free(library->playlists);
    free(library);
}

// The maestro's baton, conducting the symphony
int main() {
    struct Library *library = create_library();

    struct Song *song1 = create_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360);
    struct Song *song2 = create_song("Imagine", "John Lennon", "Imagine", 1971, 180);
    struct Song *song3 = create_song("Strawberry Fields Forever", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967, 400);

    struct Playlist *playlist1 = create_playlist("Rock Anthems");
    struct Playlist *playlist2 = create_playlist("Peaceful Vibes");

    add_song_to_playlist(playlist1, song1);
    add_song_to_playlist(playlist2, song2);
    add_song_to_playlist(playlist2, song3);

    add_playlist_to_library(library, playlist1);
    add_playlist_to_library(library, playlist2);

    print_library(library);

    destroy_library(library);

    return 0;
}