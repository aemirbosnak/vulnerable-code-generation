//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music library information
struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
};

// Function to insert a new music record into the library
void insertMusic(struct MusicLibrary** head) {
    // Allocate memory for the new music record
    struct MusicLibrary* newMusic = (struct MusicLibrary*)malloc(sizeof(struct MusicLibrary));

    // Get the music record information from the user
    printf("Enter the title: ");
    scanf("%s", newMusic->title);

    printf("Enter the artist: ");
    scanf("%s", newMusic->artist);

    printf("Enter the genre: ");
    scanf("%s", newMusic->genre);

    printf("Enter the year: ");
    scanf("%d", &newMusic->year);

    // Link the new music record to the head of the library
    if (*head == NULL) {
        *head = newMusic;
    } else {
        (*head)->next = newMusic;
    }

    // Print a confirmation message
    printf("Music record inserted successfully!\n");
}

// Function to search for a music record in the library
void searchMusic(struct MusicLibrary* head) {
    // Get the music record information from the user
    char title[50];
    printf("Enter the title: ");
    scanf("%s", title);

    // Search for the music record
    struct MusicLibrary* current = head;
    while (current) {
        if (strcmp(current->title, title) == 0) {
            // Print the music record information
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n", current->artist);
            printf("Genre: %s\n", current->genre);
            printf("Year: %d\n", current->year);
            break;
        }
        current = current->next;
    }

    // If the music record is not found, print an error message
    if (current == NULL) {
        printf("Music record not found.\n");
    }
}

// Function to delete a music record from the library
void deleteMusic(struct MusicLibrary* head) {
    // Get the music record information from the user
    char title[50];
    printf("Enter the title: ");
    scanf("%s", title);

    // Search for the music record
    struct MusicLibrary* current = head;
    struct MusicLibrary* previous = NULL;
    while (current) {
        if (strcmp(current->title, title) == 0) {
            // If the music record is the first record in the library, update the head of the library
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            // Free the memory occupied by the music record
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }

    // If the music record is not found, print an error message
    if (current == NULL) {
        printf("Music record not found.\n");
    }
}

int main() {
    // Create a linked list to store the music library information
    struct MusicLibrary* head = NULL;

    // Insert some music records into the library
    insertMusic(&head);
    insertMusic(&head);
    insertMusic(&head);

    // Search for a music record in the library
    searchMusic(head);

    // Delete a music record from the library
    deleteMusic(head);

    return 0;
}