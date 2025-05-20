//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music album
typedef struct Album {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Album* next;
} Album;

// Function to insert a new album into the linked list
void insertAlbum(Album** head, char* title, char* artist, char* genre, int year) {
    Album* newAlbum = (Album*)malloc(sizeof(Album));
    strcpy(newAlbum->title, title);
    strcpy(newAlbum->artist, artist);
    strcpy(newAlbum->genre, genre);
    newAlbum->year = year;
    newAlbum->next = NULL;

    if (*head == NULL) {
        *head = newAlbum;
    } else {
        (*head)->next = newAlbum;
    }
}

// Function to search for an album by title
Album* searchAlbum(Album* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to print all albums
void printAlbums(Album* head) {
    while (head) {
        printf("%s by %s ( %d )\n", head->title, head->artist, head->year);
        head = head->next;
    }
}

int main() {
    Album* head = NULL;

    // Insert some albums
    insertAlbum(&head, "Thriller", "Michael Jackson", "Pop", 1987);
    insertAlbum(&head, "Back in Black", "Led Zeppelin", "Rock", 1969);
    insertAlbum(&head, "Abbey Road", "The Beatles", "Rock", 1969);

    // Search for an album
    Album* foundAlbum = searchAlbum(head, "Abbey Road");

    // Print the found album
    if (foundAlbum) {
        printf("%s by %s ( %d )\n", foundAlbum->title, foundAlbum->artist, foundAlbum->year);
    } else {
        printf("Album not found\n");
    }

    // Print all albums
    printAlbums(head);

    return 0;
}