//FormAI DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50

typedef struct Song {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int year;
} Song;

typedef struct Node {
    Song* song;
    struct Node* next;
} Node;

Node* library = NULL;

Song* create_song(char* name, char* artist, char* album, int year) {
    Song* song = malloc(sizeof(Song));
    strcpy(song->name, name);
    strcpy(song->artist, artist);
    strcpy(song->album, album);
    song->year = year;
    return song;
}

void add_song(char* name, char* artist, char* album, int year) {
    Song* song = create_song(name, artist, album, year);
    Node* new_node = malloc(sizeof(Node));
    new_node->song = song;
    new_node->next = NULL;

    if (library == NULL) {
        library = new_node;
    }
    else {
        Node* curr = library;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void remove_song(char* name, char* artist) {
    if (library == NULL) {
        return;
    }
    if (strcmp(library->song->name, name) == 0 && strcmp(library->song->artist, artist) == 0) {
        Node* temp = library;
        library = library->next;
        free(temp->song);
        free(temp);
        return;
    }
    Node* curr = library;
    while (curr->next != NULL) {
        if (strcmp(curr->next->song->name, name) == 0 && strcmp(curr->next->song->artist, artist) == 0) {
            Node* temp = curr->next;
            curr->next = temp->next;
            free(temp->song);
            free(temp);
            return;
        }
        curr = curr->next;
    }
}

void print_library() {
    if (library == NULL) {
        printf("The library is empty.\n");
        return;
    }
    Node* curr = library;
    while (curr != NULL) {
        printf("%s by %s from %s (%d)\n", curr->song->name, curr->song->artist, curr->song->album, curr->song->year);
        curr = curr->next;
    }
}

int main() {
    add_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
    add_song("Imagine", "John Lennon", "Imagine", 1971);
    add_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);

    printf("Printing the library:\n");
    print_library();

    printf("\nRemoving \"Imagine\" by John Lennon.\n");
    remove_song("Imagine", "John Lennon");

    printf("\nPrinting the library again:\n");
    print_library();

    return 0;
}