//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music information
typedef struct Music {
    char title[20];
    char artist[20];
    char genre[20];
    int year;
    struct Music* next;
} Music;

// Create a linked list to store music information
Music* musicList = NULL;

// Function to insert a new music into the list
void insertMusic(char* title, char* artist, char* genre, int year) {
    Music* newMusic = (Music*)malloc(sizeof(Music));
    strcpy(newMusic->title, title);
    strcpy(newMusic->artist, artist);
    strcpy(newMusic->genre, genre);
    newMusic->year = year;
    newMusic->next = NULL;

    if (musicList == NULL) {
        musicList = newMusic;
    } else {
        Music* lastMusic = musicList;
        while (lastMusic->next != NULL) {
            lastMusic = lastMusic->next;
        }
        lastMusic->next = newMusic;
    }
}

// Function to search for music by title
Music* searchMusicByTitle(char* title) {
    Music* currentMusic = musicList;
    while (currentMusic) {
        if (strcmp(currentMusic->title, title) == 0) {
            return currentMusic;
        }
        currentMusic = currentMusic->next;
    }
    return NULL;
}

// Function to search for music by artist
Music* searchMusicByArtist(char* artist) {
    Music* currentMusic = musicList;
    while (currentMusic) {
        if (strcmp(currentMusic->artist, artist) == 0) {
            return currentMusic;
        }
        currentMusic = currentMusic->next;
    }
    return NULL;
}

// Function to search for music by genre
Music* searchMusicByGenre(char* genre) {
    Music* currentMusic = musicList;
    while (currentMusic) {
        if (strcmp(currentMusic->genre, genre) == 0) {
            return currentMusic;
        }
        currentMusic = currentMusic->next;
    }
    return NULL;
}

// Function to search for music by year
Music* searchMusicByYear(int year) {
    Music* currentMusic = musicList;
    while (currentMusic) {
        if (currentMusic->year == year) {
            return currentMusic;
        }
        currentMusic = currentMusic->next;
    }
    return NULL;
}

// Function to print music information
void printMusic(Music* music) {
    printf("Title: %s\n", music->title);
    printf("Artist: %s\n", music->artist);
    printf("Genre: %s\n", music->genre);
    printf("Year: %d\n", music->year);
    printf("\n");
}

int main() {
    // Insert some music into the list
    insertMusic("Thriller", "Michael Jackson", "Pop", 1987);
    insertMusic("Black Hole Sun", "Soundgarden", "Grunge", 1994);
    insertMusic("Bohemian Rhapsody", "Queen", "Rock", 1975);
    insertMusic("Smells Like Teen Spirit", "Nirvana", "Grunge", 1989);

    // Search for music by title
    Music* music = searchMusicByTitle("Thriller");
    printMusic(music);

    // Search for music by artist
    music = searchMusicByArtist("Soundgarden");
    printMusic(music);

    // Search for music by genre
    music = searchMusicByGenre("Grunge");
    printMusic(music);

    // Search for music by year
    music = searchMusicByYear(1987);
    printMusic(music);

    return 0;
}