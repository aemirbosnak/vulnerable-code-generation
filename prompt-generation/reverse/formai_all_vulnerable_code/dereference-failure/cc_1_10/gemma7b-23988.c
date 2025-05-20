//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include <stdio.h>
#include <string.h>

// Define a structure to store music library information
typedef struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a new music library entry
void insertMusicLibraryEntry(MusicLibrary** head, char* title, char* artist, char* genre, int year) {
    MusicLibrary* newMusicLibraryEntry = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    strcpy(newMusicLibraryEntry->title, title);
    strcpy(newMusicLibraryEntry->artist, artist);
    strcpy(newMusicLibraryEntry->genre, genre);
    newMusicLibraryEntry->year = year;
    newMusicLibraryEntry->next = NULL;

    if (*head == NULL) {
        *head = newMusicLibraryEntry;
    } else {
        (*head)->next = newMusicLibraryEntry;
    }
}

// Function to search for a music library entry
MusicLibrary* searchMusicLibraryEntry(MusicLibrary* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to delete a music library entry
void deleteMusicLibraryEntry(MusicLibrary* head, char* title) {
    MusicLibrary* previous = NULL;
    MusicLibrary* current = head;

    while (current) {
        if (strcmp(current->title, title) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

// Main function
int main() {
    MusicLibrary* musicLibrary = NULL;

    // Insert some music library entries
    insertMusicLibraryEntry(&musicLibrary, "The Dark Side of the Moon", "Pink Floyd", "Rock", 1973);
    insertMusicLibraryEntry(&musicLibrary, "Thriller", "Michael Jackson", "Pop", 1982);
    insertMusicLibraryEntry(&musicLibrary, "Sgt. Pepper's Lonely Hearts Club Band", "The Beatles", "Rock", 1967);

    // Search for a music library entry
    MusicLibrary* entry = searchMusicLibraryEntry(musicLibrary, "The Dark Side of the Moon");
    if (entry) {
        printf("Title: %s\n", entry->title);
        printf("Artist: %s\n", entry->artist);
        printf("Genre: %s\n", entry->genre);
        printf("Year: %d\n", entry->year);
    }

    // Delete a music library entry
    deleteMusicLibraryEntry(musicLibrary, "Thriller");

    // Search for the updated music library entry
    entry = searchMusicLibraryEntry(musicLibrary, "Thriller");
    if (entry) {
        printf("Title: %s\n", entry->title);
        printf("Artist: %s\n", entry->artist);
        printf("Genre: %s\n", entry->genre);
        printf("Year: %d\n", entry->year);
    }

    return 0;
}