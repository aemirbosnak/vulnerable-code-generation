//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_ARTIST 100
#define MAX_ALBUM 100
#define MAX_GENRE 100
#define MAX_TRACK_NUM 10
#define MAX_FILE_NAME 100

struct track {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    char album[MAX_ALBUM];
    char genre[MAX_GENRE];
    int track_num;
    char file_name[MAX_FILE_NAME];
};

void add_track(struct track *library, int num_tracks) {
    printf("Enter track title: ");
    scanf("%s", library[num_tracks].title);
    printf("Enter artist name: ");
    scanf("%s", library[num_tracks].artist);
    printf("Enter album name: ");
    scanf("%s", library[num_tracks].album);
    printf("Enter genre: ");
    scanf("%s", library[num_tracks].genre);
    printf("Enter track number: ");
    scanf("%d", &library[num_tracks].track_num);
    printf("Enter file name: ");
    scanf("%s", library[num_tracks].file_name);
}

void display_track(struct track track) {
    printf("Title: %s\n", track.title);
    printf("Artist: %s\n", track.artist);
    printf("Album: %s\n", track.album);
    printf("Genre: %s\n", track.genre);
    printf("Track Number: %d\n", track.track_num);
    printf("File Name: %s\n", track.file_name);
}

void search_track(struct track *library, int num_tracks, char *query) {
    int i;
    for(i=0; i<num_tracks; i++) {
        if(strstr(library[i].title, query) || strstr(library[i].artist, query) || strstr(library[i].album, query) || strstr(library[i].genre, query)) {
            display_track(library[i]);
        }
    }
}

int main() {
    int num_tracks;
    printf("Enter number of tracks: ");
    scanf("%d", &num_tracks);

    struct track library[num_tracks];

    int i;
    for(i=0; i<num_tracks; i++) {
        add_track(library, i);
    }

    char query[MAX_TITLE];
    printf("Enter search query: ");
    scanf("%s", query);

    search_track(library, num_tracks, query);

    return 0;
}