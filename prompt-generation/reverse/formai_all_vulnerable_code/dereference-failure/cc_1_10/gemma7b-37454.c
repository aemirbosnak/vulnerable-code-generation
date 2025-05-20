//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Music Library Management System structure
typedef struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a new music into the library
void insertMusic(MusicLibrary** head) {
    MusicLibrary* newMusic = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    printf("Enter the title: ");
    scanf("%s", newMusic->title);
    printf("Enter the artist: ");
    scanf("%s", newMusic->artist);
    printf("Enter the genre: ");
    scanf("%s", newMusic->genre);
    printf("Enter the year: ");
    scanf("%d", &newMusic->year);

    newMusic->next = NULL;

    if (*head == NULL) {
        *head = newMusic;
    } else {
        (*head)->next = newMusic;
    }
}

// Function to search for music in the library
MusicLibrary* searchMusic(MusicLibrary* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to delete music from the library
void deleteMusic(MusicLibrary* head, char* title) {
    MusicLibrary* prev = NULL;
    MusicLibrary* current = head;

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

// Main function
int main() {
    MusicLibrary* head = NULL;

    // Insert some music into the library
    insertMusic(&head);
    insertMusic(&head);
    insertMusic(&head);

    // Search for music in the library
    MusicLibrary* foundMusic = searchMusic(head, "The Beatles - Let Us Be Together");

    // If music is found, print its details
    if (foundMusic) {
        printf("Title: %s\n", foundMusic->title);
        printf("Artist: %s\n", foundMusic->artist);
        printf("Genre: %s\n", foundMusic->genre);
        printf("Year: %d\n", foundMusic->year);
    } else {
        printf("Music not found.\n");
    }

    // Delete music from the library
    deleteMusic(head, "The Beatles - Let Us Be Together");

    // Search for music after deletion
    foundMusic = searchMusic(head, "The Beatles - Let Us Be Together");

    // If music is found, print its details
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