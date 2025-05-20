//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Music Library Management System (MLMS) structure
typedef struct MusicLibrary {
    char title[256];
    char artist[256];
    char genre[256];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a new music entry into the library
MusicLibrary* insertMusicEntry(MusicLibrary* head) {
    MusicLibrary* newEntry = (MusicLibrary*)malloc(sizeof(MusicLibrary));

    printf("Enter the title of the music: ");
    scanf("%s", newEntry->title);

    printf("Enter the artist of the music: ");
    scanf("%s", newEntry->artist);

    printf("Enter the genre of the music: ");
    scanf("%s", newEntry->genre);

    printf("Enter the year of the music: ");
    scanf("%d", &newEntry->year);

    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

// Function to search the music library for a particular entry
MusicLibrary* searchMusicEntry(MusicLibrary* head, char* title) {
    MusicLibrary* current = head;

    while (current) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to delete a music entry from the library
void deleteMusicEntry(MusicLibrary* head, char* title) {
    MusicLibrary* current = head;
    MusicLibrary* previous = NULL;

    while (current) {
        if (strcmp(current->title, title) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

int main() {
    MusicLibrary* head = NULL;

    // Insert some music entries
    insertMusicEntry(head);
    insertMusicEntry(head);
    insertMusicEntry(head);

    // Search for a music entry
    MusicLibrary* entry = searchMusicEntry(head, "The Darkest Hour");

    // Delete a music entry
    deleteMusicEntry(head, "Another One Bites the Dust");

    return 0;
}