//FormAI DATASET v1.0 Category: Music Library Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the default size of the arrays */
#define DEFSIZE 100

/* Define the structure for songs */
struct Song {
    char* name;
    char* artist;
    char* album;
};

/* Define the structure for the music library */
struct MusicLibrary {
    struct Song* songs;
    int num_songs;
    int size;
};

/* Initialize the music library */
void initializeLibrary(struct MusicLibrary* library) {
    library->songs = malloc(sizeof(struct Song) * DEFSIZE);
    library->num_songs = 0;
    library->size = DEFSIZE;
}

/* Add a song to the music library */
void addSong(struct MusicLibrary* library, char* name, char* artist, char* album) {
    /* If the library is not big enough, allocate more space */
    if (library->num_songs >= library->size) {
        library->size += DEFSIZE;
        library->songs = realloc(library->songs, sizeof(struct Song) * library->size);
    }

    /* Add the new song to the library */
    library->songs[library->num_songs].name = strdup(name);
    library->songs[library->num_songs].artist = strdup(artist);
    library->songs[library->num_songs].album = strdup(album);
    library->num_songs++;
}

/* Remove a song from the music library */
void removeSong(struct MusicLibrary* library, int index) {
    /* Free the memory for the song being removed */
    free(library->songs[index].name);
    free(library->songs[index].artist);
    free(library->songs[index].album);

    /* Shift the remaining elements to fill in the gap */
    for (int i = index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }

    /* Decrement the number of songs */
    library->num_songs--;
}

/* Print all the songs in the music library */
void printLibrary(struct MusicLibrary* library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s - %s (%s)\n", library->songs[i].name, library->songs[i].artist, library->songs[i].album);
    }
}

/* Main program */
int main() {
    /* Initialize the music library */
    struct MusicLibrary library;
    initializeLibrary(&library);

    /* Add some songs to the library */
    addSong(&library, "Bohemian Rhapsody", "Queen", "A Night at the Opera");
    addSong(&library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV");
    addSong(&library, "Hotel California", "Eagles", "Hotel California");

    /* Print the songs in the library */
    printf("Songs in the library:\n");
    printLibrary(&library);

    /* Remove a song from the library */
    removeSong(&library, 1);

    /* Print the songs in the library again */
    printf("\nSongs in the library after removing a song:\n");
    printLibrary(&library);

    /* Free the memory for the songs */
    for (int i = 0; i < library.num_songs; i++) {
        free(library.songs[i].name);
        free(library.songs[i].artist);
        free(library.songs[i].album);
    }
    free(library.songs);

    return 0;
}