//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the Music Library Management System structure
typedef struct MusicLibrary
{
    char title[256];
    char artist[256];
    char genre[256];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a new music record into the library
void insertMusic(MusicLibrary* library, char* title, char* artist, char* genre, int year)
{
    MusicLibrary* newMusic = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    strcpy(newMusic->title, title);
    strcpy(newMusic->artist, artist);
    strcpy(newMusic->genre, genre);
    newMusic->year = year;
    newMusic->next = NULL;

    if (library == NULL)
    {
        library = newMusic;
    }
    else
    {
        library->next = newMusic;
    }
}

// Function to search for music records in the library
MusicLibrary* searchMusic(MusicLibrary* library, char* title)
{
    MusicLibrary* currentMusic = library;

    while (currentMusic)
    {
        if (strcmp(currentMusic->title, title) == 0)
        {
            return currentMusic;
        }
        currentMusic = currentMusic->next;
    }

    return NULL;
}

// Function to delete a music record from the library
void deleteMusic(MusicLibrary* library, char* title)
{
    MusicLibrary* previousMusic = NULL;
    MusicLibrary* currentMusic = library;

    while (currentMusic)
    {
        if (strcmp(currentMusic->title, title) == 0)
        {
            if (previousMusic)
            {
                previousMusic->next = currentMusic->next;
            }
            else
            {
                library = currentMusic->next;
            }
            free(currentMusic);
            return;
        }
        previousMusic = currentMusic;
        currentMusic = currentMusic->next;
    }

    return;
}

int main()
{
    MusicLibrary* library = NULL;

    // Insert some music records
    insertMusic(library, "The Dark Side of the Moon", "Pink Floyd", "Rock", 1973);
    insertMusic(library, "Thriller", "Michael Jackson", "Pop", 1987);
    insertMusic(library, "Back in Black", "Led Zeppelin", "Rock", 1969);

    // Search for a music record
    MusicLibrary* foundMusic = searchMusic(library, "The Dark Side of the Moon");

    // If the music record was found, print its details
    if (foundMusic)
    {
        printf("Title: %s\n", foundMusic->title);
        printf("Artist: %s\n", foundMusic->artist);
        printf("Genre: %s\n", foundMusic->genre);
        printf("Year: %d\n", foundMusic->year);
    }

    // Delete a music record
    deleteMusic(library, "Thriller");

    // Search for the music record after deletion
    foundMusic = searchMusic(library, "Thriller");

    // If the music record was not found, print an error message
    if (foundMusic == NULL)
    {
        printf("Error: Music record not found.\n");
    }

    return 0;
}