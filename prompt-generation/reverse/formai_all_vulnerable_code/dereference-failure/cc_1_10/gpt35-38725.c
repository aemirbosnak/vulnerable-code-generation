//FormAI DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char song_title[100];
    char artist[100];
    int duration;
} Song;

typedef struct {
    Song *songs;
    int num_songs;
    int max_songs;
} MusicLibrary;

int add_song(MusicLibrary *library, Song new_song);
int remove_song(MusicLibrary *library, char *song_title);
void print_library(MusicLibrary *library);
void sort_library(MusicLibrary *library, int option);

int main() {
    MusicLibrary my_library;
    my_library.songs = malloc(50 * sizeof(Song)); // allocate memory for 50 songs initially
    my_library.num_songs = 0;
    my_library.max_songs = 50;
    
    // adding some sample songs
    Song s1 = {"Bohemian Rhapsody", "Queen", 354};
    add_song(&my_library, s1);
    Song s2 = {"Stairway to Heaven", "Led Zeppelin", 481};
    add_song(&my_library, s2);
    Song s3 = {"Sweet Child O' Mine", "Guns N' Roses", 356};
    add_song(&my_library, s3);
    Song s4 = {"Hotel California", "Eagles", 390};
    add_song(&my_library, s4);
    Song s5 = {"Dream On", "Aerosmith", 274};
    add_song(&my_library, s5);
    Song s6 = {"November Rain", "Guns N' Roses", 537};
    add_song(&my_library, s6);

    // sample usage of functions
    print_library(&my_library);
    sort_library(&my_library, 1); // sort by song title
    print_library(&my_library);
    sort_library(&my_library, 2); // sort by artist
    print_library(&my_library);
    remove_song(&my_library, "Hotel California"); // remove a song
    print_library(&my_library);

    free(my_library.songs); // free memory
    return 0;
}

int add_song(MusicLibrary *library, Song new_song) {
    if (library->num_songs >= library->max_songs) {
        printf("Unable to add song: library is full.\n");
        return 0;
    }
    library->songs[library->num_songs] = new_song;
    library->num_songs++;
    return 1;
}

int remove_song(MusicLibrary *library, char *song_title) {
    int i, found = 0;
    for (i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].song_title, song_title) == 0) {
            found = 1;
            // move all subsequent songs back one position to fill the gap
            for (int j = i; j < library->num_songs - 1; j++) {
                library->songs[j] = library->songs[j + 1];
            }
            library->num_songs--;
            break;
        }
    }
    if (!found) {
        printf("Unable to remove song '%s': not found in library.\n", song_title);
        return 0;
    }
    printf("Successfully removed song '%s' from library.\n", song_title);
    return 1;
}

void print_library(MusicLibrary *library) {
    printf("Music Library:\n");
    printf("------------------------------------\n");
    printf("| %-30s | %-20s | %-10s |\n", "Title", "Artist", "Duration");
    printf("------------------------------------\n");
    for (int i = 0; i < library->num_songs; i++) {
        printf("| %-30s | %-20s | %02d:%02d     |\n", library->songs[i].song_title, library->songs[i].artist,
               library->songs[i].duration / 60, library->songs[i].duration % 60);
    }
    printf("------------------------------------\n");
}

void sort_library(MusicLibrary *library, int option) {
    Song temp;
    for (int i = 0; i < library->num_songs - 1; i++) {
        for (int j = i + 1; j < library->num_songs; j++) {
            if (option == 1) { // sort by song title
                if (strcmp(library->songs[i].song_title, library->songs[j].song_title) > 0) {
                    temp = library->songs[i];
                    library->songs[i] = library->songs[j];
                    library->songs[j] = temp;
                }
            }
            else if (option == 2) { // sort by artist
                if (strcmp(library->songs[i].artist, library->songs[j].artist) > 0) {
                    temp = library->songs[i];
                    library->songs[i] = library->songs[j];
                    library->songs[j] = temp;
                }
            }
            else {
                printf("Invalid sort option.\n");
                return;
            }
        }
    }
}