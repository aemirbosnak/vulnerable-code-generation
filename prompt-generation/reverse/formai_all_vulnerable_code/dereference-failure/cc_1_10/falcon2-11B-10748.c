//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <string.h>

typedef struct {
    char* title;
    char* artist;
} Song;

typedef struct {
    int size;
    Song* songs;
} Library;

void initializeLibrary(Library* lib) {
    lib->size = 0;
    lib->songs = NULL;
}

void addSong(Library* lib, char* title, char* artist) {
    if (lib->size == 0) {
        lib->songs = malloc(sizeof(Song));
        lib->songs[0].title = strdup(title);
        lib->songs[0].artist = strdup(artist);
        lib->size++;
    } else if (lib->size < 5) {
        lib->songs = realloc(lib->songs, (lib->size + 1) * sizeof(Song));
        lib->songs[lib->size].title = strdup(title);
        lib->songs[lib->size].artist = strdup(artist);
        lib->size++;
    }
}

void deleteSong(Library* lib, int index) {
    if (index < 0 || index >= lib->size) {
        printf("Invalid index.\n");
        return;
    }
    if (lib->size == 1) {
        free(lib->songs[0].title);
        free(lib->songs[0].artist);
        free(lib->songs);
        lib->songs = NULL;
        lib->size = 0;
    } else {
        for (int i = index; i < lib->size - 1; i++) {
            lib->songs[i] = lib->songs[i + 1];
        }
        lib->songs[lib->size - 1].title = NULL;
        lib->songs[lib->size - 1].artist = NULL;
        lib->size--;
    }
}

void listSongs(Library* lib) {
    for (int i = 0; i < lib->size; i++) {
        printf("Title: %s, Artist: %s\n", lib->songs[i].title, lib->songs[i].artist);
    }
}

int main() {
    Library lib;
    initializeLibrary(&lib);

    addSong(&lib, "Song 1", "Artist 1");
    addSong(&lib, "Song 2", "Artist 2");
    addSong(&lib, "Song 3", "Artist 3");

    listSongs(&lib);

    deleteSong(&lib, 0);

    listSongs(&lib);

    return 0;
}