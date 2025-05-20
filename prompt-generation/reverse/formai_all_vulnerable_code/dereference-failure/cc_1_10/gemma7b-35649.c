//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
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

// Function to insert a new music item into the linked list
void insertMusic(Music* head, Music* newMusic) {
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

// Function to search for music by title
Music* searchMusicByTitle(Music* head, char* title) {
    Music* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to search for music by artist
Music* searchMusicByArtist(Music* head, char* artist) {
    Music* temp = head;
    while (temp) {
        if (strcmp(temp->artist, artist) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to search for music by genre
Music* searchMusicByGenre(Music* head, char* genre) {
    Music* temp = head;
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
    printf("\n");
}

int main() {
    Music* head = NULL;

    // Insert some music items
    insertMusic(head, malloc(sizeof(Music)));
    strcpy(head->title, "The Dark Side of the Moon");
    strcpy(head->artist, "Pink Floyd");
    strcpy(head->genre, "Rock");
    head->year = 1973;

    insertMusic(head, malloc(sizeof(Music)));
    strcpy(head->title, "Thriller");
    strcpy(head->artist, "Michael Jackson");
    strcpy(head->genre, "Pop");
    head->year = 1987;

    insertMusic(head, malloc(sizeof(Music)));
    strcpy(head->title, "Back in Black");
    strcpy(head->artist, "AC/DC");
    strcpy(head->genre, "Rock");
    head->year = 1980;

    // Search for music by title
    Music* music = searchMusicByTitle(head, "The Dark Side of the Moon");
    if (music) {
        printMusic(music);
    } else {
        printf("Music not found.\n");
    }

    // Search for music by artist
    music = searchMusicByArtist(head, "Pink Floyd");
    if (music) {
        printMusic(music);
    } else {
        printf("Music not found.\n");
    }

    // Search for music by genre
    music = searchMusicByGenre(head, "Rock");
    if (music) {
        printMusic(music);
    } else {
        printf("Music not found.\n");
    }

    return 0;
}