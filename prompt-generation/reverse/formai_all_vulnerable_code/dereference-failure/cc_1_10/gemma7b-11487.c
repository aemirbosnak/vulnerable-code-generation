//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
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

// Function to insert a new music into the library
Music* insertMusic(Music* head) {
    Music* newMusic = (Music*)malloc(sizeof(Music));
    printf("Enter the title of the music: ");
    scanf("%s", newMusic->title);
    printf("Enter the artist of the music: ");
    scanf("%s", newMusic->artist);
    printf("Enter the genre of the music: ");
    scanf("%s", newMusic->genre);
    printf("Enter the year of the music: ");
    scanf("%d", &newMusic->year);

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

    return head;
}

// Function to search for music in the library
Music* searchMusic(Music* head, char* title) {
    Music* temp = head;
    while (temp) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the music library
void printMusic(Music* head) {
    Music* temp = head;
    while (temp) {
        printf("%s - %s (%s, %d)\n", temp->title, temp->artist, temp->genre, temp->year);
        temp = temp->next;
    }
}

int main() {
    Music* musicLibrary = NULL;

    // Insert some music into the library
    musicLibrary = insertMusic(musicLibrary);
    musicLibrary = insertMusic(musicLibrary);
    musicLibrary = insertMusic(musicLibrary);

    // Search for music in the library
    Music* foundMusic = searchMusic(musicLibrary, "The Beatles - Let's Get Back Together");

    // Print the music library
    printMusic(musicLibrary);

    // Print the found music
    if (foundMusic) {
        printf("Found music: %s - %s (%s, %d)\n", foundMusic->title, foundMusic->artist, foundMusic->genre, foundMusic->year);
    } else {
        printf("No music found.\n");
    }

    return 0;
}