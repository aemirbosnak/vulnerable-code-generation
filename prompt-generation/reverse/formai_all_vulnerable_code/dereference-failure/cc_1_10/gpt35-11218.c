//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* artist;
    char* album;
    int year;
    char* genre;
} Metadata;

int main() {
    Metadata song1, song2;
    song1.artist = "The Beatles";
    song1.album = "Sgt. Pepper's Lonely Hearts Club Band";
    song1.year = 1967;
    song1.genre = "Rock";
    
    song2.artist = "Michael Jackson";
    song2.album = "Thriller";
    song2.year = 1982;
    song2.genre = "Pop";
    
    printf("Song 1 Details:\n");
    printf("Artist: %s\nAlbum: %s\nYear: %d\nGenre: %s\n\n", song1.artist, song1.album, song1.year, song1.genre);
    
    printf("Song 2 Details:\n");
    printf("Artist: %s\nAlbum: %s\nYear: %d\nGenre: %s\n\n", song2.artist, song2.album, song2.year, song2.genre);
    
    // Let's extract some metadata from a file
    FILE* fp;
    char* filename = "example_file.mp3";
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }
    
    // We will assume that the metadata is in the first 128 bytes of the file
    char buffer[128];
    fread(buffer, sizeof(char), 128, fp);
    
    // The first 3 bytes of the buffer contain the ID3 metadata
    char id3[4], title[31], track[4], artist[31], genre[31], year[4], album[31];
    strncpy(id3, buffer, 3);
    id3[3] = '\0';
    
    if (strcmp(id3, "ID3") != 0) {
        printf("Error - Invalid ID3 tag found!\n");
        return 1;
    }
    
    // Track name
    strncpy(title, buffer+3, 30);
    title[30] = '\0';
    
    // Artist name
    strncpy(artist, buffer+33, 30);
    artist[30] = '\0';
    
    // Album name
    strncpy(album, buffer+63, 30);
    album[30] = '\0';
    
    // Year
    strncpy(year, buffer+93, 4);
    year[4] = '\0';
    
    // Track number
    strncpy(track, buffer+97, 1);
    track[1] = '\0';
    
    // Genre
    strncpy(genre, buffer+127, 1);
    genre[1] = '\0';
    
    fclose(fp);
    
    printf("Metadata Extracted:\n");
    printf("Title: %s\nArtist: %s\nAlbum: %s\nYear: %s\nTrack: %s\nGenre: %s\n\n", title, artist, album, year, track, genre);
    
    return 0;
}