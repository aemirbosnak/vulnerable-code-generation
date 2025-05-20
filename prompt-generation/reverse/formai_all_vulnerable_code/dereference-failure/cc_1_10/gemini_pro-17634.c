//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
typedef struct music_library {
    char *name;
    char *artist;
    char *album;
    int year;
    int duration;
} music_library;

// Create a new music library
music_library *create_music_library(char *name, char *artist, char *album, int year, int duration) {
    music_library *new_library = malloc(sizeof(music_library));
    new_library->name = strdup(name);
    new_library->artist = strdup(artist);
    new_library->album = strdup(album);
    new_library->year = year;
    new_library->duration = duration;
    return new_library;
}

// Free the memory allocated for a music library
void free_music_library(music_library *library) {
    free(library->name);
    free(library->artist);
    free(library->album);
    free(library);
}

// Print the details of a music library
void print_music_library(music_library *library) {
    printf("Name: %s\n", library->name);
    printf("Artist: %s\n", library->artist);
    printf("Album: %s\n", library->album);
    printf("Year: %d\n", library->year);
    printf("Duration: %d\n", library->duration);
}

// Compare two music libraries by name
int compare_music_libraries(music_library *library1, music_library *library2) {
    return strcmp(library1->name, library2->name);
}

// Sort an array of music libraries by name
void sort_music_libraries(music_library **libraries, int num_libraries) {
    qsort(libraries, num_libraries, sizeof(music_library *), (int (*)(const void *, const void *))compare_music_libraries);
}

// Search for a music library by name in an array of music libraries
music_library *search_music_library(music_library **libraries, int num_libraries, char *name) {
    int left = 0;
    int right = num_libraries - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (strcmp(libraries[mid]->name, name) == 0) {
            return libraries[mid];
        } else if (strcmp(libraries[mid]->name, name) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return NULL;
}

// Main function
int main() {
    // Create an array of music libraries
    music_library *libraries[] = {
        create_music_library("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 355),
        create_music_library("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480),
        create_music_library("Hotel California", "Eagles", "Hotel California", 1976, 395),
        create_music_library("Imagine", "John Lennon", "Imagine", 1971, 225),
        create_music_library("Thriller", "Michael Jackson", "Thriller", 1982, 420)
    };

    // Sort the array of music libraries by name
    sort_music_libraries(libraries, 5);

    // Search for a music library by name
    music_library *library = search_music_library(libraries, 5, "Stairway to Heaven");

    // Print the details of the music library
    if (library != NULL) {
        print_music_library(library);
    } else {
        printf("Music library not found.\n");
    }

    // Free the memory allocated for the music libraries
    for (int i = 0; i < 5; i++) {
        free_music_library(libraries[i]);
    }

    return 0;
}