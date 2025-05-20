//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 50

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    char genre[10];
    int year;
    float length;
} Song;

Song *library = NULL;
int num_songs = 0;

void add_song(char *title, char *artist, char *album, char *genre, int year, float length) {
    if (num_songs < MAX_SONGS) {
        library = realloc(library, sizeof(Song) * (num_songs + 1));
        strcpy(library[num_songs].title, title);
        strcpy(library[num_songs].artist, artist);
        strcpy(library[num_songs].album, album);
        strcpy(library[num_songs].genre, genre);
        library[num_songs].year = year;
        library[num_songs].length = length;
        num_songs++;
    } else {
        printf("Library is full.\n");
    }
}

Song *search_song_by_title(char *title) {
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].title, title) == 0) {
            return &library[i];
        }
    }
    return NULL;
}

Song *search_song_by_artist(char *artist) {
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].artist, artist) == 0) {
            return &library[i];
        }
    }
    return NULL;
}

void print_library() {
    printf("Title\tArtist\tAlbum\tGenre\tYear\tLength\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%s\t%s\t%s\t%s\t%d\t%.2f\n", library[i].title, library[i].artist, library[i].album, library[i].genre, library[i].year, library[i].length);
    }
}

int main() {
    char title[50], artist[50], album[50], genre[10];
    int year;
    float length;

    add_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", "Rock", 1975, 5.58);
    add_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", "Hard Rock", 1971, 8.02);

    Song *song = search_song_by_title("Bohemian Rhapsody");
    if (song != NULL) {
        printf("Found song: %s - %s\n", song->title, song->artist);
    } else {
        printf("Song not found.\n");
    }

    print_library();

    return 0;
}