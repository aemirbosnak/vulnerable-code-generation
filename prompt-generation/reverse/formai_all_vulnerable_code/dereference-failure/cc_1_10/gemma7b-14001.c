//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <string.h>

// Define a structure for a music library item
typedef struct MusicItem {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicItem* next;
} MusicItem;

// Create a linked list of music library items
MusicItem* head = NULL;

// Function to add a music library item to the linked list
void addMusicItem(char* title, char* artist, char* genre, int year) {
    MusicItem* newNode = malloc(sizeof(MusicItem));
    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);
    strcpy(newNode->genre, genre);
    newNode->year = year;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        MusicItem* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a music library item by title
MusicItem* searchMusicItemByTitle(char* title) {
    MusicItem* currentItem = head;
    while (currentItem) {
        if (strcmp(currentItem->title, title) == 0) {
            return currentItem;
        }
        currentItem = currentItem->next;
    }
    return NULL;
}

// Function to search for a music library item by artist
MusicItem* searchMusicItemByArtist(char* artist) {
    MusicItem* currentItem = head;
    while (currentItem) {
        if (strcmp(currentItem->artist, artist) == 0) {
            return currentItem;
        }
        currentItem = currentItem->next;
    }
    return NULL;
}

// Function to search for a music library item by genre
MusicItem* searchMusicItemByGenre(char* genre) {
    MusicItem* currentItem = head;
    while (currentItem) {
        if (strcmp(currentItem->genre, genre) == 0) {
            return currentItem;
        }
        currentItem = currentItem->next;
    }
    return NULL;
}

// Function to search for a music library item by year
MusicItem* searchMusicItemByYear(int year) {
    MusicItem* currentItem = head;
    while (currentItem) {
        if (currentItem->year == year) {
            return currentItem;
        }
        currentItem = currentItem->next;
    }
    return NULL;
}

// Main function
int main() {
    // Add some music library items
    addMusicItem("Bohemian Rhapsody", "Queen", "Rock", 1975);
    addMusicItem("Thriller", "Michael Jackson", "Pop", 1987);
    addMusicItem("Stairway to Heaven", "Led Zeppelin", "Rock", 1969);
    addMusicItem("The Sound of Silence", "Simon & Garfunkel", "Folk", 1964);

    // Search for music library items
    MusicItem* item = searchMusicItemByTitle("Bohemian Rhapsody");
    if (item) {
        printf("Title: %s\n", item->title);
        printf("Artist: %s\n", item->artist);
        printf("Genre: %s\n", item->genre);
        printf("Year: %d\n", item->year);
    } else {
        printf("Item not found.\n");
    }

    item = searchMusicItemByArtist("Michael Jackson");
    if (item) {
        printf("Title: %s\n", item->title);
        printf("Artist: %s\n", item->artist);
        printf("Genre: %s\n", item->genre);
        printf("Year: %d\n", item->year);
    } else {
        printf("Item not found.\n");
    }

    item = searchMusicItemByGenre("Rock");
    if (item) {
        printf("Title: %s\n", item->title);
        printf("Artist: %s\n", item->artist);
        printf("Genre: %s\n", item->genre);
        printf("Year: %d\n", item->year);
    } else {
        printf("Item not found.\n");
    }

    item = searchMusicItemByYear(1975);
    if (item) {
        printf("Title: %s\n", item->title);
        printf("Artist: %s\n", item->artist);
        printf("Genre: %s\n", item->genre);
        printf("Year: %d\n", item->year);
    } else {
        printf("Item not found.\n");
    }

    return 0;
}