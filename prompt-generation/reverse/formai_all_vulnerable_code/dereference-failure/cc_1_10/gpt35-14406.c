//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for all string variables
#define MAX_LENGTH 50

// Define a struct to represent a Song
typedef struct{
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    int year;
} Song;

// Define a struct to represent a Playlist
typedef struct {
    char name[MAX_LENGTH];
    Song* songs; // Pointer to dynamically allocated Song array
    int num_songs;
} Playlist;

// Function to add a Song to a Playlist
void addSong(Playlist* playlist) {
    Song song;
    printf("\nAdding a new Song to Playlist %s\n", playlist->name);
    printf("Enter Song title: ");
    fgets(song.title, MAX_LENGTH, stdin);
    printf("Enter Song artist: ");
    fgets(song.artist, MAX_LENGTH, stdin);
    printf("Enter Song year (yyyy): ");
    scanf("%d", &song.year);
    getchar(); // Consume newline character

    // Increase the size of the songs array by 1
    playlist->num_songs++;
    playlist->songs = realloc(playlist->songs, playlist->num_songs * sizeof(Song));

    // Add the new Song to the end of the songs array
    playlist->songs[playlist->num_songs-1] = song;

    printf("Song added successfully!\n");
}

// Function to display all Songs in a Playlist
void displaySongs(Playlist* playlist) {
    printf("\nDisplaying all Songs in Playlist %s\n\n", playlist->name);
    for (int i = 0; i < playlist->num_songs; i++) {
        printf("Title: %s", playlist->songs[i].title);
        printf("Artist: %s", playlist->songs[i].artist);
        printf("Year: %d\n", playlist->songs[i].year);
    }
}

int main() {
    Playlist playlist;
    playlist.num_songs = 0;
    playlist.songs = NULL; // Initialize songs array to NULL

    printf("Welcome to the Music Library Management System!\n");
    printf("Please enter the name of your new Playlist: ");
    fgets(playlist.name, MAX_LENGTH, stdin);

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a Song\n");
        printf("2. Display all Songs\n");
        printf("3. Exit Program\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch(choice) {
            case 1:
                addSong(&playlist);
                break;
            case 2:
                displaySongs(&playlist);
                break;
            case 3:
                // Free dynamically allocated memory before exiting program
                for (int i = 0; i < playlist.num_songs; i++) {
                    free(playlist.songs[i].title);
                    free(playlist.songs[i].artist);
                }
                free(playlist.songs);
                printf("\nThank you for using the Music Library Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    }
    return 0;
}