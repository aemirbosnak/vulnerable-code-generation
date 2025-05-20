//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <string.h>

#define MAX_SONG_NUM 100

typedef struct Song {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Song* next;
} Song;

Song* head = NULL;

void insert_song(char* title, char* artist, char* genre, int year) {
    Song* new_song = (Song*)malloc(sizeof(Song));
    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    strcpy(new_song->genre, genre);
    new_song->year = year;
    new_song->next = NULL;

    if (head == NULL) {
        head = new_song;
    } else {
        Song* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_song;
    }
}

void search_song(char* title) {
    Song* current = head;
    while (current) {
        if (strcmp(current->title, title) == 0) {
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n", current->artist);
            printf("Genre: %s\n", current->genre);
            printf("Year: %d\n", current->year);
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Song not found.\n");
    }
}

void update_song(char* title, char* new_title, char* new_artist, char* new_genre, int new_year) {
    Song* current = head;
    while (current) {
        if (strcmp(current->title, title) == 0) {
            strcpy(current->title, new_title);
            strcpy(current->artist, new_artist);
            strcpy(current->genre, new_genre);
            current->year = new_year;
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Song not found.\n");
    }
}

void delete_song(char* title) {
    Song* current = head;
    Song* previous = NULL;
    while (current) {
        if (strcmp(current->title, title) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Song not found.\n");
    }
}

int main() {
    insert_song("Song 1", "Artist 1", "Genre 1", 2020);
    insert_song("Song 2", "Artist 2", "Genre 2", 2021);
    insert_song("Song 3", "Artist 3", "Genre 3", 2022);

    search_song("Song 2");

    update_song("Song 2", "New Song 2", "New Artist 2", "New Genre 2", 2023);

    delete_song("Song 3");

    search_song("Song 2");

    return 0;
}