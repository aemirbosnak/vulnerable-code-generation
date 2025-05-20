//FormAI DATASET v1.0 Category: Music Library Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing information about a song
typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
} Song;

// Function to display the details of a song
void displaySong(Song *song) {
    printf("------------------------------------\n");
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Year: %d\n", song->year);
    printf("Duration: %d seconds\n", song->duration);
    printf("------------------------------------\n");
}

// Function to add a song to the music library
void addSong(Song **library, int *numSongs) {
    printf("Enter the details of the song:\n");
    Song *newSong = (Song*) malloc(sizeof(Song));
    printf("Title: ");
    fgets(newSong->title, 50, stdin);
    newSong->title[strcspn(newSong->title, "\n")] = 0;
    printf("Artist: ");
    fgets(newSong->artist, 50, stdin);
    newSong->artist[strcspn(newSong->artist, "\n")] = 0;
    printf("Album: ");
    fgets(newSong->album, 50, stdin);
    newSong->album[strcspn(newSong->album, "\n")] = 0;
    printf("Year: ");
    scanf("%d", &newSong->year);
    printf("Duration (in seconds): ");
    scanf("%d", &newSong->duration);
    getchar(); // Consume the newline character left in the input buffer
    library[*numSongs] = newSong;
    *numSongs += 1;
    printf("Song added successfully!\n");
}

// Function to search for a song in the music library
void searchSong(Song **library, int numSongs) {
    char searchTitle[50];
    printf("Enter the title of the song to be searched: ");
    fgets(searchTitle, 50, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < numSongs; i++) {
        if (strcmp(searchTitle, library[i]->title) == 0) {
            displaySong(library[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Song not found in the library.\n");
    }
}

// Function to remove a song from the music library
void removeSong(Song **library, int *numSongs) {
    char removeTitle[50];
    printf("Enter the title of the song to be removed: ");
    fgets(removeTitle, 50, stdin);
    removeTitle[strcspn(removeTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < *numSongs; i++) {
        if (strcmp(removeTitle, library[i]->title) == 0) {
            free(library[i]); // Free the memory allocated to the song
            for (int j = i; j < *numSongs - 1; j++) {
                library[j] = library[j+1]; // Shift all songs after the removed song by one index
            }
            *numSongs -= 1;
            printf("Song removed successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Song not found in the library.\n");
    }
}

int main() {
    int option, numSongs = 0;
    Song **library = (Song**) malloc(100 * sizeof(Song*)); // Allocate memory for 100 songs

    printf("Welcome to the Music Library Management System!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a song\n");
        printf("2. Search for a song\n");
        printf("3. Remove a song\n");
        printf("4. Exit\n");

        scanf("%d", &option);
        getchar(); // Consume the newline character left in the input buffer

        switch (option) {
            case 1:
                addSong(library, &numSongs);
                break;
            case 2:
                searchSong(library, numSongs);
                break;
            case 3:
                removeSong(library, &numSongs);
                break;
            case 4:
                printf("Thank you for using the Music Library Management System!\n");
                exit(0);
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    }

    return 0;
}