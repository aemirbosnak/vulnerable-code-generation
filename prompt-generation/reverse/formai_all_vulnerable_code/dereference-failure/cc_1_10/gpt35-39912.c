//FormAI DATASET v1.0 Category: Music Library Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing music information
typedef struct {
    char *title;
    char *artist;
    int year;
    int duration;
} Music;

// Function to print all music in the library
void printLibrary(Music *library, int size) {
    printf("Library:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - %s (%d) %d:%02d\n", i+1, library[i].title, library[i].artist, library[i].year, library[i].duration / 60, library[i].duration % 60);
    }
    printf("\n");
}

// Function to add music to the library
void addMusic(Music *library, int *size) {
    char title[100];
    char artist[100];
    int year, duration;

    printf("Enter music title: ");
    scanf("%99s", title);

    printf("Enter artist name: ");
    scanf("%99s", artist);

    printf("Enter year: ");
    scanf("%d", &year);

    printf("Enter duration (in seconds): ");
    scanf("%d", &duration);

    // Allocate memory for new music and add to library
    library[*size].title = malloc(strlen(title) + 1);
    strcpy(library[*size].title, title);
    library[*size].artist = malloc(strlen(artist) + 1);
    strcpy(library[*size].artist, artist);
    library[*size].year = year;
    library[*size].duration = duration;

    *size += 1;
    printf("\nMusic added successfully!\n\n");
}

// Function to remove a specific music from the library
void removeMusic(Music *library, int *size) {
    int index;

    printLibrary(library, *size);
    printf("Enter the index of the music you want to remove: ");
    scanf("%d", &index);

    if (index > 0 && index <= *size) {
        // Free memory for title and artist before removing music
        free(library[index-1].title);
        free(library[index-1].artist);

        // Shift all music after removed music to fill the gap
        for (int i = index-1; i < *size - 1; i++) {
            library[i] = library[i+1];
        }
        
        *size -= 1;
        printf("\nMusic removed successfully!\n\n");
    } else {
        printf("\nInvalid index.\n\n");
    }
}

int main() {
    Music library[50]; // Maximum size of library is 50
    int size = 0;
    int choice;

    printf("Welcome to the Music Library Management System!\n\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. View library\n");
        printf("2. Add music\n");
        printf("3. Remove music\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printLibrary(library, size);
                break;
            case 2:
                if (size < 50) {
                    addMusic(library, &size);
                } else {
                    printf("\nMaximum library capacity reached. Cannot add more music.\n\n");
                }
                break;
            case 3:
                if (size > 0) {
                    removeMusic(library, &size);
                } else {
                    printf("\nLibrary is empty. Cannot remove music.\n\n");
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}