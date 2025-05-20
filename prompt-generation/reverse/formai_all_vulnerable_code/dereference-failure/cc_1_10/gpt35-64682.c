//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to hold the song data */
typedef struct song {
    char* title;
    char* artist;
    int year;
    char* genre;
} Song;

/* Function to create a new song */
Song* create_song(char* title, char* artist, int year, char* genre) {
    Song* new_song = (Song*) malloc(sizeof(Song));
    new_song->title = strdup(title);
    new_song->artist = strdup(artist);
    new_song->year = year;
    new_song->genre = strdup(genre);
    return new_song;
}

/* Function to print a song */
void print_song(Song* song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Year: %d\n", song->year);
    printf("Genre: %s\n", song->genre);
}

/* Function to compare two songs by title */
int compare_title(Song* song1, Song* song2) {
    return strcmp(song1->title, song2->title);
}

/* Function to compare two songs by artist */
int compare_artist(Song* song1, Song* song2) {
    return strcmp(song1->artist, song2->artist);
}

/* Function to compare two songs by year */
int compare_year(Song* song1, Song* song2) {
    return song1->year - song2->year;
}

/* Function to compare two songs by genre */
int compare_genre(Song* song1, Song* song2) {
    return strcmp(song1->genre, song2->genre);
}

/* Struct to hold the music library data */
typedef struct music_library {
    int num_songs;
    int max_songs;
    Song** songs;
} MusicLibrary;

/* Function to create a new music library */
MusicLibrary* create_music_library(int max_songs) {
    MusicLibrary* new_library = (MusicLibrary*) malloc(sizeof(MusicLibrary));
    new_library->num_songs = 0;
    new_library->max_songs = max_songs;
    new_library->songs = (Song**) malloc(max_songs * sizeof(Song*));
    return new_library;
}

/* Function to add a song to the music library */
void add_song(MusicLibrary* library, Song* song) {
    if (library->num_songs < library->max_songs) {
        library->songs[library->num_songs] = song;
        library->num_songs++;
    }
}

/* Function to print the entire music library */
void print_library(MusicLibrary* library) {
    for (int i = 0; i < library->num_songs; i++) {
        print_song(library->songs[i]);
        printf("\n");
    }
}

/* Function to sort the music library */
void sort_library(MusicLibrary* library, int (*cmp)(Song*, Song*)) {
    for (int i = 0; i < library->num_songs - 1; i++) {
        for (int j = i + 1; j < library->num_songs; j++) {
            if (cmp(library->songs[i], library->songs[j]) > 0) {
                Song* temp_song = library->songs[i];
                library->songs[i] = library->songs[j];
                library->songs[j] = temp_song;
            }
        }
    }
}

int main() {
    MusicLibrary* library = create_music_library(10);
    add_song(library, create_song("Bohemian Rhapsody", "Queen", 1975, "Rock"));
    add_song(library, create_song("Sweet Child O' Mine", "Guns N' Roses", 1987, "Rock"));
    add_song(library, create_song("Billie Jean", "Michael Jackson", 1983, "Pop"));
    add_song(library, create_song("Smells Like Teen Spirit", "Nirvana", 1991, "Grunge"));
    add_song(library, create_song("Beat It", "Michael Jackson", 1982, "Pop"));

    printf("Original Library:\n");
    print_library(library);

    printf("\nSorted by Title:\n");
    sort_library(library, compare_title);
    print_library(library);

    printf("\nSorted by Artist:\n");
    sort_library(library, compare_artist);
    print_library(library);

    printf("\nSorted by Year:\n");
    sort_library(library, compare_year);
    print_library(library);

    printf("\nSorted by Genre:\n");
    sort_library(library, compare_genre);
    print_library(library);

    return 0;
}