//FormAI DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
} Song;

typedef struct {
    Song* songs;
    int num_songs;
    int capacity;
} Library;

void add_song(Library* l, Song s) {
    if (l->num_songs >= l->capacity) {
        l->songs = realloc(l->songs, l->capacity * 2 * sizeof(Song));
        l->capacity *= 2;
    }
    l->songs[l->num_songs] = s;
    l->num_songs++;
}

int find_song(Library* l, char* title, char* artist) {
    for (int i = 0; i < l->num_songs; i++) {
        if (strcmp(l->songs[i].title, title) == 0 && strcmp(l->songs[i].artist, artist) == 0) {
            return i;
        }
    }
    return -1;
}

void remove_song(Library* l, char* title, char* artist) {
    int index = find_song(l, title, artist);
    if (index != -1) {
        for (int i = index; i < l->num_songs - 1; i++) {
            l->songs[i] = l->songs[i + 1];
        }
        l->num_songs--;
    }
}

void print_library(Library* l) {
    printf("%-20s%-20s%-20s%-10s%-10s\n", "Title", "Artist", "Album", "Year", "Duration");
    for (int i = 0; i < l->num_songs; i++) {
        printf("%-20s%-20s%-20s%-10d%-10d\n", l->songs[i].title, l->songs[i].artist, l->songs[i].album, l->songs[i].year, l->songs[i].duration);
    }
}

int main() {
    printf("Welcome to the C Music Library Management System!\n");
    printf("Initializing library...\n");
    Library lib;
    lib.songs = malloc(10 * sizeof(Song));
    lib.num_songs = 0;
    lib.capacity = 10;
    printf("Library created with a capacity of 10 songs.\n");
    printf("Adding songs...\n");
    Song s1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 354};
    add_song(&lib, s1);
    Song s2 = {"Stairway to Heaven", "Led Zeppelin", "IV", 1971, 482};
    add_song(&lib, s2);
    Song s3 = {"Hotel California", "Eagles", "Hotel California", 1976, 391};
    add_song(&lib, s3);
    printf("Songs added to library.\n");
    printf("Printing library...\n");
    print_library(&lib);
    printf("Removing 'Stairway to Heaven' by 'Led Zeppelin'...\n");
    remove_song(&lib, "Stairway to Heaven", "Led Zeppelin");
    printf("Printing library...\n");
    print_library(&lib);
    printf("Exiting program. Thank you for using the C Music Library Management System!\n");
    free(lib.songs);
    return 0;
}