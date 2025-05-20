//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[100];
    int duration;
    char genre[100];
    struct Song *next;
};

struct Playlist {
    char name[100];
    struct Song *head;
    struct Playlist *next;
};

struct Song *createSong(char title[], char artist[], int duration, char genre[]) {
    struct Song *newSong = (struct Song*) malloc(sizeof(struct Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->duration = duration;
    strcpy(newSong->genre, genre);
    newSong->next = NULL;
    return newSong;
}

void addSongToLibrary(struct Song** library, char title[], char artist[], int duration, char genre[]) {
    struct Song *newSong = createSong(title, artist, duration, genre);
    if(*library == NULL) {
        *library = newSong;
    } else {
        struct Song *current = *library;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newSong;
    }
}

void addSongToPlaylist(struct Playlist** playlist, char playlistName[], char title[], char artist[], int duration, char genre[]) {
    if(*playlist == NULL) {
        struct Playlist *newPlaylist = (struct Playlist*) malloc(sizeof(struct Playlist));
        strcpy(newPlaylist->name, playlistName);
        newPlaylist->head = createSong(title, artist, duration, genre);
        newPlaylist->next = NULL;
        *playlist = newPlaylist;
    } else {
        struct Playlist *curPlaylist = *playlist;
        while(curPlaylist->next != NULL && strcmp(curPlaylist->name, playlistName) != 0) {
            curPlaylist = curPlaylist->next;
        }
        if(strcmp(curPlaylist->name, playlistName) == 0) {
            struct Song *newSong = createSong(title, artist, duration, genre);
            if(curPlaylist->head == NULL) {
                curPlaylist->head = newSong;
            } else {
                struct Song *current = curPlaylist->head;
                while(current->next != NULL) {
                    current = current->next;
                }
                current->next = newSong;
            }
        } else {
            struct Playlist *newPlaylist = (struct Playlist*) malloc(sizeof(struct Playlist));
            strcpy(newPlaylist->name, playlistName);
            newPlaylist->head = createSong(title, artist, duration, genre);
            newPlaylist->next = NULL;
            curPlaylist->next = newPlaylist;
        }
    }
}

void displayLibrary(struct Song* library) {
    printf("\n====Library====\n");
    while(library != NULL) {
        printf("Title: %s | Artist: %s | Duration: %d | Genre: %s\n", library->title, library->artist, library->duration, library->genre);
        library = library->next;
    }
}

void displayPlaylist(struct Playlist* playlist, char name[]) {
    while(playlist != NULL && strcmp(playlist->name, name) != 0) {
        playlist = playlist->next;
    }
    if(playlist == NULL) {
        printf("Playlist not found!\n");
        return;
    }
    printf("\n====%s Playlist====\n", playlist->name);
    struct Song *current = playlist->head;
    while(current != NULL) {
        printf("Title: %s | Artist: %s | Duration: %d | Genre: %s\n", current->title, current->artist, current->duration, current->genre);
        current = current->next;
    }
}

int main() {
    struct Song *library = NULL;
    struct Playlist *playlists = NULL;

    addSongToLibrary(&library, "Bad Guy", "Billie Eilish", 180, "Alternative");
    addSongToLibrary(&library, "Shape of You", "Ed Sheeran", 240, "Pop");
    addSongToLibrary(&library, "Closer", "The Chainsmokers ft. Halsey", 245, "Electronic");
    addSongToLibrary(&library, "Uptown Funk", "Mark Ronson ft. Bruno Mars", 300, "Pop");
    addSongToPlaylist(&playlists, "Driving", "Bad Guy", "Billie Eilish", 180, "Alternative");
    addSongToPlaylist(&playlists, "Driving", "Lost in Japan", "Shawn Mendes", 210, "Pop");

    displayLibrary(library);
    displayPlaylist(playlists, "Driving");

    return 0;
}