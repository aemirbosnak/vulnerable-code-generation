//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: energetic
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

// Function to insert a music into the linked list
void insertMusic(Music** head, char* title, char* artist, char* genre, int year) {
    Music* newMusic = (Music*)malloc(sizeof(Music));
    strcpy(newMusic->title, title);
    strcpy(newMusic->artist, artist);
    strcpy(newMusic->genre, genre);
    newMusic->year = year;
    newMusic->next = NULL;

    if (*head == NULL) {
        *head = newMusic;
    } else {
        (*head)->next = newMusic;
    }
}

// Function to search for music by title
Music* searchMusicByTitle(Music* head, char* title) {
    Music* currentMusic = head;
    while (currentMusic) {
        if (strcmp(currentMusic->title, title) == 0) {
            return currentMusic;
        }
        currentMusic = currentMusic->next;
    }
    return NULL;
}

// Function to search for music by artist
Music* searchMusicByArtist(Music* head, char* artist) {
    Music* currentMusic = head;
    while (currentMusic) {
        if (strcmp(currentMusic->artist, artist) == 0) {
            return currentMusic;
        }
        currentMusic = currentMusic->next;
    }
    return NULL;
}

// Function to search for music by genre
Music* searchMusicByGenre(Music* head, char* genre) {
    Music* currentMusic = head;
    while (currentMusic) {
        if (strcmp(currentMusic->genre, genre) == 0) {
            return currentMusic;
        }
        currentMusic = currentMusic->next;
    }
    return NULL;
}

// Function to print all music
void printMusic(Music* head) {
    Music* currentMusic = head;
    while (currentMusic) {
        printf("%s by %s (%d) - %s\n", currentMusic->title, currentMusic->artist, currentMusic->year, currentMusic->genre);
        currentMusic = currentMusic->next;
    }
}

int main() {
    Music* head = NULL;

    // Insert some music
    insertMusic(&head, "Bohemian Rhapsody", "Queen", "Rock", 1975);
    insertMusic(&head, "Thriller", "Michael Jackson", "Pop", 1987);
    insertMusic(&head, "Like a Rolling Stone", "The Rolling Stones", "Rock", 1965);

    // Search for music by title
    Music* foundMusic = searchMusicByTitle(head, "Bohemian Rhapsody");
    if (foundMusic) {
        printf("Found music: %s\n", foundMusic->title);
    }

    // Search for music by artist
    foundMusic = searchMusicByArtist(head, "Queen");
    if (foundMusic) {
        printf("Found music: %s\n", foundMusic->title);
    }

    // Search for music by genre
    foundMusic = searchMusicByGenre(head, "Rock");
    if (foundMusic) {
        printf("Found music: %s\n", foundMusic->title);
    }

    // Print all music
    printMusic(head);

    return 0;
}