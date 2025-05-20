//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Song {
    char title[100];
    int length;
};

struct Library {
    int size;
    struct Song* songs;
};

void addSong(struct Library* library, struct Song* song) {
    if (library->size < 10) {
        library->songs[library->size] = *song;
        library->size++;
        return;
    } else {
        addSong(library, song);
    }
}

void displayLibrary(struct Library* library) {
    if (library->size > 0) {
        printf("Library contains %d songs:\n", library->size);
        for (int i = 0; i < library->size; i++) {
            printf("%d. %s (%d minutes)\n", i+1, library->songs[i].title, library->songs[i].length);
        }
        displayLibrary(library);
    }
}

int main() {
    struct Library library;
    library.size = 0;
    library.songs = NULL;

    struct Song song1;
    strcpy(song1.title, "Song 1");
    song1.length = 240;

    struct Song song2;
    strcpy(song2.title, "Song 2");
    song2.length = 180;

    addSong(&library, &song1);
    addSong(&library, &song2);

    displayLibrary(&library);

    return 0;
}