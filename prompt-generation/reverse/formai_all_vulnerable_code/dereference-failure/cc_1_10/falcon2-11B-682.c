//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* title;
    int length;
    int bitrate;
    char* artist;
    char* album;
    char* genre;
} Music;

void add_song(Music* song) {
    printf("Song added successfully\n");
}

void list_songs() {
    Music* songs = malloc(sizeof(Music));
    songs->title = "Paranoia";
    songs->length = 3;
    songs->bitrate = 128;
    songs->artist = "Rage Against the Machine";
    songs->album = "The Battle of Los Angeles";
    songs->genre = "Rock";

    add_song(songs);

    Music* song = malloc(sizeof(Music));
    song->title = "System of a Down";
    song->length = 4;
    song->bitrate = 256;
    song->artist = "System of a Down";
    song->album = "Toxicity";
    song->genre = "Alternative Metal";

    add_song(song);

    Music* song2 = malloc(sizeof(Music));
    song2->title = "Pink Floyd";
    song2->length = 5;
    song2->bitrate = 320;
    song2->artist = "Pink Floyd";
    song2->album = "The Wall";
    song2->genre = "Progressive Rock";

    add_song(song2);

    list_songs();
}

int main() {
    list_songs();

    return 0;
}