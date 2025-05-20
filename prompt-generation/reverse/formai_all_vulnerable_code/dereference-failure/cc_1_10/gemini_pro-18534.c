//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music_library {
    char *name;
    char *artist;
    char *album;
    int year;
    int track;
    int duration;
} music_library;

typedef struct node {
    music_library *data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void add_song(music_library *song) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = song;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void print_library() {
    node *current = head;
    while (current != NULL) {
        printf("%s by %s from %d\n", current->data->name, current->data->artist, current->data->year);
        current = current->next;
    }
}

int main() {
    music_library *song1 = (music_library *) malloc(sizeof(music_library));
    song1->name = "Bohemian Rhapsody";
    song1->artist = "Queen";
    song1->album = "A Night at the Opera";
    song1->year = 1975;
    song1->track = 1;
    song1->duration = 355;
    add_song(song1);

    music_library *song2 = (music_library *) malloc(sizeof(music_library));
    song2->name = "Stairway to Heaven";
    song2->artist = "Led Zeppelin";
    song2->album = "Led Zeppelin IV";
    song2->year = 1971;
    song2->track = 4;
    song2->duration = 480;
    add_song(song2);

    music_library *song3 = (music_library *) malloc(sizeof(music_library));
    song3->name = "Hotel California";
    song3->artist = "The Eagles";
    song3->album = "Hotel California";
    song3->year = 1976;
    song3->track = 3;
    song3->duration = 382;
    add_song(song3);

    print_library();

    return 0;
}