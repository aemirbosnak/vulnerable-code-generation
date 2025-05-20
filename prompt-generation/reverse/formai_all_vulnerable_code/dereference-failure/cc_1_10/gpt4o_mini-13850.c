//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

typedef struct Song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    struct Song* next;
} Song;

Song* head = NULL;

void addSong(char* title, char* artist) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->next = head;
    head = newSong;
    printf("Song added: %s by %s\n", title, artist);
}

void displaySongs() {
    if (head == NULL) {
        printf("No songs in the library.\n");
        return;
    }
    printf("\nMusic Library:\n");
    Song* current = head;
    while (current != NULL) {
        printf("Title: %s | Artist: %s\n", current->title, current->artist);
        current = current->next;
    }
}

void deleteSong(char* title) {
    Song* current = head;
    Song* previous = NULL;
    
    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Song not found: %s\n", title);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Delete the head
    } else {
        previous->next = current->next; // Bypass the song
    }

    free(current);
    printf("Song deleted: %s\n", title);
}

void freeLibrary() {
    Song* current = head;
    Song* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    head = NULL;
}

int main() {
    int choice;
    char title[MAX_TITLE_LENGTH], artist[MAX_ARTIST_LENGTH];

    do {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Song\n");
        printf("2. Display Songs\n");
        printf("3. Delete Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the input buffer

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                printf("Enter artist name: ");
                fgets(artist, MAX_ARTIST_LENGTH, stdin);
                artist[strcspn(artist, "\n")] = 0; // Remove newline
                addSong(title, artist);
                break;

            case 2:
                displaySongs();
                break;

            case 3:
                printf("Enter song title to delete: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                deleteSong(title);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    freeLibrary();
    return 0;
}