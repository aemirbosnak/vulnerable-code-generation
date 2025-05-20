//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50
#define MAX_YEAR_LENGTH 4
#define MAX_GENRE_LENGTH 50

// Structure for storing album information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char year[MAX_YEAR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
} Album;

// Function to create a new album
Album* create_album(char name[], char artist[], char album[], char year[], char genre[]) {
    Album* new_album = (Album*)malloc(sizeof(Album));
    if (new_album == NULL) {
        fprintf(stderr, "Failed to allocate memory for new album\n");
        return NULL;
    }
    strcpy(new_album->name, name);
    strcpy(new_album->artist, artist);
    strcpy(new_album->album, album);
    strcpy(new_album->year, year);
    strcpy(new_album->genre, genre);
    return new_album;
}

// Function to print album information
void print_album(Album* album) {
    printf("Name: %s\n", album->name);
    printf("Artist: %s\n", album->artist);
    printf("Album: %s\n", album->album);
    printf("Year: %s\n", album->year);
    printf("Genre: %s\n", album->genre);
}

// Function to add album to library
void add_album(Album* library[], int num_albums, Album* new_album) {
    library[num_albums] = new_album;
    num_albums++;
}

// Function to search for album by name
bool search_album_by_name(Album* library[], int num_albums, char name[]) {
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(library[i]->name, name) == 0) {
            return true;
        }
    }
    return false;
}

// Function to search for album by artist
bool search_album_by_artist(Album* library[], int num_albums, char artist[]) {
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(library[i]->artist, artist) == 0) {
            return true;
        }
    }
    return false;
}

// Function to search for album by year
bool search_album_by_year(Album* library[], int num_albums, char year[]) {
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(library[i]->year, year) == 0) {
            return true;
        }
    }
    return false;
}

// Function to search for album by genre
bool search_album_by_genre(Album* library[], int num_albums, char genre[]) {
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(library[i]->genre, genre) == 0) {
            return true;
        }
    }
    return false;
}

// Function to remove album from library
void remove_album(Album* library[], int num_albums, Album* album) {
    for (int i = 0; i < num_albums; i++) {
        if (library[i] == album) {
            num_albums--;
            free(library[i]);
            library[i] = NULL;
            break;
        }
    }
}

// Function to display all albums in library
void display_library(Album* library[], int num_albums) {
    printf("Library:\n");
    for (int i = 0; i < num_albums; i++) {
        print_album(library[i]);
    }
}

int main() {
    Album* library[100];
    int num_albums = 0;

    // Create and add albums to library
    Album* album1 = create_album("Sgt. Pepper's Lonely Hearts Club Band", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", "1967", "Rock");
    Album* album2 = create_album("Thriller", "Michael Jackson", "Thriller", "1982", "Pop");
    Album* album3 = create_album("The Dark Side of the Moon", "Pink Floyd", "The Dark Side of the Moon", "1973", "Prog Rock");

    add_album(library, num_albums, album1);
    add_album(library, num_albums, album2);
    add_album(library, num_albums, album3);

    // Search for albums by name, artist, year, and genre
    printf("Search for album by name: %s\n", "Sgt. Pepper's Lonely Hearts Club Band");
    if (search_album_by_name(library, num_albums, "Sgt. Pepper's Lonely Hearts Club Band")) {
        print_album(library[0]);
    }
    else {
        printf("Not found\n");
    }

    printf("Search for album by artist: %s\n", "Michael Jackson");
    if (search_album_by_artist(library, num_albums, "Michael Jackson")) {
        print_album(library[1]);
    }
    else {
        printf("Not found\n");
    }

    printf("Search for album by year: %s\n", "1982");
    if (search_album_by_year(library, num_albums, "1982")) {
        print_album(library[1]);
    }
    else {
        printf("Not found\n");
    }

    printf("Search for album by genre: %s\n", "Rock");
    if (search_album_by_genre(library, num_albums, "Rock")) {
        print_album(library[0]);
    }
    else {
        printf("Not found\n");
    }

    // Remove album from library
    remove_album(library, num_albums, library[0]);
    remove_album(library, num_albums, library[1]);

    // Display all albums in library
    display_library(library, num_albums);

    return 0;
}