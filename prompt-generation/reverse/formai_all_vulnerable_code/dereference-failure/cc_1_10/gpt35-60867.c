//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char artist[100];
    char album[100];
    char title[100];
    char genre[100];
    int year;
    int track;
} Metadata;

int main() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb"); // open file in binary mode
    if(fp == NULL) {
        printf("Error: Could not open %s\n", filename);
        return 1;
    }

    char tag[3];
    tag[2] = '\0';

    fseek(fp, -128L, SEEK_END); // move to end of file and back up 128 bytes
    fread(tag, 1, 3, fp); // read first 3 bytes

    if(strcmp(tag, "TAG") != 0) { // check if bytes are "TAG"
        printf("Error: No ID3 tag found in %s\n", filename);
        return 2;
    }

    Metadata song;

    fseek(fp, -125L, SEEK_END); // move back to the start of the tag
    fread(song.title, 1, 30, fp); // read title (30 bytes)
    fread(song.artist, 1, 30, fp); // read artist (30 bytes)
    fread(song.album, 1, 30, fp); // read album (30 bytes)
    fread(&song.year, 4, 1, fp); // read year (4 bytes)
    fread(song.genre, 1, 1, fp); // read genre (1 byte)
    fread(&song.track, 1, 1, fp); // read track (1 byte)

    fclose(fp);

    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Year: %d\n", song.year);
    printf("Genre: %s\n", song.genre);
    printf("Track: %d\n", song.track);

    return 0;
}