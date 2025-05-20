//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Song {
    char title[100];
    char artist[50];
    int duration;
    struct Song* next;
} Song;

typedef struct Node {
    Song data;
    struct Node* next;
} Node;

typedef struct Library {
    Node* head;
    Node* tail;
} Library;

void initLibrary(Library* library) {
    library->head = NULL;
    library->tail = NULL;
}

Node* createSongNode(Song song) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = song;
    newNode->next = NULL;
    return newNode;
}

void addSongToLibrary(Library* library, Song song) {
    Node* newSongNode = createSongNode(song);

    if (library->head == NULL) {
        library->head = newSongNode;
        library->tail = newSongNode;
    } else {
        library->tail->next = newSongNode;
        library->tail = newSongNode;
    }
}

void printLibrary(Library* library) {
    printf("=============================================\n");
    printf("The Enchanted Melodic Menagerie:\n");
    printf("=============================================\n");

    Node* currentSong = library->head;

    while (currentSong != NULL) {
        printf("%s by %s (%d seconds)\n", currentSong->data.title, currentSong->data.artist, currentSong->data.duration);
        currentSong = currentSong->next;
    }
}

int main() {
    Library myLibrary;
    initLibrary(&myLibrary);

    printf("Welcome to The Enchanted Melodic Menagerie! Let's add some magical tunes.\n");

    Song enchantedForest = {"Enchanted Forest", "Mystic Woods", 120};
    Song fairyDance = {"Fairy Dance", "Pixie Poppers", 90};
    Song dragonRoar = {"Dragon Roar", "Mighty Wyrm", 180};

    addSongToLibrary(&myLibrary, enchantedForest);
    addSongToLibrary(&myLibrary, fairyDance);
    addSongToLibrary(&myLibrary, dragonRoar);

    printf("\nYour enchanting library now contains:\n");
    printLibrary(&myLibrary);

    return 0;
}