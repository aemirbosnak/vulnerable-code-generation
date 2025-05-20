//FormAI DATASET v1.0 Category: Music Library Management System ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char genre[MAX_SIZE];
    int year;
} Song;

typedef struct {
    Song** songs;
    int num_songs;
    int max_songs;
} MusicLibrary;

void addSong(MusicLibrary* library, Song* song) {
    if (library->num_songs >= library->max_songs) {
        library->max_songs += MAX_SIZE;
        library->songs = realloc(library->songs, sizeof(Song*) * library->max_songs);
    }
    library->songs[library->num_songs++] = song;
}

void printSong(Song* song) {
    printf("%s - %s (%d) [%s]\n", song->title, song->artist, song->year, song->genre);
}

void printLibrary(MusicLibrary* library) {
    for (int i = 0; i < library->num_songs; i++) {
        printSong(library->songs[i]);
    }
}

int main() {
    MusicLibrary* library = malloc(sizeof(MusicLibrary));
    library->num_songs = 0;
    library->max_songs = MAX_SIZE;
    library->songs = malloc(sizeof(Song*) * library->max_songs);

    Song* s1 = malloc(sizeof(Song));
    strcpy(s1->title, "Bohemian Rhapsody");
    strcpy(s1->artist, "Queen");
    strcpy(s1->genre, "Rock");
    s1->year = 1975;
    addSong(library, s1);

    Song* s2 = malloc(sizeof(Song));
    strcpy(s2->title, "Stairway to Heaven");
    strcpy(s2->artist, "Led Zeppelin");
    strcpy(s2->genre, "Rock");
    s2->year = 1971;
    addSong(library, s2);

    Song* s3 = malloc(sizeof(Song));
    strcpy(s3->title, "Thriller");
    strcpy(s3->artist, "Michael Jackson");
    strcpy(s3->genre, "Pop");
    s3->year = 1982;
    addSong(library, s3);

    printf("Your Music Library:\n");
    printLibrary(library);

    free(s1);
    free(s2);
    free(s3);
    free(library->songs);
    free(library);
    return 0;
}