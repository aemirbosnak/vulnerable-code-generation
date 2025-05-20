//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: random
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

// Create a linked list of music
Music* createMusicList() {
    return NULL;
}

// Insert a music into the linked list
void insertMusic(Music* head, Music* newMusic) {
    if (head == NULL) {
        head = newMusic;
    } else {
        newMusic->next = head;
        head = newMusic;
    }
}

// Search for music in the linked list
Music* searchMusic(Music* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Delete music from the linked list
void deleteMusic(Music* head, char* title) {
    Music* prev = NULL;
    Music* current = head;

    while (current) {
        if (strcmp(current->title, title) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    return;
}

int main() {
    Music* head = createMusicList();

    // Insert some music into the list
    insertMusic(head, malloc(sizeof(Music)));
    insertMusic(head, malloc(sizeof(Music)));
    insertMusic(head, malloc(sizeof(Music)));

    // Search for music in the list
    Music* foundMusic = searchMusic(head, "The Darkest Passenger");

    // If music is found, print its information
    if (foundMusic) {
        printf("Title: %s\n", foundMusic->title);
        printf("Artist: %s\n", foundMusic->artist);
        printf("Genre: %s\n", foundMusic->genre);
        printf("Year: %d\n", foundMusic->year);
    } else {
        printf("Music not found.\n");
    }

    // Delete music from the list
    deleteMusic(head, "The Darkest Passenger");

    // Search for music after deletion
    foundMusic = searchMusic(head, "The Darkest Passenger");

    // If music is found, print its information
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