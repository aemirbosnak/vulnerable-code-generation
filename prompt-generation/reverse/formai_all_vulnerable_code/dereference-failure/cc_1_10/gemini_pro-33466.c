//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct album {
    char *name;
    char *artist;
    int year;
    struct album *next;
};

struct library {
    struct album *first;
};

struct library *create_library() {
    struct library *lib = malloc(sizeof(struct library));
    if (lib == NULL) {
        return NULL;
    }
    lib->first = NULL;
    return lib;
}

void add_album(struct library *lib, char *name, char *artist, int year) {
    struct album *new_album = malloc(sizeof(struct album));
    if (new_album == NULL) {
        return;
    }
    new_album->name = strdup(name);
    new_album->artist = strdup(artist);
    new_album->year = year;
    new_album->next = lib->first;
    lib->first = new_album;
}

void print_library(struct library *lib) {
    struct album *album = lib->first;
    while (album != NULL) {
        printf("%s by %s (%d)\n", album->name, album->artist, album->year);
        album = album->next;
    }
}

void free_library(struct library *lib) {
    struct album *album = lib->first;
    while (album != NULL) {
        struct album *next = album->next;
        free(album->name);
        free(album->artist);
        free(album);
        album = next;
    }
    free(lib);
}

int main() {
    struct library *lib = create_library();
    add_album(lib, "The Dark Side of the Moon", "Pink Floyd", 1973);
    add_album(lib, "Sgt. Pepper's Lonely Hearts Club Band", "The Beatles", 1967);
    add_album(lib, "Pet Sounds", "The Beach Boys", 1966);
    add_album(lib, "Revolver", "The Beatles", 1966);
    add_album(lib, "Highway 61 Revisited", "Bob Dylan", 1965);
    add_album(lib, "The Velvet Underground & Nico", "The Velvet Underground", 1967);
    add_album(lib, "Are You Experienced?", "The Jimi Hendrix Experience", 1967);
    add_album(lib, "Led Zeppelin", "Led Zeppelin", 1969);
    add_album(lib, "Trout Mask Replica", "Captain Beefheart & His Magic Band", 1969);
    add_album(lib, "Sticky Fingers", "The Rolling Stones", 1971);
    print_library(lib);
    free_library(lib);
    return 0;
}