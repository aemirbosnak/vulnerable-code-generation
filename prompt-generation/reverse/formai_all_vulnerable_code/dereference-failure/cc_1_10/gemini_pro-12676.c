//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} Song;

typedef struct node {
    Song song;
    struct node *next;
} Node;

Node *head = NULL;

void add_song(Song song) {
    Node *new_node = malloc(sizeof(Node));
    new_node->song = song;
    new_node->next = head;
    head = new_node;
}

void print_songs() {
    Node *current = head;
    while (current != NULL) {
        printf("%s by %s from %s (%d)\n", current->song.title, current->song.artist, current->song.album, current->song.year);
        current = current->next;
    }
}

void free_songs() {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975};
    Song song2 = {"Imagine", "John Lennon", "Imagine", 1971};
    Song song3 = {"Strawberry Fields Forever", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967};
    Song song4 = {"Superstition", "Stevie Wonder", "Superstition", 1972};
    Song song5 = {"Rocket Man", "Elton John", "Honky Château", 1972};

    add_song(song1);
    add_song(song2);
    add_song(song3);
    add_song(song4);
    add_song(song5);

    print_songs();

    free_songs();

    return 0;
}