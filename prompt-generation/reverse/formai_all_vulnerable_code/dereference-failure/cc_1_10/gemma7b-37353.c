//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: excited
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

int main() {
    Music* head = NULL;

    // Insert some music
    insertMusic(&head, "Thriller", "Michael Jackson", "Pop", 1987);
    insertMusic(&head, "Bohemian Rhapsody", "Queen", "Rock", 1975);
    insertMusic(&head, "Like a Rolling Stone", "The Rolling Stones", "Rock", 1965);

    // Search for music by title
    Music* foundMusic = searchMusicByTitle(head, "Bohemian Rhapsody");

    // Print the found music
    if (foundMusic) {
        printf("Title: %s\n", foundMusic->title);
        printf("Artist: %s\n", foundMusic->artist);
        printf("Genre: %s\n", foundMusic->genre);
        printf("Year: %d\n", foundMusic->year);
    } else {
        printf("Music not found.\n");
    }

    return 0;
}