//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Music Library Management System structure
typedef struct MusicLibraryManagementSystem {
    char title[255];
    char artist[255];
    char genre[255];
    int year;
    struct MusicLibraryManagementSystem* next;
} MusicLibraryManagementSystem;

// Function to insert a new music record into the library
void insertMusicRecord(MusicLibraryManagementSystem** head) {
    // Allocate memory for the new music record
    MusicLibraryManagementSystem* newMusicRecord = (MusicLibraryManagementSystem*)malloc(sizeof(MusicLibraryManagementSystem));

    // Get the music record's details from the user
    printf("Enter the title: ");
    scanf("%s", newMusicRecord->title);

    printf("Enter the artist: ");
    scanf("%s", newMusicRecord->artist);

    printf("Enter the genre: ");
    scanf("%s", newMusicRecord->genre);

    printf("Enter the year: ");
    scanf("%d", &newMusicRecord->year);

    // Insert the new music record into the library
    if (*head == NULL) {
        *head = newMusicRecord;
    } else {
        (*head)->next = newMusicRecord;
    }

    // Print a confirmation message
    printf("Music record inserted successfully.\n");
}

// Function to search for a music record in the library
void searchMusicRecord(MusicLibraryManagementSystem* head) {
    // Get the music record's details from the user
    printf("Enter the title: ");
    char title[255];
    scanf("%s", title);

    printf("Enter the artist: ");
    char artist[255];
    scanf("%s", artist);

    // Search for the music record
    MusicLibraryManagementSystem* currentMusicRecord = head;
    while (currentMusicRecord) {
        if (strcmp(currentMusicRecord->title, title) == 0 && strcmp(currentMusicRecord->artist, artist) == 0) {
            // Print the music record's details
            printf("Title: %s\n", currentMusicRecord->title);
            printf("Artist: %s\n", currentMusicRecord->artist);
            printf("Genre: %s\n", currentMusicRecord->genre);
            printf("Year: %d\n", currentMusicRecord->year);
            break;
        }
        currentMusicRecord = currentMusicRecord->next;
    }

    // If the music record is not found, print an error message
    if (currentMusicRecord == NULL) {
        printf("Music record not found.\n");
    }
}

// Function to delete a music record from the library
void deleteMusicRecord(MusicLibraryManagementSystem* head) {
    // Get the music record's details from the user
    printf("Enter the title: ");
    char title[255];
    scanf("%s", title);

    printf("Enter the artist: ");
    char artist[255];
    scanf("%s", artist);

    // Search for the music record
    MusicLibraryManagementSystem* currentMusicRecord = head;
    MusicLibraryManagementSystem* previousMusicRecord = NULL;
    while (currentMusicRecord) {
        if (strcmp(currentMusicRecord->title, title) == 0 && strcmp(currentMusicRecord->artist, artist) == 0) {
            // Delete the music record
            if (previousMusicRecord) {
                previousMusicRecord->next = currentMusicRecord->next;
            } else {
                head = currentMusicRecord->next;
            }
            free(currentMusicRecord);
            break;
        }
        previousMusicRecord = currentMusicRecord;
        currentMusicRecord = currentMusicRecord->next;
    }

    // If the music record is not found, print an error message
    if (currentMusicRecord == NULL) {
        printf("Music record not found.\n");
    }
}

int main() {
    // Create a linked list to store the music records
    MusicLibraryManagementSystem* head = NULL;

    // Insert some music records into the library
    insertMusicRecord(&head);
    insertMusicRecord(&head);
    insertMusicRecord(&head);

    // Search for a music record in the library
    searchMusicRecord(head);

    // Delete a music record from the library
    deleteMusicRecord(head);

    return 0;
}