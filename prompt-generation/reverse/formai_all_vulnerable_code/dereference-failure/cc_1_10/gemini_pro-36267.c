//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char *title;
    char *artist;
    int year;
    struct Album *next;
};

struct Library {
    struct Album *head;
    struct Album *tail;
};

struct Library *create_library() {
    struct Library *library = malloc(sizeof(struct Library));
    library->head = NULL;
    library->tail = NULL;
    return library;
}

void add_album(struct Library *library, char *title, char *artist, int year) {
    struct Album *album = malloc(sizeof(struct Album));
    album->title = strdup(title);
    album->artist = strdup(artist);
    album->year = year;
    album->next = NULL;

    if (library->head == NULL) {
        library->head = album;
        library->tail = album;
    } else {
        library->tail->next = album;
        library->tail = album;
    }
}

void print_library(struct Library *library) {
    struct Album *album = library->head;
    while (album != NULL) {
        printf("%s by %s (%d)\n", album->title, album->artist, album->year);
        album = album->next;
    }
}

void free_album(struct Album *album) {
    free(album->title);
    free(album->artist);
    free(album);
}

void free_library(struct Library *library) {
    struct Album *album = library->head;
    while (album != NULL) {
        struct Album *next = album->next;
        free_album(album);
        album = next;
    }
    free(library);
}

int main() {
    struct Library *library = create_library();

    add_album(library, "Dark Side of the Moon", "Pink Floyd", 1973);
    add_album(library, "Sgt. Pepper's Lonely Hearts Club Band", "The Beatles", 1967);
    add_album(library, "Pet Sounds", "The Beach Boys", 1966);
    add_album(library, "Revolver", "The Beatles", 1966);
    add_album(library, "Highway 61 Revisited", "Bob Dylan", 1965);

    print_library(library);

    free_library(library);

    return 0;
}