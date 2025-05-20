//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Limit the number of music files to 100.
#define MAX_FILES 100

// Define a MusicFile struct with attributes id, title, artist and length.
typedef struct MusicFile {
    int id;
    char* title;
    char* artist;
    int length;
} MusicFile;

// Define an array to store music files.
MusicFile files[MAX_FILES];
int numFiles = 0;

// Function to add a new music file to the library.
void addMusicFile(char* title, char* artist, int length) {
    // Check if the maximum number of files has been reached.
    if (numFiles >= MAX_FILES) {
        printf("The music library is full!\n");
        return;
    }

    // Create a new music file with a unique ID.
    MusicFile newFile;
    newFile.id = numFiles + 1;

    // Copy the title and artist name into the struct.
    newFile.title = (char*) malloc(sizeof(char) * strlen(title));
    strcpy(newFile.title, title);
    newFile.artist = (char*) malloc(sizeof(char) * strlen(artist));
    strcpy(newFile.artist, artist);

    // Set the length of the file.
    newFile.length = length;

    // Add the new file to the library.
    files[numFiles] = newFile;
    numFiles++;

    printf("%s by %s has been added to the music library.\n", title, artist);
}

// Function to print all the music files in the library.
void printMusicLibrary() {
    printf("Music Library:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%d) %s by %s - Length: %d seconds\n", files[i].id, files[i].title, files[i].artist, files[i].length);
    }
}

int main() {
    // Test adding files to the music library.
    addMusicFile("Bohemian Rhapsody", "Queen", 355);
    addMusicFile("Stairway to Heaven", "Led Zeppelin", 482);
    addMusicFile("Hotel California", "Eagles", 391);

    // Print out the music library.
    printMusicLibrary();

    return 0;
}