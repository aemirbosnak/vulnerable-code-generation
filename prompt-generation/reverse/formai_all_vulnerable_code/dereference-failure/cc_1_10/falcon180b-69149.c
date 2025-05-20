//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LEN 100
#define MAX_ARTIST_LEN 50
#define MAX_ALBUM_LEN 100
#define MAX_GENRE_LEN 50
#define MAX_TRACK_NUMBER 10
#define MAX_YEAR 4

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char genre[MAX_GENRE_LEN];
    char track_number[MAX_TRACK_NUMBER];
    char year[MAX_YEAR];
} Song;

void print_song(Song *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Genre: %s\n", song->genre);
    printf("Track Number: %s\n", song->track_number);
    printf("Year: %s\n", song->year);
}

int main(int argc, char *argv[]) {
    Song song;
    FILE *fp;
    char line[256];
    int i = 0;

    if(argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while(fgets(line, sizeof(line), fp)!= NULL) {
        if(i == 0) {
            strcpy(song.title, line);
        }
        else if(i == 1) {
            strcpy(song.artist, line);
        }
        else if(i == 2) {
            strcpy(song.album, line);
        }
        else if(i == 3) {
            strcpy(song.genre, line);
        }
        else if(i == 4) {
            strcpy(song.track_number, line);
        }
        else if(i == 5) {
            strcpy(song.year, line);
        }
        i++;
    }

    fclose(fp);
    print_song(&song);

    return 0;
}