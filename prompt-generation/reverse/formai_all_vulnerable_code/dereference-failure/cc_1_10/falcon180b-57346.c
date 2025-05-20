//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_ARTISTS 50
#define MAX_ALBUMS 50
#define MAX_GENRES 50

typedef struct Song {
    char title[100];
    char artist[50];
    char album[50];
    char genre[50];
} Song;

typedef struct Artist {
    char name[50];
    int num_songs;
    Song *songs;
} Artist;

typedef struct Album {
    char title[50];
    int num_songs;
    Song *songs;
} Album;

typedef struct Genre {
    char name[50];
    int num_songs;
    Song *songs;
} Genre;

void add_song(Song *song) {
    printf("Enter song title: ");
    scanf("%s", song->title);
    printf("Enter artist name: ");
    scanf("%s", song->artist);
    printf("Enter album title: ");
    scanf("%s", song->album);
    printf("Enter genre: ");
    scanf("%s", song->genre);
}

void display_song(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Genre: %s\n\n", song.genre);
}

void add_artist(Artist *artist) {
    printf("Enter artist name: ");
    scanf("%s", artist->name);
    artist->num_songs = 0;
    artist->songs = (Song *) malloc(MAX_SONGS * sizeof(Song));
}

void display_artist(Artist artist) {
    printf("Artist: %s\n", artist.name);
    printf("Number of songs: %d\n", artist.num_songs);
    for (int i = 0; i < artist.num_songs; i++) {
        display_song(artist.songs[i]);
    }
}

void add_album(Album *album) {
    printf("Enter album title: ");
    scanf("%s", album->title);
    album->num_songs = 0;
    album->songs = (Song *) malloc(MAX_SONGS * sizeof(Song));
}

void display_album(Album album) {
    printf("Album: %s\n", album.title);
    printf("Number of songs: %d\n", album.num_songs);
    for (int i = 0; i < album.num_songs; i++) {
        display_song(album.songs[i]);
    }
}

void add_genre(Genre *genre) {
    printf("Enter genre name: ");
    scanf("%s", genre->name);
    genre->num_songs = 0;
    genre->songs = (Song *) malloc(MAX_SONGS * sizeof(Song));
}

void display_genre(Genre genre) {
    printf("Genre: %s\n", genre.name);
    printf("Number of songs: %d\n", genre.num_songs);
    for (int i = 0; i < genre.num_songs; i++) {
        display_song(genre.songs[i]);
    }
}

int main() {
    Song song;
    Artist artist;
    Album album;
    Genre genre;

    add_song(&song);
    add_artist(&artist);
    add_album(&album);
    add_genre(&genre);

    display_song(song);
    display_artist(artist);
    display_album(album);
    display_genre(genre);

    return 0;
}