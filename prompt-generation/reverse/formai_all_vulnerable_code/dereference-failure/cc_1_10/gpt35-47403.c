//FormAI DATASET v1.0 Category: Music Library Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Struct to hold information about a song
typedef struct {
    char title[MAX];
    char artist[MAX];
    char album[MAX];
    int year;
} Song;

// Struct to hold information about a music library
typedef struct {
    Song songs[MAX];
    int count;
} Library;

// Function to add a song to the library
void addSong(Library *library, Song song) {
    if (library->count >= MAX) {
        printf("Library is full.\n");
        return;
    }
    
    library->songs[library->count] = song;
    library->count++;
    printf("Song added succesfully.\n");
}

// Function to remove a song from the library
void removeSong(Library *library, char *title) {
    int found = 0;
    
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            for (int j = i; j < library->count - 1; j++) {
                library->songs[j] = library->songs[j+1];
            }
            library->count--;
            found = 1;
            printf("Song removed succesfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Song not found in library.\n");
    }
}

// Function to search for a song in the library
void searchSong(Library *library, char *title) {
    int found = 0;
    
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            printf("Title: %s\n", library->songs[i].title);
            printf("Artist: %s\n", library->songs[i].artist);
            printf("Album: %s\n", library->songs[i].album);
            printf("Year: %d\n", library->songs[i].year);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Song not found in library.\n");
    }
}

int main() {
    Library myLibrary;
    myLibrary.count = 0;
    
    int choice;
    
    do {
        // Print menu
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Search Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Add Song
                printf("Enter song title: ");
                scanf("%s", &myLibrary.songs[myLibrary.count].title);
                
                printf("Enter artist name: ");
                scanf("%s", &myLibrary.songs[myLibrary.count].artist);
                
                printf("Enter album name: ");
                scanf("%s", &myLibrary.songs[myLibrary.count].album);
                
                printf("Enter year of release: ");
                scanf("%d", &myLibrary.songs[myLibrary.count].year);
                
                addSong(&myLibrary, myLibrary.songs[myLibrary.count]);
                break;
                
            case 2: // Remove Song
                printf("Enter song title: ");
                char title[MAX];
                scanf("%s", &title);
                removeSong(&myLibrary, title);
                break;
                
            case 3: // Search Song
                printf("Enter song title: ");
                char search_title[MAX];
                scanf("%s", &search_title);
                searchSong(&myLibrary, search_title);
                break;
                
            case 4:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice, please try again.\n");
        }
        
    } while (choice != 4);
    
    return 0;
}