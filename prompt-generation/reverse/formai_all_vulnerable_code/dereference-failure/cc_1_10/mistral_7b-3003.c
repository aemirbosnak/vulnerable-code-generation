//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Gratitude to the Open Source Community for providing us with such powerful tools

// Structure to represent a Music File
typedef struct MusicFile {
    char title[100];
    char artist[50];
    char genre[30];
    char filePath[200];
    struct MusicFile* next;
} MusicFile;

// Function to create a new MusicFile node
MusicFile* createMusicFileNode(char* title, char* artist, char* genre, char* filePath) {
    MusicFile* newNode = (MusicFile*) malloc(sizeof(MusicFile));
    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);
    strcpy(newNode->genre, genre);
    strcpy(newNode->filePath, filePath);
    newNode->next = NULL;
    return newNode;
}

// Function to add a new MusicFile to the library
void addMusicFile(MusicFile** head, char* title, char* artist, char* genre, char* filePath) {
    MusicFile* newNode = createMusicFileNode(title, artist, genre, filePath);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    MusicFile* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to display the contents of the MusicLibrary
void displayMusicLibrary(MusicFile* head) {
    MusicFile* current = head;

    printf("=====================\n");
    printf("Music Library\n");
    printf("=====================\n");

    while (current != NULL) {
        printf("\nTitle: %s\n", current->title);
        printf("Artist: %s\n", current->artist);
        printf("Genre: %s\n", current->genre);
        printf("FilePath: %s\n", current->filePath);
        current = current->next;
    }
}

int main() {
    MusicFile* musicLibrary = NULL;

    // Adding some MusicFiles to the library
    addMusicFile(&musicLibrary, "Bohemian Rhapsody", "Queen", "Rock", "/path/to/bohemian_rhapsody.mp3");
    addMusicFile(&musicLibrary, "Another Brick in the Wall", "Pink Floyd", "Rock", "/path/to/another_brick.mp3");
    addMusicFile(&musicLibrary, "Stairway to Heaven", "Led Zeppelin", "Rock", "/path/to/stairway.mp3");
    addMusicFile(&musicLibrary, "Imagine", "John Lennon", "Rock", "/path/to/imagine.mp3");

    // Displaying the contents of the MusicLibrary
    displayMusicLibrary(musicLibrary);

    return 0;
}