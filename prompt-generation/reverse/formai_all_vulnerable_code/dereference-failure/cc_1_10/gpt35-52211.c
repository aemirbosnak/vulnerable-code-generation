//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about a song
struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    float duration;
};

// Structure to store information about a node in the linked list
struct Node {
    struct Song song;
    struct Node* next;
};

typedef struct Node* List;

// Function to create a new node and add it to the end of the list
void addSong(List* list, struct Song song) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->song = song;
    newNode->next = NULL;
    if (*list == NULL) {
        *list = newNode;
    } else {
        struct Node* lastNode = *list;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

// Function to print the list of songs
void printList(List list) {
    printf("Title\t\tArtist\t\tAlbum\t\tYear\tDuration\n");
    printf("---------------------------------------------------------------\n");
    struct Node* currentNode = list;
    while (currentNode != NULL) {
        printf("%s\t%s\t%s\t%d\t%.2f\n", currentNode->song.title, currentNode->song.artist, currentNode->song.album, currentNode->song.year, currentNode->song.duration);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Function to search for a song by title
void searchTitle(List list, char title[50]) {
    struct Node* currentNode = list;
    while (currentNode != NULL) {
        if (strcmp(currentNode->song.title, title) == 0) {
            printf("Title\t\tArtist\t\tAlbum\t\tYear\tDuration\n");
            printf("---------------------------------------------------------------\n");
            printf("%s\t%s\t%s\t%d\t%.2f\n\n", currentNode->song.title, currentNode->song.artist, currentNode->song.album, currentNode->song.year, currentNode->song.duration);
            return;
        }
        currentNode = currentNode->next;
    }
    printf("Song not found.\n\n");
}

// Function to search for a song by artist
void searchArtist(List list, char artist[50]) {
    struct Node* currentNode = list;
    while (currentNode != NULL) {
        if (strcmp(currentNode->song.artist, artist) == 0) {
            printf("Title\t\tArtist\t\tAlbum\t\tYear\tDuration\n");
            printf("---------------------------------------------------------------\n");
            printf("%s\t%s\t%s\t%d\t%.2f\n", currentNode->song.title, currentNode->song.artist, currentNode->song.album, currentNode->song.year, currentNode->song.duration);
        }
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    // Initialize the list to NULL
    List songList = NULL;

    // Add some songs to the list
    struct Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 5.55};
    addSong(&songList, song1);

    struct Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 8.03};
    addSong(&songList, song2);

    struct Song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 6.30};
    addSong(&songList, song3);

    struct Song song4 = {"Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991, 5.01};
    addSong(&songList, song4);

    // Print the list of songs
    printList(songList);

    // Search for a song by title
    printf("Search for a song by title: ");
    char title[50];
    fflush(stdin);
    fgets(title, 50, stdin);
    if (title[strlen(title) - 1] == '\n') {
        title[strlen(title) - 1] = '\0';
    }
    searchTitle(songList, title);

    // Search for songs by artist
    printf("Search for songs by artist: ");
    char artist[50];
    fflush(stdin);
    fgets(artist, 50, stdin);
    if (artist[strlen(artist) - 1] == '\n') {
        artist[strlen(artist) - 1] = '\0';
    }
    searchArtist(songList, artist);

    return 0;
}