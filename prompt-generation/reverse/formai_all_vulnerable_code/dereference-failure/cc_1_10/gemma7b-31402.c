//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: active
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

// Create a linked list of music
Music* head = NULL;

// Function to insert music into the list
void insertMusic(char* title, char* artist, char* genre, int year) {
    Music* newMusic = (Music*)malloc(sizeof(Music));
    strcpy(newMusic->title, title);
    strcpy(newMusic->artist, artist);
    strcpy(newMusic->genre, genre);
    newMusic->year = year;
    newMusic->next = NULL;

    if (head == NULL) {
        head = newMusic;
    } else {
        Music* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newMusic;
    }
}

// Function to search music by title
Music* searchMusicByTitle(char* title) {
    Music* temp = head;
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
    Music* temp = head;
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
    Music* temp = head;
    while (temp) {
        if (strcmp(temp->genre, genre) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to search music by year
Music* searchMusicByYear(int year) {
    Music* temp = head;
    while (temp) {
        if (temp->year == year) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print music list
void printMusicList() {
    Music* temp = head;
    while (temp) {
        printf("%s - %s (%d) - %s\n", temp->title, temp->artist, temp->year, temp->genre);
        temp = temp->next;
    }
}

int main() {
    insertMusic("The Wall", "Pink Floyd", "Rock", 1973);
    insertMusic("Stairway to Heaven", "Led Zeppelin", "Rock", 1969);
    insertMusic("Imagine", "John Lennon", "Rock", 1971);
    insertMusic("Another One Bites the Dust", "Queen", "Rock", 1986);

    printMusicList();

    Music* searchMusic = searchMusicByTitle("The Wall");
    if (searchMusic) {
        printf("Found music: %s - %s (%d) - %s\n", searchMusic->title, searchMusic->artist, searchMusic->year, searchMusic->genre);
    } else {
        printf("Music not found.\n");
    }

    searchMusic = searchMusicByArtist("Led Zeppelin");
    if (searchMusic) {
        printf("Found music: %s - %s (%d) - %s\n", searchMusic->title, searchMusic->artist, searchMusic->year, searchMusic->genre);
    } else {
        printf("Music not found.\n");
    }

    searchMusic = searchMusicByGenre("Rock");
    if (searchMusic) {
        printf("Found music: %s - %s (%d) - %s\n", searchMusic->title, searchMusic->artist, searchMusic->year, searchMusic->genre);
    } else {
        printf("Music not found.\n");
    }

    searchMusic = searchMusicByYear(1973);
    if (searchMusic) {
        printf("Found music: %s - %s (%d) - %s\n", searchMusic->title, searchMusic->artist, searchMusic->year, searchMusic->genre);
    } else {
        printf("Music not found.\n");
    }

    return 0;
}