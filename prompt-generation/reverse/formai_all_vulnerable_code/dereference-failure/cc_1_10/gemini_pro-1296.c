//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library item
typedef struct music_item {
    char *title;
    char *artist;
    char *album;
    int year_released;
    int track_number;
} music_item;

// Create a new music library item
music_item *create_music_item(char *title, char *artist, char *album, int year_released, int track_number) {
    music_item *item = malloc(sizeof(music_item));
    item->title = strdup(title);
    item->artist = strdup(artist);
    item->album = strdup(album);
    item->year_released = year_released;
    item->track_number = track_number;
    return item;
}

// Free the memory allocated for a music library item
void free_music_item(music_item *item) {
    free(item->title);
    free(item->artist);
    free(item->album);
    free(item);
}

// Print the details of a music library item
void print_music_item(music_item *item) {
    printf("Title: %s\n", item->title);
    printf("Artist: %s\n", item->artist);
    printf("Album: %s\n", item->album);
    printf("Year released: %d\n", item->year_released);
    printf("Track number: %d\n", item->track_number);
}

// Create a new music library
music_item **create_music_library(int size) {
    music_item **library = malloc(sizeof(music_item *) * size);
    for (int i = 0; i < size; i++) {
        library[i] = NULL;
    }
    return library;
}

// Free the memory allocated for a music library
void free_music_library(music_item **library, int size) {
    for (int i = 0; i < size; i++) {
        if (library[i] != NULL) {
            free_music_item(library[i]);
        }
    }
    free(library);
}

// Add a new music library item to a music library
void add_music_item_to_library(music_item **library, int size, music_item *item) {
    for (int i = 0; i < size; i++) {
        if (library[i] == NULL) {
            library[i] = item;
            return;
        }
    }
    printf("Error: The music library is full.\n");
}

// Remove a music library item from a music library
void remove_music_item_from_library(music_item **library, int size, music_item *item) {
    for (int i = 0; i < size; i++) {
        if (library[i] == item) {
            free_music_item(library[i]);
            library[i] = NULL;
            return;
        }
    }
    printf("Error: The music library does not contain the specified item.\n");
}

// Print the details of all music library items in a music library
void print_music_library(music_item **library, int size) {
    for (int i = 0; i < size; i++) {
        if (library[i] != NULL) {
            print_music_item(library[i]);
            printf("\n");
        }
    }
}

// Main function
int main() {
    // Create a new music library
    music_item **library = create_music_library(10);

    // Add some music library items to the library
    music_item *item1 = create_music_item("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1);
    add_music_item_to_library(library, 10, item1);
    music_item *item2 = create_music_item("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4);
    add_music_item_to_library(library, 10, item2);
    music_item *item3 = create_music_item("Hotel California", "Eagles", "Hotel California", 1976, 3);
    add_music_item_to_library(library, 10, item3);

    // Print the details of all music library items in the library
    print_music_library(library, 10);

    // Remove a music library item from the library
    remove_music_item_from_library(library, 10, item2);

    // Print the details of all music library items in the library
    print_music_library(library, 10);

    // Free the memory allocated for the music library
    free_music_library(library, 10);

    return 0;
}