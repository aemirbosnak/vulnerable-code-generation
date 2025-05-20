//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
} song;

// Structure to represent a music library
typedef struct music_library {
    song *songs;
    int num_songs;
} music_library;

// Function to create a new music library
music_library *create_music_library() {
    music_library *library = malloc(sizeof(music_library));
    library->songs = NULL;
    library->num_songs = 0;
    return library;
}

// Function to add a song to a music library
void add_song_to_library(music_library *library, song *new_song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(song));
    library->songs[library->num_songs] = *new_song;
    library->num_songs++;
}

// Function to print a music library
void print_music_library(music_library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("Title: %s\n", library->songs[i].title);
        printf("Artist: %s\n", library->songs[i].artist);
        printf("Album: %s\n", library->songs[i].album);
        printf("Year: %d\n", library->songs[i].year);
        printf("Duration: %d\n\n", library->songs[i].duration);
    }
}

// Function to search for a song in a music library by title
song *search_song_by_title(music_library *library, char *title) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Function to search for a song in a music library by artist
song *search_song_by_artist(music_library *library, char *artist) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].artist, artist) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Function to search for a song in a music library by album
song *search_song_by_album(music_library *library, char *album) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].album, album) == 0) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Function to search for a song in a music library by year
song *search_song_by_year(music_library *library, int year) {
    for (int i = 0; i < library->num_songs; i++) {
        if (library->songs[i].year == year) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Function to search for a song in a music library by duration
song *search_song_by_duration(music_library *library, int duration) {
    for (int i = 0; i < library->num_songs; i++) {
        if (library->songs[i].duration == duration) {
            return &library->songs[i];
        }
    }
    return NULL;
}

// Function to free the memory allocated to a music library
void free_music_library(music_library *library) {
    free(library->songs);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    music_library *library = create_music_library();

    // Add some songs to the library
    song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 560};
    add_song_to_library(library, &song1);
    song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 828};
    add_song_to_library(library, &song2);
    song song3 = {"Imagine", "John Lennon", "Imagine", 1971, 360};
    add_song_to_library(library, &song3);
    song song4 = {"Hey Jude", "The Beatles", "Hey Jude", 1968, 420};
    add_song_to_library(library, &song4);
    song song5 = {"Like a Rolling Stone", "Bob Dylan", "Highway 61 Revisited", 1965, 660};
    add_song_to_library(library, &song5);

    // Print the music library
    printf("Music Library:\n");
    print_music_library(library);

    // Search for a song by title
    song *song = search_song_by_title(library, "Bohemian Rhapsody");
    if (song != NULL) {
        printf("Song found by title:\n");
        printf("Title: %s\n", song->title);
        printf("Artist: %s\n", song->artist);
        printf("Album: %s\n", song->album);
        printf("Year: %d\n", song->year);
        printf("Duration: %d\n", song->duration);
    } else {
        printf("Song not found by title.\n");
    }

    // Search for a song by artist
    song = search_song_by_artist(library, "Led Zeppelin");
    if (song != NULL) {
        printf("Song found by artist:\n");
        printf("Title: %s\n", song->title);
        printf("Artist: %s\n", song->artist);
        printf("Album: %s\n", song->album);
        printf("Year: %d\n", song->year);
        printf("Duration: %d\n", song->duration);
    } else {
        printf("Song not found by artist.\n");
    }

    // Search for a song by album
    song = search_song_by_album(library, "A Night at the Opera");
    if (song != NULL) {
        printf("Song found by album:\n");
        printf("Title: %s\n", song->title);
        printf("Artist: %s\n", song->artist);
        printf("Album: %s\n", song->album);
        printf("Year: %d\n", song->year);
        printf("Duration: %d\n", song->duration);
    } else {
        printf("Song not found by album.\n");
    }

    // Search for a song by year
    song = search_song_by_year(library, 1968);
    if (song != NULL) {
        printf("Song found by year:\n");
        printf("Title: %s\n", song->title);
        printf("Artist: %s\n", song->artist);
        printf("Album: %s\n", song->album);
        printf("Year: %d\n", song->year);
        printf("Duration: %d\n", song->duration);
    } else {
        printf("Song not found by year.\n");
    }

    // Search for a song by duration
    song = search_song_by_duration(library, 828);
    if (song != NULL) {
        printf("Song found by duration:\n");
        printf("Title: %s\n", song->title);
        printf("Artist: %s\n", song->artist);
        printf("Album: %s\n", song->album);
        printf("Year: %d\n", song->year);
        printf("Duration: %d\n", song->duration);
    } else {
        printf("Song not found by duration.\n");
    }

    // Free the memory allocated to the music library
    free_music_library(library);

    return 0;
}