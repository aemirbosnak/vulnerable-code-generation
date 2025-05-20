//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char* name;
    char* artist;
    int year;
};

struct Library {
    struct Album* albums;
    int size;
};

struct Library createLibrary() {
    struct Library library;
    library.size = 0;
    library.albums = NULL;
    return library;
}

void addAlbum(struct Library* library, char* name, char* artist, int year) {
    struct Album* album = (struct Album*)malloc(sizeof(struct Album));
    strcpy(album->name, name);
    strcpy(album->artist, artist);
    album->year = year;
    library->albums = (struct Album*)realloc(library->albums, (library->size + 1) * sizeof(struct Album));
    library->albums[library->size++] = *album;
}

struct Album* findAlbum(struct Library* library, char* name) {
    for (int i = 0; i < library->size; i++) {
        if (strcmp(library->albums[i].name, name) == 0) {
            return &library->albums[i];
        }
    }
    return NULL;
}

void displayAlbums(struct Library* library) {
    for (int i = 0; i < library->size; i++) {
        printf("Name: %s\n", library->albums[i].name);
        printf("Artist: %s\n", library->albums[i].artist);
        printf("Year: %d\n", library->albums[i].year);
        printf("\n");
    }
}

int main() {
    struct Library library = createLibrary();

    addAlbum(&library, "Thriller", "Michael Jackson", 1982);
    addAlbum(&library, "Back in Black", "AC/DC", 1980);
    addAlbum(&library, "Nevermind", "Nirvana", 1991);

    struct Album* foundAlbum = findAlbum(&library, "Back in Black");
    if (foundAlbum!= NULL) {
        printf("Found: %s by %s (year: %d)\n", foundAlbum->name, foundAlbum->artist, foundAlbum->year);
    } else {
        printf("Album not found.\n");
    }

    displayAlbums(&library);

    return 0;
}