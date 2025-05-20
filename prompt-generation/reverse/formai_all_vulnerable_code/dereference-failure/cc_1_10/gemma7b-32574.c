//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music information
typedef struct Music {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Music* next;
} Music;

// Create a linked list to store music information
Music* musicList = NULL;

// Function to insert music into the list
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
        Music* temp = musicList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newMusic;
    }
}

// Function to search music by title
Music* searchMusicByTitle(char* title) {
    Music* temp = musicList;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to search music by artist
Music* searchMusicByArtist(char* artist) {
    Music* temp = musicList;
    while (temp) {
        if (strcmp(temp->artist, artist) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to search music by genre
Music* searchMusicByGenre(char* genre) {
    Music* temp = musicList;
    while (temp) {
        if (strcmp(temp->genre, genre) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print music information
void printMusic(Music* music) {
    printf("Title: %s\n", music->title);
    printf("Artist: %s\n", music->artist);
    printf("Genre: %s\n", music->genre);
    printf("Year: %d\n", music->year);
}

int main() {
    insertMusic("Song 1", "Artist 1", "Genre 1", 2000);
    insertMusic("Song 2", "Artist 2", "Genre 2", 2001);
    insertMusic("Song 3", "Artist 3", "Genre 1", 2002);

    Music* music = searchMusicByTitle("Song 2");
    printMusic(music);

    music = searchMusicByArtist("Artist 2");
    printMusic(music);

    music = searchMusicByGenre("Genre 1");
    printMusic(music);

    return 0;
}