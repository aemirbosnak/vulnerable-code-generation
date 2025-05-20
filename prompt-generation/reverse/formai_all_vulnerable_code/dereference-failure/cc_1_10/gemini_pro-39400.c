//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store music library data
typedef struct music {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} Music;

// Function to add a new music to the library
void add_music(Music **library, int *size) {
    // Allocate memory for the new music
    *library = realloc(*library, (*size + 1) * sizeof(Music));

    // Get the music details from the user
    printf("Enter the title: ");
    scanf(" %[^\n]%*c", (*library)[*size].title);

    printf("Enter the artist: ");
    scanf(" %[^\n]%*c", (*library)[*size].artist);

    printf("Enter the album: ");
    scanf(" %[^\n]%*c", (*library)[*size].album);

    printf("Enter the year: ");
    scanf("%d", &(*library)[*size].year);

    // Increment the size of the library
    (*size)++;
}

// Function to search for a music in the library
int search_music(Music *library, int size, char *title) {
    // Loop through the library and search for the music
    for (int i = 0; i < size; i++) {
        if (strcmp(library[i].title, title) == 0) {
            // Return the index of the music
            return i;
        }
    }

    // Return -1 if the music is not found
    return -1;
}

// Function to print the music library
void print_library(Music *library, int size) {
    // Loop through the library and print the music details
    for (int i = 0; i < size; i++) {
        printf("%s - %s - %s - %d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}

// Main function
int main() {
    // Initialize the music library
    Music *library = NULL;
    int size = 0;

    // Add some music to the library
    add_music(&library, &size);
    add_music(&library, &size);
    add_music(&library, &size);

    // Print the music library
    print_library(library, size);

    // Search for a music in the library
    char title[50];
    printf("Enter the title of the music you want to search for: ");
    scanf(" %[^\n]%*c", title);

    int index = search_music(library, size, title);
    if (index == -1) {
        printf("Music not found.\n");
    } else {
        printf("Music found:\n");
        printf("%s - %s - %s - %d\n", library[index].title, library[index].artist, library[index].album, library[index].year);
    }

    // Free the memory allocated for the library
    free(library);

    return 0;
}