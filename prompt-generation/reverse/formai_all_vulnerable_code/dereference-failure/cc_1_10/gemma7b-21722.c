//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store music information
typedef struct Music {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Music* next;
} Music;

// Function to insert a new music into the linked list
void insert(Music* head, Music* newMusic) {
    if (head == NULL) {
        head = newMusic;
    } else {
        newMusic->next = head;
        head = newMusic;
    }
}

// Function to search for music by title
Music* searchByTitle(Music* head, char* title) {
    Music* current = head;
    while (current) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to search for music by artist
Music* searchByArtist(Music* head, char* artist) {
    Music* current = head;
    while (current) {
        if (strcmp(current->artist, artist) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to search for music by genre
Music* searchByGenre(Music* head, char* genre) {
    Music* current = head;
    while (current) {
        if (strcmp(current->genre, genre) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print music information
void printMusic(Music* music) {
    printf("Title: %s\n", music->title);
    printf("Artist: %s\n", music->artist);
    printf("Genre: %s\n", music->genre);
    printf("Year: %d\n", music->year);
    printf("\n");
}

int main() {
    Music* head = NULL;

    // Insert some music into the linked list
    insert(head, malloc(sizeof(Music)));
    insert(head, malloc(sizeof(Music)));
    insert(head, malloc(sizeof(Music)));

    // Print music information
    printMusic(head);

    // Search for music by title
    Music* music = searchByTitle(head, "Song 1");
    if (music) {
        printMusic(music);
    }

    // Search for music by artist
    music = searchByArtist(head, "Artist 1");
    if (music) {
        printMusic(music);
    }

    // Search for music by genre
    music = searchByGenre(head, "Genre 1");
    if (music) {
        printMusic(music);
    }

    return 0;
}