//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library entry
typedef struct music_entry {
    char *title;
    char *artist;
    char *album;
    int year;
    int track_number;
} music_entry;

// Define the maximum number of entries in the library
#define MAX_ENTRIES 100

// Create an array of music library entries
music_entry library[MAX_ENTRIES];

// Initialize the library with some sample data
void initialize_library() {
    strcpy(library[0].title, "Bohemian Rhapsody");
    strcpy(library[0].artist, "Queen");
    strcpy(library[0].album, "A Night at the Opera");
    library[0].year = 1975;
    library[0].track_number = 1;

    strcpy(library[1].title, "Stairway to Heaven");
    strcpy(library[1].artist, "Led Zeppelin");
    strcpy(library[1].album, "Led Zeppelin IV");
    library[1].year = 1971;
    library[1].track_number = 4;

    strcpy(library[2].title, "Hotel California");
    strcpy(library[2].artist, "Eagles");
    strcpy(library[2].album, "Hotel California");
    library[2].year = 1976;
    library[2].track_number = 3;
}

// Print the music library to the console
void print_library() {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (library[i].title != NULL) {
            printf("%s by %s from the album %s (%d, track %d)\n",
                   library[i].title, library[i].artist, library[i].album,
                   library[i].year, library[i].track_number);
        }
    }
}

// Add a new entry to the music library
void add_entry(char *title, char *artist, char *album, int year, int track_number) {
    // Find the first empty slot in the library
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (library[i].title == NULL) {
            break;
        }
    }

    // If we found an empty slot, add the new entry
    if (i < MAX_ENTRIES) {
        library[i].title = malloc(strlen(title) + 1);
        strcpy(library[i].title, title);
        library[i].artist = malloc(strlen(artist) + 1);
        strcpy(library[i].artist, artist);
        library[i].album = malloc(strlen(album) + 1);
        strcpy(library[i].album, album);
        library[i].year = year;
        library[i].track_number = track_number;
    } else {
        printf("Error: The music library is full.\n");
    }
}

// Delete an entry from the music library
void delete_entry(char *title) {
    // Find the entry with the given title
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(library[i].title, title) == 0) {
            break;
        }
    }

    // If we found the entry, delete it
    if (i < MAX_ENTRIES) {
        free(library[i].title);
        free(library[i].artist);
        free(library[i].album);
        library[i].title = NULL;
        library[i].artist = NULL;
        library[i].album = NULL;
    } else {
        printf("Error: The music library does not contain an entry with the title '%s'.\n", title);
    }
}

// Search for an entry in the music library by title
music_entry *search_by_title(char *title) {
    // Find the entry with the given title
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(library[i].title, title) == 0) {
            break;
        }
    }

    // If we found the entry, return it
    if (i < MAX_ENTRIES) {
        return &library[i];
    } else {
        return NULL;
    }
}

// Search for an entry in the music library by artist
music_entry *search_by_artist(char *artist) {
    // Find the entry with the given artist
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(library[i].artist, artist) == 0) {
            break;
        }
    }

    // If we found the entry, return it
    if (i < MAX_ENTRIES) {
        return &library[i];
    } else {
        return NULL;
    }
}

// Search for an entry in the music library by album
music_entry *search_by_album(char *album) {
    // Find the entry with the given album
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(library[i].album, album) == 0) {
            break;
        }
    }

    // If we found the entry, return it
    if (i < MAX_ENTRIES) {
        return &library[i];
    } else {
        return NULL;
    }
}

// Main function
int main() {
    // Initialize the music library
    initialize_library();

    // Print the music library
    printf("Music Library:\n");
    print_library();

    // Add a new entry to the music library
    add_entry("Thriller", "Michael Jackson", "Thriller", 1982, 1);

    // Print the music library again
    printf("\nMusic Library after adding 'Thriller':\n");
    print_library();

    // Delete an entry from the music library
    delete_entry("Stairway to Heaven");

    // Print the music library again
    printf("\nMusic Library after deleting 'Stairway to Heaven':\n");
    print_library();

    // Search for an entry in the music library by title
    music_entry *entry = search_by_title("Hotel California");
    if (entry != NULL) {
        printf("\nEntry found by title: %s by %s from the album %s (%d, track %d)\n",
               entry->title, entry->artist, entry->album, entry->year, entry->track_number);
    } else {
        printf("\nEntry not found by title.\n");
    }

    // Search for an entry in the music library by artist
    entry = search_by_artist("Led Zeppelin");
    if (entry != NULL) {
        printf("\nEntry found by artist: %s by %s from the album %s (%d, track %d)\n",
               entry->title, entry->artist, entry->album, entry->year, entry->track_number);
    } else {
        printf("\nEntry not found by artist.\n");
    }

    // Search for an entry in the music library by album
    entry = search_by_album("Thriller");
    if (entry != NULL) {
        printf("\nEntry found by album: %s by %s from the album %s (%d, track %d)\n",
               entry->title, entry->artist, entry->album, entry->year, entry->track_number);
    } else {
        printf("\nEntry not found by album.\n");
    }

    return 0;
}