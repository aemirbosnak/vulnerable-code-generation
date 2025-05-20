//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct MusicTrack {
    char title[50];
    char artist[50];
    char genre[50];
    struct MusicTrack* next;
} MusicTrack;

MusicTrack* insert(MusicTrack* head, char* title, char* artist, char* genre) {
    MusicTrack* newTrack = (MusicTrack*)malloc(sizeof(MusicTrack));
    strcpy(newTrack->title, title);
    strcpy(newTrack->artist, artist);
    strcpy(newTrack->genre, genre);
    newTrack->next = NULL;

    if (head == NULL) {
        head = newTrack;
    } else {
        head->next = newTrack;
    }

    return head;
}

MusicTrack* search(MusicTrack* head, char* query) {
    MusicTrack* current = head;

    while (current) {
        if (strcmp(current->title, query) == 0 || strcmp(current->artist, query) == 0 || strcmp(current->genre, query) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void display(MusicTrack* head) {
    MusicTrack* current = head;

    printf("List of music tracks:\n");
    while (current) {
        printf("Title: %s\n", current->title);
        printf("Artist: %s\n", current->artist);
        printf("Genre: %s\n", current->genre);
        printf("\n");
        current = current->next;
    }
}

void update(MusicTrack* track, char* newTitle, char* newArtist, char* newGenre) {
    strcpy(track->title, newTitle);
    strcpy(track->artist, newArtist);
    strcpy(track->genre, newGenre);
}

void delete(MusicTrack* head, MusicTrack* track) {
    MusicTrack* previous = NULL;
    MusicTrack* current = head;

    while (current) {
        if (current == track) {
            if (previous) {
                previous->next = track->next;
            } else {
                head = track->next;
            }
            free(track);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

int main() {
    MusicTrack* head = NULL;

    // Insert some music tracks
    insert(head, "The Sound of Silence", "Led Zeppelin", "Rock");
    insert(head, "Stairway to Heaven", "Led Zeppelin", "Rock");
    insert(head, "Bohemian Rhapsody", "Queen", "Rock");
    insert(head, "Another One Bites the Dust", "Queen", "Rock");
    insert(head, "Black Magic Woman", " Santana", "Rock");

    // Search for music tracks
    MusicTrack* track = search(head, "Stairway to Heaven");
    if (track) {
        printf("Title: %s\n", track->title);
        printf("Artist: %s\n", track->artist);
        printf("Genre: %s\n", track->genre);
    }

    // Display all music tracks
    display(head);

    // Update music track information
    update(track, "Stairway to Heaven", "Led Zeppelin", "Classic Rock");

    // Delete music track
    delete(head, track);

    // Display updated list of music tracks
    display(head);

    return 0;
}