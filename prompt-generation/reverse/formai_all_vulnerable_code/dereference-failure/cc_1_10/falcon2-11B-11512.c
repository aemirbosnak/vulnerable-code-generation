//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Album
{
    char title[100];
    char artist[100];
    int year;
    int genre;
    int price;
};

struct Album* newAlbum(char title[], char artist[], int year, int genre, int price)
{
    struct Album* album = (struct Album*)malloc(sizeof(struct Album));
    strcpy(album->title, title);
    strcpy(album->artist, artist);
    album->year = year;
    album->genre = genre;
    album->price = price;
    return album;
}

void displayAlbum(struct Album* album)
{
    printf("Title: %s\n", album->title);
    printf("Artist: %s\n", album->artist);
    printf("Year: %d\n", album->year);
    printf("Genre: %d\n", album->genre);
    printf("Price: %d\n\n", album->price);
}

void updateAlbum(struct Album* album, char title[], char artist[], int year, int genre, int price)
{
    strcpy(album->title, title);
    strcpy(album->artist, artist);
    album->year = year;
    album->genre = genre;
    album->price = price;
}

int deleteAlbum(struct Album* album)
{
    free(album);
    return 0;
}

int main()
{
    struct Album* album = newAlbum("The Dark Side of the Moon", "Pink Floyd", 1973, 1, 25);
    displayAlbum(album);

    updateAlbum(album, "The Wall", "Pink Floyd", 1979, 2, 15);
    displayAlbum(album);

    deleteAlbum(album);

    return 0;
}