//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100

typedef struct Song {
    char title[MAX_TITLE_LENGTH];
    struct Song* next;
} Song;

typedef struct Playlist {
    Song* head;
    int size;
} Playlist;

// Function to initialize the playlist
Playlist* createPlaylist() {
    Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
    if (!playlist) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    playlist->head = NULL;
    playlist->size = 0;
    printf("🎵 New Playlist Created! 🎵\n");
    return playlist;
}

// Function to create a new song
Song* createSong(const char* title) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    if (!newSong) {
        printf("Memory allocation failed for song!\n");
        exit(1);
    }
    strncpy(newSong->title, title, MAX_TITLE_LENGTH);
    newSong->next = NULL;
    printf("🎶 Song '%s' added to memory! 🎶\n", title);
    return newSong;
}

// Function to add a song to the playlist
void addSong(Playlist* playlist, const char* title) {
    Song* newSong = createSong(title);
    if (playlist->head == NULL) {
        playlist->head = newSong;
    } else {
        Song* temp = playlist->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
    playlist->size++;
    printf("🎉 Added '%s' to the playlist! Total songs: %d 🎉\n", title, playlist->size);
}

// Function to display the playlist
void displayPlaylist(Playlist* playlist) {
    if (playlist->size == 0) {
        printf("Your playlist is empty! 🌌\n");
        return;
    }
    printf("🎤 Your Playlist 🎤\n");
    Song* temp = playlist->head;
    while (temp != NULL) {
        printf(" - %s\n", temp->title);
        temp = temp->next;
    }
}

// Function to remove a song from the playlist
void removeSong(Playlist* playlist, const char* title) {
    if (playlist->size == 0) {
        printf("Your playlist is already empty! 🌪️\n");
        return;
    }

    Song* temp = playlist->head;
    Song* prev = NULL;

    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song '%s' not found in the playlist! 🚫\n", title);
        return;
    }

    if (prev == NULL) {
        playlist->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    playlist->size--;
    printf("🎊 Removed '%s' from the playlist! Songs left: %d 🎊\n", title, playlist->size);
}

// Function to free all memory used by the playlist
void freePlaylist(Playlist* playlist) {
    Song* current = playlist->head;
    Song* next;

    while (current != NULL) {
        next = current->next;
        printf("💔 Freeing song '%s' from memory! 💔\n", current->title);
        free(current);
        current = next;
    }

    free(playlist);
    printf("🌟 Playlist memory freed! Goodbye! 🌟\n");
}

int main() {
    Playlist* myPlaylist = createPlaylist();

    addSong(myPlaylist, "Song of Storms");
    addSong(myPlaylist, "Dance of the Sugar Plum Fairy");
    addSong(myPlaylist, "The Sound of Silence");
    displayPlaylist(myPlaylist);

    removeSong(myPlaylist, "Dance of the Sugar Plum Fairy");
    displayPlaylist(myPlaylist);

    removeSong(myPlaylist, "Not in Playlist"); // Attempt to remove a non-existing song

    freePlaylist(myPlaylist); // Free all the memory
    return 0;
}