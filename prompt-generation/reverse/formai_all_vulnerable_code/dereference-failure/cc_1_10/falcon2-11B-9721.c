//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

typedef struct {
    char artist[MAX_LENGTH];
    char song[MAX_LENGTH];
    int duration;
} song_t;

typedef struct {
    char name[MAX_LENGTH];
    song_t songs[10];
    int num_songs;
} library_t;

void add_song(library_t *lib, const char *artist, const char *song, int duration) {
    if (lib->num_songs >= MAX_LENGTH) {
        printf("Error: Library is full!\n");
        return;
    }

    strcpy(lib->songs[lib->num_songs].artist, artist);
    strcpy(lib->songs[lib->num_songs].song, song);
    lib->songs[lib->num_songs].duration = duration;
    lib->num_songs++;
}

void remove_song(library_t *lib, int index) {
    if (index >= MAX_LENGTH || index < 0) {
        printf("Error: Invalid index\n");
        return;
    }

    for (int i = index; i < MAX_LENGTH - 1; i++) {
        lib->songs[i] = lib->songs[i + 1];
    }
    lib->num_songs--;
}

void print_songs(library_t *lib) {
    printf("Library: %s\n", lib->name);
    printf("Number of songs: %d\n", lib->num_songs);
    for (int i = 0; i < lib->num_songs; i++) {
        printf("Artist: %s, Song: %s, Duration: %d\n", lib->songs[i].artist, lib->songs[i].song, lib->songs[i].duration);
    }
}

int main() {
    library_t my_library = {"My Library", { 0 }};

    add_song(&my_library, "Artist1", "Song1", 120);
    add_song(&my_library, "Artist2", "Song2", 180);
    add_song(&my_library, "Artist3", "Song3", 300);

    print_songs(&my_library);

    remove_song(&my_library, 1);

    print_songs(&my_library);

    return 0;
}