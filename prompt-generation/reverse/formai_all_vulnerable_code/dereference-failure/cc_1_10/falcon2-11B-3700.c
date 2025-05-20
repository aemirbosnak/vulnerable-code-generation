//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    char title[50];
    char artist[50];
    struct Node* next;
};

// Function to add a song to the library
void addSong(struct Node** head, char* title, char* artist) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // Copy the title and artist strings to the new node
    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);

    // Set the new node's next pointer to NULL
    newNode->next = NULL;

    // If the library is empty, set the new node as the head
    if (*head == NULL) {
        *head = newNode;
    }
    // Otherwise, insert the new node at the end of the list
    else {
        struct Node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to remove a song from the library
void removeSong(struct Node** head, char* title) {
    // Initialize the current pointer to the head of the list
    struct Node* current = *head;

    // Search for the song with the given title
    while (current!= NULL && strcmp(current->title, title)!= 0) {
        current = current->next;
    }

    // If the song was found, remove it from the list
    if (current!= NULL) {
        if (*head == current) {
            *head = current->next;
        } else {
            struct Node* prev = *head;
            while (prev->next!= current) {
                prev = prev->next;
            }
            prev->next = current->next;
        }
        free(current);
    }
}

// Function to search for a song by title or artist
void searchSong(struct Node* head, char* query) {
    // Initialize the current pointer to the head of the list
    struct Node* current = head;

    // Search for the song with the given query
    while (current!= NULL) {
        if (strcmp(current->title, query) == 0 || strcmp(current->artist, query) == 0) {
            printf("Song: %s - %s\n", current->title, current->artist);
        }
        current = current->next;
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Add songs to the library
    addSong(&head, "Bohemian Rhapsody", "Queen");
    addSong(&head, "Stairway to Heaven", "Led Zeppelin");
    addSong(&head, "Imagine", "John Lennon");

    // Search for songs by title or artist
    searchSong(head, "Queen");
    searchSong(head, "Led Zeppelin");
    searchSong(head, "Imagine");

    // Remove songs from the library
    removeSong(&head, "Stairway to Heaven");
    removeSong(&head, "Queen");

    // Search for songs again
    searchSong(head, "Led Zeppelin");
    searchSong(head, "Imagine");

    return 0;
}