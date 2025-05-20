//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of songs in the library
#define MAX_SONGS 100

// Define the song structure
typedef struct Song {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Song* next;
} Song;

// Create a linked list of songs
Song* song_list = NULL;

// Function to add a song to the library
void add_song() {
    // Allocate memory for the new song
    Song* new_song = (Song*)malloc(sizeof(Song));

    // Get the song's title, artist, genre, and year
    printf("Enter the song title: ");
    scanf("%s", new_song->title);

    printf("Enter the artist's name: ");
    scanf("%s", new_song->artist);

    printf("Enter the genre of the song: ");
    scanf("%s", new_song->genre);

    printf("Enter the year of the song: ");
    scanf("%d", &new_song->year);

    // Set the new song's next pointer to NULL
    new_song->next = NULL;

    // If the song list is empty, make the new song the first song in the list
    if (song_list == NULL) {
        song_list = new_song;
    } else {
        // Traverse the song list until the last song is reached
        Song* current_song = song_list;
        while (current_song->next != NULL) {
            current_song = current_song->next;
        }

        // Add the new song to the end of the list
        current_song->next = new_song;
    }
}

// Function to search for a song in the library
void search_song() {
    // Get the song title
    printf("Enter the song title: ");
    char search_title[50];
    scanf("%s", search_title);

    // Search for the song
    Song* current_song = song_list;
    while (current_song) {
        if (strcmp(current_song->title, search_title) == 0) {
            // Print the song's information
            printf("Title: %s\n", current_song->title);
            printf("Artist: %s\n", current_song->artist);
            printf("Genre: %s\n", current_song->genre);
            printf("Year: %d\n", current_song->year);
            break;
        }
        current_song = current_song->next;
    }

    // If the song is not found, print an error message
    if (current_song == NULL) {
        printf("Song not found.\n");
    }
}

// Function to delete a song from the library
void delete_song() {
    // Get the song title
    printf("Enter the song title: ");
    char delete_title[50];
    scanf("%s", delete_title);

    // Search for the song
    Song* current_song = song_list;
    Song* previous_song = NULL;
    while (current_song) {
        if (strcmp(current_song->title, delete_title) == 0) {
            // If the song is the first song in the list, update the song list
            if (previous_song == NULL) {
                song_list = current_song->next;
            } else {
                // Traverse the song list until the song is found
                previous_song->next = current_song->next;
            }

            // Free the memory of the song
            free(current_song);
            break;
        }
        previous_song = current_song;
        current_song = current_song->next;
    }

    // If the song is not found, print an error message
    if (current_song == NULL) {
        printf("Song not found.\n");
    }
}

// Main function
int main() {
    // Menu loop
    int menu_choice;
    while (1) {
        // Print the menu options
        printf("1. Add song\n");
        printf("2. Search song\n");
        printf("3. Delete song\n");
        printf("4. Exit\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        // Switch case to handle the user's choice
        switch (menu_choice) {
            case 1:
                add_song();
                break;
            case 2:
                search_song();
                break;
            case 3:
                delete_song();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}