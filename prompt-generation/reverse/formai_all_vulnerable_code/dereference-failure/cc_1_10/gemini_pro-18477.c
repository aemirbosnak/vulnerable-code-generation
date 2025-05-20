//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: excited
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
    music_library *library = malloc(sizeof(music_library));
    library->name = strdup(name);
    library->artist = strdup(artist);
    library->album = strdup(album);
    library->year = year;
    library->duration = duration;
    return library;
}

// Destroy a music library
void destroy_music_library(music_library *library) {
    free(library->name);
    free(library->artist);
    free(library->album);
    free(library);
}

// Print a music library
void print_music_library(music_library *library) {
    printf("Name: %s\n", library->name);
    printf("Artist: %s\n", library->artist);
    printf("Album: %s\n", library->album);
    printf("Year: %d\n", library->year);
    printf("Duration: %d\n", library->duration);
}

// Compare two music libraries
int compare_music_libraries(music_library *library1, music_library *library2) {
    return strcmp(library1->name, library2->name);
}

// Sort a music library
void sort_music_library(music_library **libraries, int num_libraries) {
    qsort(libraries, num_libraries, sizeof(music_library *), compare_music_libraries);
}

// Find a music library by name
music_library *find_music_library_by_name(music_library **libraries, int num_libraries, char *name) {
    int i;
    for (i = 0; i < num_libraries; i++) {
        if (strcmp(libraries[i]->name, name) == 0) {
            return libraries[i];
        }
    }
    return NULL;
}

// Main function
int main() {
    // Create a music library
    music_library *library1 = create_music_library("Thriller", "Michael Jackson", "Thriller", 1982, 40);

    // Print the music library
    print_music_library(library1);

    // Destroy the music library
    destroy_music_library(library1);

    return 0;
}