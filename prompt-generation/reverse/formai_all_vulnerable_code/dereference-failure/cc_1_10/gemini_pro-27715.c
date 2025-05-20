//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the song structure
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
} Song;

// Define the library structure
typedef struct library {
    Song *songs;
    int numSongs;
} Library;

// Create a new library
Library *createLibrary() {
    Library *library = (Library *)malloc(sizeof(Library));
    library->songs = NULL;
    library->numSongs = 0;
    return library;
}

// Add a song to the library
void addSong(Library *library, Song *song) {
    library->songs = (Song *)realloc(library->songs, (library->numSongs + 1) * sizeof(Song));
    library->songs[library->numSongs] = *song;
    library->numSongs++;
}

// Print the library
void printLibrary(Library *library) {
    for (int i = 0; i < library->numSongs; i++) {
        printf("%s by %s from the album %s (%d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].album, library->songs[i].year);
    }
}

// Search for a song by title
Song *searchSongByTitle(Library *library, char *title) {
    for (int i = 0; i < library->numSongs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Search for a song by artist
Song *searchSongByArtist(Library *library, char *artist) {
    for (int i = 0; i < library->numSongs; i++) {
        if (strcmp(library->songs[i].artist, artist) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Search for a song by album
Song *searchSongByAlbum(Library *library, char *album) {
    for (int i = 0; i < library->numSongs; i++) {
        if (strcmp(library->songs[i].album, album) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Delete a song from the library
void deleteSong(Library *library, Song *song) {
    int index = -1;
    for (int i = 0; i < library->numSongs; i++) {
        if (&library->songs[i] == song) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < library->numSongs - 1; i++) {
            library->songs[i] = library->songs[i + 1];
        }
        library->numSongs--;
        library->songs = (Song *)realloc(library->songs, library->numSongs * sizeof(Song));
    }
}

// Free the library
void freeLibrary(Library *library) {
    free(library->songs);
    free(library);
}

// Main function
int main() {
    // Create a new library
    Library *library = createLibrary();

    // Add some songs to the library
    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360};
    addSong(library, &song1);
    Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480};
    addSong(library, &song2);
    Song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 380};
    addSong(library, &song3);
    Song song4 = {"Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991, 300};
    addSong(library, &song4);
    Song song5 = {"Imagine", "John Lennon", "Imagine", 1971, 180};
    addSong(library, &song5);

    // Print the library
    printf("The library contains the following songs:\n");
    printLibrary(library);

    // Search for a song by title
    Song *song = searchSongByTitle(library, "Bohemian Rhapsody");
    if (song != NULL) {
        printf("Found the song '%s' by %s from the album %s (%d)\n", song->title, song->artist, song->album, song->year);
    } else {
        printf("Could not find the song 'Bohemian Rhapsody'\n");
    }

    // Search for a song by artist
    song = searchSongByArtist(library, "Led Zeppelin");
    if (song != NULL) {
        printf("Found the song '%s' by %s from the album %s (%d)\n", song->title, song->artist, song->album, song->year);
    } else {
        printf("Could not find a song by Led Zeppelin\n");
    }

    // Search for a song by album
    song = searchSongByAlbum(library, "Nevermind");
    if (song != NULL) {
        printf("Found the song '%s' by %s from the album %s (%d)\n", song->title, song->artist, song->album, song->year);
    } else {
        printf("Could not find a song from the album Nevermind\n");
    }

    // Delete a song from the library
    deleteSong(library, &song1);

    // Print the library again
    printf("The library now contains the following songs:\n");
    printLibrary(library);

    // Free the library
    freeLibrary(library);

    return 0;
}