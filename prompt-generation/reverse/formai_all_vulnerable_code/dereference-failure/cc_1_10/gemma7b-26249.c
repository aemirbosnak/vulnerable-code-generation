//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: detailed
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

// Function to insert a new music into the list
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
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to search for music by artist
Music* searchMusicByArtist(Music* head, char* artist) {
    while (head) {
        if (strcmp(head->artist, artist) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to search for music by genre
Music* searchMusicByGenre(Music* head, char* genre) {
    while (head) {
        if (strcmp(head->genre, genre) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to print music information
void printMusic(Music* head) {
    while (head) {
        printf("Title: %s\n", head->title);
        printf("Artist: %s\n", head->artist);
        printf("Genre: %s\n", head->genre);
        printf("Year: %d\n", head->year);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Music* head = NULL;

    // Insert some music
    insertMusic(&head, "The Darkest Hour", "The Who", "Rock", 1969);
    insertMusic(&head, "Stairway to Heaven", "Led Zeppelin", "Rock", 1969);
    insertMusic(&head, "Yesterday", "The Beatles", "Rock", 1967);
    insertMusic(&head, "Like a Rolling Stone", "The Stones", "Rock", 1965);

    // Print music information
    printMusic(head);

    // Search for music by title
    Music* foundMusic = searchMusicByTitle(head, "Stairway to Heaven");
    if (foundMusic) {
        printf("Found music: %s\n", foundMusic->title);
    }

    // Search for music by artist
    foundMusic = searchMusicByArtist(head, "The Who");
    if (foundMusic) {
        printf("Found music: %s\n", foundMusic->title);
    }

    // Search for music by genre
    foundMusic = searchMusicByGenre(head, "Rock");
    if (foundMusic) {
        printf("Found music: %s\n", foundMusic->title);
    }

    return 0;
}