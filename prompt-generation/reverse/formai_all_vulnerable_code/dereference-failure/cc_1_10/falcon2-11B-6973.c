//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 50
#define MAX_GENRE_LEN 20
#define MAX_YEAR_LEN 4
#define MAX_SIZE 1024

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char genre[MAX_GENRE_LEN];
    char year[MAX_YEAR_LEN];
    int size;
} Album;

int main() {
    Album* albums = malloc(MAX_SIZE * sizeof(Album));
    int num_albums = 0;

    printf("Welcome to the medieval music library management system!\n");
    printf("Please enter the number of albums in the library:\n");
    scanf("%d", &num_albums);

    for (int i = 0; i < num_albums; i++) {
        Album album;
        printf("Album %d:\n", i + 1);
        printf("Title: ");
        scanf("%s", album.title);
        printf("Artist: ");
        scanf("%s", album.artist);
        printf("Genre: ");
        scanf("%s", album.genre);
        printf("Year: ");
        scanf("%s", album.year);
        printf("Size (in bytes): ");
        scanf("%d", &album.size);

        albums[i] = album;
    }

    printf("The following albums are in the library:\n");
    for (int i = 0; i < num_albums; i++) {
        Album album = albums[i];
        printf("%d. %s - %s (%s, %d)\n", i + 1, album.title, album.artist, album.genre, album.size);
    }

    free(albums);
    return 0;
}