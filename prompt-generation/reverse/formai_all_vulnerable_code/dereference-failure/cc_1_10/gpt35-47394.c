//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SONG_LENGTH 100
#define MAX_PLAYLIST_LENGTH 50
#define MAX_PLAYLISTS 10

typedef struct song {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
    int duration;
    struct song* next;
} Song;

Song* create_song(char name[], char artist[], int duration) {
    Song* song = malloc(sizeof(Song));
    strncpy(song->name, name, MAX_NAME_LENGTH);
    strncpy(song->artist, artist, MAX_NAME_LENGTH);
    song->duration = duration;
    song->next = NULL;
    return song;
}

void free_song(Song* song) {
    free(song);
}

typedef struct playlist {
    char name[MAX_NAME_LENGTH];
    Song* head;
} Playlist;

Playlist* create_playlist(char name[]) {
    Playlist* playlist = malloc(sizeof(Playlist));
    strncpy(playlist->name, name, MAX_NAME_LENGTH);
    playlist->head = NULL;
    return playlist;
}

void add_song_to_playlist(Song* song, Playlist* playlist) {
    Song* current = playlist->head;
    if (!current) {
        playlist->head = song;
    } else {
        while (current->next) {
            current = current->next;
        }
        current->next = song;
    }
}

void remove_song_from_playlist(char name[], Playlist* playlist) {
    Song* current = playlist->head;
    Song* prev = NULL;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (!prev) {
                playlist->head = current->next;
            } else {
                prev->next = current->next;
            }
            free_song(current);
            printf("Song %s removed from playlist %s\n", name, playlist->name);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Song %s not found in playlist %s\n", name, playlist->name);
}

void print_song(Song* song) {
    printf("%s by %s (%ds)\n", song->name, song->artist, song->duration);
}

void print_playlist(Playlist* playlist) {
    printf("Playlist: %s\n", playlist->name);
    Song* current = playlist->head;
    while (current) {
        print_song(current);
        current = current->next;
    }
    printf("\n");
}

typedef struct library {
    Playlist* playlists[MAX_PLAYLISTS];
    int num_playlists;
} Library;

Library* create_library() {
    Library* library = malloc(sizeof(Library));
    library->num_playlists = 0;
    return library;
}

void add_playlist(Library* library, Playlist* playlist) {
    if (library->num_playlists >= MAX_PLAYLISTS) {
        printf("Max number of playlists reached\n");
        return;
    }
    library->playlists[library->num_playlists] = playlist;
    library->num_playlists++;
}

void remove_playlist(char name[], Library* library) {
    int i;
    for (i = 0; i < library->num_playlists; i++) {
        if (strcmp(library->playlists[i]->name, name) == 0) {
            free(library->playlists[i]);
            library->playlists[i] = library->playlists[library->num_playlists - 1];
            library->num_playlists--;
            printf("Playlist %s removed from library\n", name);
            return;
        }
    }
    printf("Playlist %s not found in library\n", name);
}

void print_library(Library* library) {
    printf("Library:\n\n");
    int i;
    for (i = 0; i < library->num_playlists; i++) {
        print_playlist(library->playlists[i]);
    }
}

int main() {
    Library* library = create_library();
    Playlist* playlist1 = create_playlist("Rock");
    add_song_to_playlist(create_song("Bohemian Rhapsody", "Queen", 300), playlist1);
    add_song_to_playlist(create_song("Sweet Child O' Mine", "Guns N' Roses", 310), playlist1);
    add_song_to_playlist(create_song("Stairway to Heaven", "Led Zeppelin", 480), playlist1);
    add_playlist(library, playlist1);
    
    Playlist* playlist2 = create_playlist("Pop");
    add_song_to_playlist(create_song("Uptown Funk", "Mark Ronson ft. Bruno Mars", 268), playlist2);
    add_song_to_playlist(create_song("Shape of You", "Ed Sheeran", 231), playlist2);
    add_song_to_playlist(create_song("Bad Guy", "Billie Eilish", 196), playlist2);
    add_playlist(library, playlist2);
    
    print_library(library);
    
    remove_song_from_playlist("Sweet Child O' Mine", playlist1);
    remove_playlist("Pop", library);
    
    print_library(library);
    
    return 0;
}