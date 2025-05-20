//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music information
typedef struct Music {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Music* next;
} Music;

// Function to insert a music into the linked list
void insertMusic(Music* head, Music* newMusic) {
    if (head == NULL) {
        head = newMusic;
    } else {
        newMusic->next = head;
        head = newMusic;
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

    // Insert some music into the list
    Music* newMusic1 = malloc(sizeof(Music));
    strcpy(newMusic1->title, "The Darkest Shadow");
    strcpy(newMusic1->artist, "The Lord of Darkness");
    strcpy(newMusic1->genre, "Death Metal");
    newMusic1->year = 1994;
    insertMusic(head, newMusic1);

    Music* newMusic2 = malloc(sizeof(Music));
    strcpy(newMusic2->title, "Master of Puppets");
    strcpy(newMusic2->artist, "Iron Maiden");
    strcpy(newMusic2->genre, "Heavy Metal");
    newMusic2->year = 1982;
    insertMusic(head, newMusic2);

    Music* newMusic3 = malloc(sizeof(Music));
    strcpy(newMusic3->title, "The Number of the Beast");
    strcpy(newMusic3->artist, "Iron Maiden");
    strcpy(newMusic3->genre, "Heavy Metal");
    newMusic3->year = 1982;
    insertMusic(head, newMusic3);

    // Search for music by title
    Music* foundMusic = searchMusicByTitle(head, "The Darkest Shadow");
    if (foundMusic) {
        printMusic(foundMusic);
    } else {
        printf("Music not found.\n");
    }

    // Search for music by artist
    foundMusic = searchMusicByArtist(head, "Iron Maiden");
    if (foundMusic) {
        printMusic(foundMusic);
    } else {
        printf("Music not found.\n");
    }

    // Search for music by genre
    foundMusic = searchMusicByGenre(head, "Heavy Metal");
    if (foundMusic) {
        printMusic(foundMusic);
    } else {
        printf("Music not found.\n");
    }

    return 0;
}