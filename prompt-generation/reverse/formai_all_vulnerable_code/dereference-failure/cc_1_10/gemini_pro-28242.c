//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct music_library {
    char *name;
    char *artist;
    int year;
    int tracks;
    float rating;
};

struct music_library_node {
    struct music_library music_library;
    struct music_library_node *next;
};

struct music_library_node *head = NULL;
struct music_library_node *tail = NULL;

void add_music_library(char *name, char *artist, int year, int tracks, float rating) {
    struct music_library_node *new_node = malloc(sizeof(struct music_library_node));
    new_node->music_library.name = malloc(strlen(name) + 1);
    strcpy(new_node->music_library.name, name);
    new_node->music_library.artist = malloc(strlen(artist) + 1);
    strcpy(new_node->music_library.artist, artist);
    new_node->music_library.year = year;
    new_node->music_library.tracks = tracks;
    new_node->music_library.rating = rating;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void print_music_library() {
    struct music_library_node *current_node = head;

    while (current_node != NULL) {
        printf("Name: %s\n", current_node->music_library.name);
        printf("Artist: %s\n", current_node->music_library.artist);
        printf("Year: %d\n", current_node->music_library.year);
        printf("Tracks: %d\n", current_node->music_library.tracks);
        printf("Rating: %f\n\n", current_node->music_library.rating);

        current_node = current_node->next;
    }
}

int main() {
    add_music_library("The Dark Side of the Moon", "Pink Floyd", 1973, 10, 4.5);
    add_music_library("Sgt. Pepper's Lonely Hearts Club Band", "The Beatles", 1967, 13, 4.8);
    add_music_library("Pet Sounds", "The Beach Boys", 1966, 14, 4.7);
    add_music_library("Revolver", "The Beatles", 1966, 14, 4.9);
    add_music_library("Rubber Soul", "The Beatles", 1965, 14, 4.8);

    print_music_library();

    return 0;
}