//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold music track details
typedef struct Track {
    char title[100];
    char artist[100];
    struct Track* next; // Pointer to the next track
} Track;

// Function to create a new track
Track* createTrack(char* title, char* artist) {
    Track* newTrack = (Track*)malloc(sizeof(Track));
    strcpy(newTrack->title, title);
    strcpy(newTrack->artist, artist);
    newTrack->next = NULL;
    return newTrack;
}

// Function to add a track to the library
void addTrack(Track** head, char* title, char* artist) {
    Track* newTrack = createTrack(title, artist);
    newTrack->next = *head; // Point to the old first track
    *head = newTrack; // Update the head to the new track
    printf("Track added: %s by %s\n", title, artist);
}

// Function to display all tracks in the library
void displayTracks(Track* head) {
    Track* temp = head;
    if(temp == NULL) {
        printf("No tracks found in the library.\n");
        return;
    }
    printf("Music Library:\n");
    while (temp != NULL) {
        printf("Title: %s | Artist: %s\n", temp->title, temp->artist);
        temp = temp->next;
    }
}

// Function to find a track by its title
void findTrack(Track* head, char* title) {
    Track* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            printf("Track found: %s by %s\n", temp->title, temp->artist);
            return;
        }
        temp = temp->next;
    }
    printf("Track not found: %s\n", title);
}

// Function to free the memory allocated for the tracks
void freeLibrary(Track* head) {
    Track* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to provide a menu and interact with the user
int main() {
    Track* library = NULL;
    int choice;
    char title[100], artist[100];

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Track\n");
        printf("2. Display All Tracks\n");
        printf("3. Find Track by Title\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer

        switch (choice) {
            case 1:
                printf("Enter track title: ");
                fgets(title, sizeof(title), stdin);
                strtok(title, "\n"); // Remove newline character

                printf("Enter track artist: ");
                fgets(artist, sizeof(artist), stdin);
                strtok(artist, "\n"); // Remove newline character

                addTrack(&library, title, artist);
                break;

            case 2:
                displayTracks(library);
                break;

            case 3:
                printf("Enter track title to find: ");
                fgets(title, sizeof(title), stdin);
                strtok(title, "\n"); // Remove newline character
                findTrack(library, title);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Clean up and free the memory
    freeLibrary(library);
    return 0;
}