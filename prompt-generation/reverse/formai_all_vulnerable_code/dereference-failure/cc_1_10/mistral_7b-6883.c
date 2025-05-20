//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ARTISTS 50
#define MAX_SONGS 100
#define MAX_CHAR 100

typedef struct Song {
    char title[MAX_CHAR];
    char artist[MAX_CHAR];
    int duration;
    struct Song *next;
} Song;

typedef struct Artist {
    char name[MAX_CHAR];
    int id;
    Song *first_song;
    Song *last_song;
    struct Artist *next;
} Artist;

void add_song(Artist *artist, Song *song) {
    if (artist->first_song == NULL) {
        artist->first_song = song;
        artist->last_song = song;
    } else {
        artist->last_song->next = song;
        artist->last_song = song;
    }
}

void add_artist(Artist **artists, char *name, int id) {
    Artist *new_artist = (Artist *)malloc(sizeof(Artist));
    strcpy(new_artist->name, name);
    new_artist->id = id;
    new_artist->next = NULL;
    new_artist->first_song = NULL;
    new_artist->last_song = NULL;

    if (*artists == NULL) {
        *artists = new_artist;
    } else {
        Artist *current = *artists;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_artist;
    }
}

void print_songs(Artist *artist) {
    Song *current = artist->first_song;
    printf("%s's songs:\n", artist->name);
    while (current != NULL) {
        printf("- %s by %s (Duration: %d)\n", current->title, current->artist, current->duration);
        current = current->next;
    }
}

int main() {
    Artist *artists = NULL;
    Song *songs[MAX_SONGS] = {0};

    add_artist(&artists, "Michael Jackson", 1);
    add_artist(&artists, "The Beatles", 2);

    Song *song1 = (Song *)malloc(sizeof(Song));
    strcpy(song1->title, "Billie Jean");
    strcpy(song1->artist, "Michael Jackson");
    song1->duration = 450;
    add_song(artists, song1);

    Song *song2 = (Song *)malloc(sizeof(Song));
    strcpy(song2->title, "Hey Jude");
    strcpy(song2->artist, "The Beatles");
    song2->duration = 250;
    add_song(artists, song2);

    Song *song3 = (Song *)malloc(sizeof(Song));
    strcpy(song3->title, "Thriller");
    strcpy(song3->artist, "Michael Jackson");
    song3->duration = 400;
    add_song(artists, song3);

    Song *song4 = (Song *)malloc(sizeof(Song));
    strcpy(song4->title, "Let It Be");
    strcpy(song4->artist, "The Beatles");
    song4->duration = 200;
    add_song(artists, song4);

    for (int i = 0; i < 4; i++) {
        print_songs(artists);
        artists = artists->next;
    }

    return 0;
}