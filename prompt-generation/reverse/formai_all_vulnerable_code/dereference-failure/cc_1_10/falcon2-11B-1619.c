//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include <stdio.h>
#include <string.h>

typedef struct album {
    char artist[100];
    char title[100];
    char genre[100];
    int year;
} album;

typedef struct library {
    album *albums;
    int num_albums;
} library;

void add_album(library *library, char artist[], char title[], char genre[], int year) {
    library->num_albums++;
    album *album = malloc(sizeof(album));
    strcpy(album->artist, artist);
    strcpy(album->title, title);
    strcpy(album->genre, genre);
    album->year = year;
    library->albums = realloc(library->albums, (library->num_albums + 1) * sizeof(album));
    library->albums[library->num_albums - 1] = *album;
}

void print_library(library library) {
    printf("Music Library:\n");
    for (int i = 0; i < library.num_albums; i++) {
        printf("Artist: %s\n", library.albums[i].artist);
        printf("Title: %s\n", library.albums[i].title);
        printf("Genre: %s\n", library.albums[i].genre);
        printf("Year: %d\n", library.albums[i].year);
    }
}

int main() {
    library library;
    library.num_albums = 0;
    library.albums = NULL;

    add_album(&library, "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", "Rock", 1967);
    add_album(&library, "Led Zeppelin", "Led Zeppelin", "Rock", 1969);
    add_album(&library, "Pink Floyd", "The Dark Side of the Moon", "Progressive Rock", 1973);
    add_album(&library, "Queen", "A Night at the Opera", "Rock", 1975);
    add_album(&library, "The Rolling Stones", "Sticky Fingers", "Rock", 1971);

    print_library(library);

    return 0;
}