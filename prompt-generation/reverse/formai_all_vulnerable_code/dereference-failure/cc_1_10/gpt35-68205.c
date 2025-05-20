//FormAI DATASET v1.0 Category: Music Library Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for a song
typedef struct Song {
    char name[50];
    char artist[50];
    char album[50];
} Song;

// Define struct for a music library
typedef struct MusicLibrary {
    Song *songs;
    int num_songs;
} MusicLibrary;

// Define function to add a song to the library
void add_song(MusicLibrary *library, Song song) {
    library->num_songs++;
    library->songs = realloc(library->songs, sizeof(Song) * library->num_songs);
    library->songs[library->num_songs-1] = song;
}

// Define function to remove a song from the library
void remove_song(MusicLibrary *library, int song_index) {
    memmove(&library->songs[song_index], &library->songs[song_index+1], sizeof(Song) * (library->num_songs - song_index - 1));
    library->num_songs--;
    library->songs = realloc(library->songs, sizeof(Song) * library->num_songs);
}

// Define function to search for a song by name
void search_by_name(MusicLibrary library, char *name) {
    printf("Results for search by name:\n");
    for (int i = 0; i < library.num_songs; i++) {
        if (strcmp(library.songs[i].name, name) == 0) {
            printf("%s by %s from %s\n", library.songs[i].name, library.songs[i].artist, library.songs[i].album);
        }
    }
}

// Define function to search for a song by artist
void search_by_artist(MusicLibrary library, char *artist) {
    printf("Results for search by artist:\n");
    for (int i = 0; i < library.num_songs; i++) {
        if (strcmp(library.songs[i].artist, artist) == 0) {
            printf("%s by %s from %s\n", library.songs[i].name, library.songs[i].artist, library.songs[i].album);
        }
    }
}

int main() {
    MusicLibrary library;
    library.songs = NULL;
    library.num_songs = 0;
    
    // Add some test songs to the library
    add_song(&library, (Song){"Song 1", "Artist 1", "Album 1"});
    add_song(&library, (Song){"Song 2", "Artist 2", "Album 2"});
    add_song(&library, (Song){"Song 3", "Artist 1", "Album 1"});
    
    // Print out all songs in the library
    printf("All songs in music library:\n");
    for (int i = 0; i < library.num_songs; i++) {
        printf("%s by %s from %s\n", library.songs[i].name, library.songs[i].artist, library.songs[i].album);
    }
    
    // Search for a song by name and artist
    search_by_name(library, "Song 1");
    search_by_artist(library, "Artist 1");
    
    // Remove a song from the library
    remove_song(&library, 1);
    
    // Print out all songs in the library again
    printf("All songs in music library after song removal:\n");
    for (int i = 0; i < library.num_songs; i++) {
        printf("%s by %s from %s\n", library.songs[i].name, library.songs[i].artist, library.songs[i].album);
    }
    
    return 0;
}