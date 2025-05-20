//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    char artist[50];
    int release_year;
} Song;

typedef struct Node {
    Song data;
    struct Node* next;
} Node;

Node* head = NULL;

void add_song(Song s) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = s;
    new_node->next = head;
    head = new_node;
}

void print_library() {
    Node* current = head;
    while (current != NULL) {
        printf("Title: %s\n", current->data.title);
        printf("Artist: %s\n", current->data.artist);
        printf("Release Year: %d\n", current->data.release_year);
        current = current->next;
    }
}

int main() {
    Song new_song = {"Bohemian Rhapsody", "Queen", 1975};
    add_song(new_song);

    Song another_song = {"We Will Rock You", "Queen", 1977};
    add_song(another_song);

    printf("Music Library:\n");
    print_library();

    Song shocking_song = {"Enter Sandman", "Metallica", 1991};
    add_song(shocking_song);

    printf("\nI CAN'T BELIEVE IT! We added a Metallica song to our music library!\n");
    print_library();

    return 0;
}