//FormAI DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
/* This program is a Music Library Management System. It allows users to add, delete, and view songs in their library. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store song data
typedef struct {
    char title[50];
    char artist[50];
    int year;
} Song;

// Function to add song to library
void add_song(Song* library[], int* song_count) {
    // Allocate memory for new song
    Song* new_song = (Song*) malloc(sizeof(Song));

    // Get song title
    printf("\nEnter the title of the song: ");
    fflush(stdin);
    fgets(new_song->title, 50, stdin);
    new_song->title[strcspn(new_song->title, "\r\n")] = 0; // Remove newline character

    // Get artist name
    printf("Enter the artist of the song: ");
    fflush(stdin);
    fgets(new_song->artist, 50, stdin);
    new_song->artist[strcspn(new_song->artist, "\r\n")] = 0; // Remove newline character

    // Get year of song
    printf("Enter the year the song was released: ");
    scanf("%d", &new_song->year);

    // Add song to library
    library[*song_count] = new_song;
    (*song_count)++;
}

// Function to delete song from library
void delete_song(Song* library[], int* song_count) {
    // Get index of song to delete
    int index;
    printf("\nEnter the index of the song you want to delete: ");
    scanf("%d", &index);

    // Check if index is valid
    if (index >= 0 && index < *song_count) {
        // Free memory allocated for song
        free(library[index]);

        // Shift remaining songs to fill gap
        for (int i = index; i < *song_count - 1; i++) {
            library[i] = library[i+1];
        }
        
        // Decrement song count
        (*song_count)--;
        printf("Song deleted successfully!\n");
    } else {
        printf("Invalid index!\n");
    }
}

// Function to view all songs in library
void view_songs(Song* library[], int song_count) {
    if (song_count > 0) {
        printf("\n---------------\n");
        for (int i = 0; i < song_count; i++) {
            printf("Song %d:\n", i+1);
            printf("  Title: %s\n", library[i]->title);
            printf("  Artist: %s\n", library[i]->artist);
            printf("  Year: %d\n", library[i]->year);
            printf("---------------\n");
        }
    } else {
        printf("\nNo songs found!\n");
    }
}

int main() {
    Song* library[100]; // Array to store songs
    int song_count = 0; // Number of songs in library
    int choice; // User choice for menu

    printf("Welcome to the Music Library Management System!\n");

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. View Songs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add song
                add_song(library, &song_count);
                break;

            case 2: // Delete song
                delete_song(library, &song_count);
                break;

            case 3: // View songs
                view_songs(library, song_count);
                break;

            case 4: // Exit
                printf("\nThank you for using the Music Library Management System!\n");
                break;

            default: // Invalid choice
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}