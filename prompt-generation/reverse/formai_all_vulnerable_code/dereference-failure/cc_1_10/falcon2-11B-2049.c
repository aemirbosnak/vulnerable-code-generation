//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a song
struct Song {
    char name[100];
    int duration;
};

// Define a structure to represent the library
struct Library {
    int size;
    struct Song* songs;
};

// Define a function to add a song to the library
void addSong(struct Library* lib, struct Song* song) {
    lib->songs = realloc(lib->songs, sizeof(struct Song) * (lib->size + 1));
    strcpy(lib->songs[lib->size].name, song->name);
    lib->songs[lib->size].duration = song->duration;
    lib->size++;
}

// Define a function to remove a song from the library
void removeSong(struct Library* lib, int index) {
    if (index >= 0 && index < lib->size) {
        memmove(&lib->songs[index], &lib->songs[index + 1], sizeof(struct Song) * (lib->size - index - 1));
        lib->size--;
    }
}

// Define a function to search for a song in the library
struct Song* searchSong(struct Library* lib, char* name) {
    for (int i = 0; i < lib->size; i++) {
        if (strcmp(lib->songs[i].name, name) == 0) {
            return &lib->songs[i];
        }
    }
    return NULL;
}

// Define a function to display the library
void displayLibrary(struct Library* lib) {
    printf("Library:\n");
    for (int i = 0; i < lib->size; i++) {
        printf("Name: %s, Duration: %d\n", lib->songs[i].name, lib->songs[i].duration);
    }
}

int main() {
    struct Library lib;
    lib.size = 0;

    // Create some songs
    struct Song song1 = {"Song 1", 240};
    struct Song song2 = {"Song 2", 180};
    struct Song song3 = {"Song 3", 300};

    // Add songs to the library
    addSong(&lib, &song1);
    addSong(&lib, &song2);
    addSong(&lib, &song3);

    // Display the library
    printf("Library:\n");
    displayLibrary(&lib);

    // Search for a song
    struct Song* song = searchSong(&lib, "Song 2");
    if (song!= NULL) {
        printf("Found song: %s\n", song->name);
    } else {
        printf("Song not found\n");
    }

    // Remove a song
    removeSong(&lib, 2);

    // Display the library again
    printf("Library:\n");
    displayLibrary(&lib);

    return 0;
}