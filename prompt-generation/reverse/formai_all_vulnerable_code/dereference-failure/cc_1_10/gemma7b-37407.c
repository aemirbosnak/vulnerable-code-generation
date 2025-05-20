//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music library information
typedef struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a new music item into the library
void insertMusicItem(MusicLibrary* head) {
    MusicLibrary* newNode = malloc(sizeof(MusicLibrary));
    printf("Enter the title of the music item: ");
    scanf("%s", newNode->title);
    printf("Enter the artist of the music item: ");
    scanf("%s", newNode->artist);
    printf("Enter the genre of the music item: ");
    scanf("%s", newNode->genre);
    printf("Enter the year of the music item: ");
    scanf("%d", &newNode->year);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Function to search for a music item in the library
MusicLibrary* searchMusicItem(MusicLibrary* head, char* title) {
    MusicLibrary* current = head;

    while (current) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to delete a music item from the library
void deleteMusicItem(MusicLibrary* head, char* title) {
    MusicLibrary* previous = NULL;
    MusicLibrary* current = head;

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

// Function to display the music library
void displayMusicLibrary(MusicLibrary* head) {
    MusicLibrary* current = head;

    printf("Here is your music library:\n");

    while (current) {
        printf("Title: %s\n", current->title);
        printf("Artist: %s\n", current->artist);
        printf("Genre: %s\n", current->genre);
        printf("Year: %d\n", current->year);
        printf("\n");
        current = current->next;
    }
}

int main() {
    MusicLibrary* head = NULL;

    // Insert some music items into the library
    insertMusicItem(head);
    insertMusicItem(head);
    insertMusicItem(head);

    // Display the music library
    displayMusicLibrary(head);

    // Search for a music item
    MusicLibrary* item = searchMusicItem(head, "Song 2");

    // If the item is found, display its information
    if (item) {
        printf("Title: %s\n", item->title);
        printf("Artist: %s\n", item->artist);
        printf("Genre: %s\n", item->genre);
        printf("Year: %d\n", item->year);
    } else {
        printf("Item not found.\n");
    }

    // Delete a music item
    deleteMusicItem(head, "Song 1");

    // Display the music library after deletion
    displayMusicLibrary(head);

    return 0;
}