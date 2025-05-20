//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music track
typedef struct Track {
    char *title;
    char *artist;
    char *album;
    int year;
    int duration;
} Track;

// Create a dynamic array of tracks
Track *library;
int num_tracks = 0;

// Add a new track to the library
void add_track(char *title, char *artist, char *album, int year, int duration) {
    library = realloc(library, (num_tracks + 1) * sizeof(Track));
    library[num_tracks].title = strdup(title);
    library[num_tracks].artist = strdup(artist);
    library[num_tracks].album = strdup(album);
    library[num_tracks].year = year;
    library[num_tracks].duration = duration;
    num_tracks++;
}

// Print the details of a single track
void print_track(int index) {
    printf("Title: %s\n", library[index].title);
    printf("Artist: %s\n", library[index].artist);
    printf("Album: %s\n", library[index].album);
    printf("Year: %d\n", library[index].year);
    printf("Duration: %d seconds\n\n", library[index].duration);
}

// Print the details of all tracks in the library
void print_library() {
    for (int i = 0; i < num_tracks; i++) {
        print_track(i);
    }
}

// Search the library for a track by title
int search_by_title(char *title) {
    for (int i = 0; i < num_tracks; i++) {
        if (strcmp(library[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}

// Search the library for a track by artist
int search_by_artist(char *artist) {
    for (int i = 0; i < num_tracks; i++) {
        if (strcmp(library[i].artist, artist) == 0) {
            return i;
        }
    }
    return -1;
}

// Search the library for a track by album
int search_by_album(char *album) {
    for (int i = 0; i < num_tracks; i++) {
        if (strcmp(library[i].album, album) == 0) {
            return i;
        }
    }
    return -1;
}

// Delete a track from the library
void delete_track(int index) {
    free(library[index].title);
    free(library[index].artist);
    free(library[index].album);
    for (int i = index; i < num_tracks - 1; i++) {
        library[i] = library[i + 1];
    }
    num_tracks--;
}

// Main function
int main() {
    // Add some awesome tracks to the library
    add_track("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 358);
    add_track("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480);
    add_track("Hotel California", "Eagles", "Hotel California", 1976, 382);
    add_track("Thriller", "Michael Jackson", "Thriller", 1982, 320);
    add_track("Imagine", "John Lennon", "Imagine", 1971, 180);

    // Print the library
    printf("Get ready for the music of a lifetime!\n");
    print_library();

    // Search the library for a track by title
    int index = search_by_title("Stairway to Heaven");
    if (index >= 0) {
        printf("Found it! Here's the info:\n");
        print_track(index);
    } else {
        printf("Sorry, that track doesn't exist in the library.\n");
    }

    // Delete a track from the library
    delete_track(2);

    // Print the library again
    printf("\nHere's the updated library:\n");
    print_library();

    return 0;
}