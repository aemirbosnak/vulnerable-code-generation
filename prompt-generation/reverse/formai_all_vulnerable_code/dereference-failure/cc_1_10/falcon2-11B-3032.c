//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 100
#define MAX_GENRE_LEN 100

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char genre[MAX_GENRE_LEN];
} Album;

typedef struct {
    Album *albums;
    int num_albums;
    int capacity;
} MusicLibrary;

MusicLibrary createLibrary() {
    MusicLibrary library;
    library.albums = NULL;
    library.num_albums = 0;
    library.capacity = 10;
    return library;
}

void addAlbum(MusicLibrary *library, const char *title, const char *artist, const char *genre) {
    if (library->num_albums == library->capacity) {
        library->capacity *= 2;
        library->albums = realloc(library->albums, library->capacity * sizeof(Album));
    }

    Album *newAlbum = &library->albums[library->num_albums];
    strcpy(newAlbum->title, title);
    strcpy(newAlbum->artist, artist);
    strcpy(newAlbum->genre, genre);

    library->num_albums++;
}

void removeAlbum(MusicLibrary *library, int index) {
    if (index >= library->num_albums) {
        return;
    }

    for (int i = index; i < library->num_albums - 1; i++) {
        library->albums[i] = library->albums[i + 1];
    }

    library->num_albums--;
}

void displayLibrary(MusicLibrary *library) {
    printf("Library contains:\n");
    for (int i = 0; i < library->num_albums; i++) {
        printf("Album %d: %s by %s (%s)\n", i + 1, library->albums[i].title, library->albums[i].artist, library->albums[i].genre);
    }
}

int main() {
    MusicLibrary library = createLibrary();

    addAlbum(&library, "Thriller", "Michael Jackson", "Pop");
    addAlbum(&library, "Back in Black", "AC/DC", "Rock");
    addAlbum(&library, "Purple Rain", "Prince", "Pop");
    addAlbum(&library, "OK Computer", "Radiohead", "Rock");
    addAlbum(&library, "Reign in Blood", "Slayer", "Heavy Metal");
    addAlbum(&library, "London Calling", "The Clash", "Punk");

    displayLibrary(&library);

    removeAlbum(&library, 1);
    displayLibrary(&library);

    removeAlbum(&library, 0);
    displayLibrary(&library);

    return 0;
}