//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ARTISTS 100
#define MAX_TRACKS 100
#define MAX_TITLE_LEN 50
#define MAX_GENRE_LEN 20

typedef struct Artist {
    char name[MAX_ARTISTS];
    int num_tracks;
    struct Artist *next;
} Artist;

typedef struct Track {
    char title[MAX_TITLE_LEN];
    char genre[MAX_GENRE_LEN];
    int length;
    struct Track *next;
    Artist *artist;
} Track;

Artist *artists = NULL;
Track *tracks = NULL;

void add_artist(const char *name) {
    Artist *new_artist = (Artist *)malloc(sizeof(Artist));
    strcpy(new_artist->name, name);
    new_artist->num_tracks = 0;
    new_artist->next = artists;
    artists = new_artist;
}

Artist *find_artist(const char *name) {
    Artist *current = artists;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_track(const char *title, const char *genre, int length, Artist *artist) {
    Track *new_track = (Track *)malloc(sizeof(Track));
    strcpy(new_track->title, title);
    strcpy(new_track->genre, genre);
    new_track->length = length;
    new_track->next = tracks;
    new_track->artist = artist;
    artist->num_tracks++;
    tracks = new_track;
}

void print_library() {
    Artist *current_artist = artists;
    printf("Artists:\n");
    while (current_artist != NULL) {
        printf("%s: %d tracks\n", current_artist->name, current_artist->num_tracks);
        Track *current_track = tracks;
        while (current_track != NULL && current_track->artist == current_artist) {
            printf("    %s - %s (%s) - %d seconds\n", current_track->title, current_track->genre, current_track->title, current_track->length);
            current_track = current_track->next;
        }
        current_artist = current_artist->next;
    }
}

int main() {
    add_artist("Michael Jackson");
    add_artist("The Beatles");

    Artist *mj = find_artist("Michael Jackson");
    add_track("Billie Jean", "Pop", 453, mj);
    add_track("Thriller", "Pop", 501, mj);

    Artist *beatles = find_artist("The Beatles");
    add_track("Hey Jude", "Rock", 366, beatles);
    add_track("Let It Be", "Pop", 152, beatles);

    print_library();

    return 0;
}