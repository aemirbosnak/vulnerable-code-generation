//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_ARTISTS 100
#define MAX_ALBUMS 100

typedef struct
{
    char title[50];
    char artist[50];
    char album[50];
    int year;
    float rating;
} Song;

typedef struct
{
    char name[50];
    char genre[50];
    int num_songs;
    Song *songs;
} Artist;

typedef struct
{
    char title[50];
    char artist[50];
    int year;
    int num_songs;
    Song *songs;
} Album;

Song *songs[MAX_SONGS];
Artist *artists[MAX_ARTISTS];
Album *albums[MAX_ALBUMS];

int num_songs = 0;
int num_artists = 0;
int num_albums = 0;

void add_song(Song *song)
{
    songs[num_songs++] = song;
}

void add_artist(Artist *artist)
{
    artists[num_artists++] = artist;
}

void add_album(Album *album)
{
    albums[num_albums++] = album;
}

void print_songs()
{
    for (int i = 0; i < num_songs; i++)
    {
        printf("%s - %s - %s - %d - %.2f\n", songs[i]->title, songs[i]->artist, songs[i]->album, songs[i]->year, songs[i]->rating);
    }
}

void print_artists()
{
    for (int i = 0; i < num_artists; i++)
    {
        printf("%s - %s - %d\n", artists[i]->name, artists[i]->genre, artists[i]->num_songs);
    }
}

void print_albums()
{
    for (int i = 0; i < num_albums; i++)
    {
        printf("%s - %s - %d - %d\n", albums[i]->title, albums[i]->artist, albums[i]->year, albums[i]->num_songs);
    }
}

int main()
{
    // Create some songs
    Song *song1 = malloc(sizeof(Song));
    strcpy(song1->title, "Bohemian Rhapsody");
    strcpy(song1->artist, "Queen");
    strcpy(song1->album, "A Night at the Opera");
    song1->year = 1975;
    song1->rating = 5.0;
    add_song(song1);

    Song *song2 = malloc(sizeof(Song));
    strcpy(song2->title, "Imagine");
    strcpy(song2->artist, "John Lennon");
    strcpy(song2->album, "Imagine");
    song2->year = 1971;
    song2->rating = 4.5;
    add_song(song2);

    Song *song3 = malloc(sizeof(Song));
    strcpy(song3->title, "Strawberry Fields Forever");
    strcpy(song3->artist, "The Beatles");
    strcpy(song3->album, "Sgt. Pepper's Lonely Hearts Club Band");
    song3->year = 1967;
    song3->rating = 5.0;
    add_song(song3);

    // Create some artists
    Artist *artist1 = malloc(sizeof(Artist));
    strcpy(artist1->name, "Queen");
    strcpy(artist1->genre, "Rock");
    artist1->num_songs = 1;
    artist1->songs = song1;
    add_artist(artist1);

    Artist *artist2 = malloc(sizeof(Artist));
    strcpy(artist2->name, "John Lennon");
    strcpy(artist2->genre, "Rock");
    artist2->num_songs = 1;
    artist2->songs = song2;
    add_artist(artist2);

    Artist *artist3 = malloc(sizeof(Artist));
    strcpy(artist3->name, "The Beatles");
    strcpy(artist3->genre, "Rock");
    artist3->num_songs = 1;
    artist3->songs = song3;
    add_artist(artist3);

    // Create some albums
    Album *album1 = malloc(sizeof(Album));
    strcpy(album1->title, "A Night at the Opera");
    strcpy(album1->artist, "Queen");
    album1->year = 1975;
    album1->num_songs = 1;
    album1->songs = song1;
    add_album(album1);

    Album *album2 = malloc(sizeof(Album));
    strcpy(album2->title, "Imagine");
    strcpy(album2->artist, "John Lennon");
    album2->year = 1971;
    album2->num_songs = 1;
    album2->songs = song2;
    add_album(album2);

    Album *album3 = malloc(sizeof(Album));
    strcpy(album3->title, "Sgt. Pepper's Lonely Hearts Club Band");
    strcpy(album3->artist, "The Beatles");
    album3->year = 1967;
    album3->num_songs = 1;
    album3->songs = song3;
    add_album(album3);

    // Print the songs
    printf("Songs:\n");
    print_songs();

    // Print the artists
    printf("\nArtists:\n");
    print_artists();

    // Print the albums
    printf("\nAlbums:\n");
    print_albums();

    return 0;
}