//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 50

// --- Song Struct ---
typedef struct Song {
    char* name;
    char* artist;
    int year;
} Song;

// --- Database Struct ---
typedef struct Database {
    Song **songs;
    int size;
} Database;

// --- Function Prototypes ---
void addSong(Database* db, char* name, char* artist, int year);
void printSongs(Database* db);
void freeDatabase(Database* db);

// --- Main ---
int main()
{
    // Initialize Database
    Database *musicLibrary = malloc(sizeof(Database));
    musicLibrary->size = 0;
    musicLibrary->songs = malloc(MAX_SONGS * sizeof(Song*));
    
    // Add Songs to the Library
    addSong(musicLibrary, "Cherry Blossom", "Lucky Kilimanjaro", 2019);
    addSong(musicLibrary, "The Weekend", "SZA", 2017);
    addSong(musicLibrary, "Gasoline", "Halsey", 2014);
    addSong(musicLibrary, "Kodachrome", "Paul Simon", 1973);
    
    // Print the Songs in the Library
    printf("Music Library:\n");
    printSongs(musicLibrary);
    
    // Free Database Memory
    freeDatabase(musicLibrary);
    return 0;
}

// --- Function Definitions ---

// Add a Song to the Database
void addSong(Database* db, char* name, char* artist, int year)
{
    if (db->size < MAX_SONGS)
    {
        Song *newSong = malloc(sizeof(Song));
        newSong->name = malloc(strlen(name) + 1);
        strcpy(newSong->name, name);
        newSong->artist = malloc(strlen(artist) + 1);
        strcpy(newSong->artist, artist);
        newSong->year = year;

        db->songs[db->size] = newSong;
        db->size++;
    }
    else
    {
        printf("ERROR: Music library is full, cannot add song.\n");
    }
}

// Print the Songs in the Database
void printSongs(Database* db)
{
    for (int i = 0; i < db->size; i++)
    {
        printf("%d. %s by %s (%d)\n", i+1, db->songs[i]->name, 
               db->songs[i]->artist, db->songs[i]->year);   
    }
}

// Free Memory Allocated for the Database
void freeDatabase(Database* db)
{
    for (int i = 0; i < db->size; i++)
    {
        free(db->songs[i]->name);
        free(db->songs[i]->artist);
        free(db->songs[i]);
    }
    free(db->songs);
    free(db);
}