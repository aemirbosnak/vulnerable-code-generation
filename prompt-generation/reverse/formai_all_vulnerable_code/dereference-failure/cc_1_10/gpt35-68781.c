//FormAI DATASET v1.0 Category: Music Library Management System ; Style: secure
// C Music Library Management System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store information about each song
typedef struct Song {
    char title[100];
    char artist[100];
    int duration;
    int rating;
    struct Song* next;
} Song;

// Function to add a new song to the library
Song* addSong(Song* head) {
    Song* newSong = (Song*) malloc(sizeof(Song));
    printf("\nEnter details of the song:\n");
    printf("Title: ");
    fgets(newSong->title, 100, stdin);
    printf("Artist: ");
    fgets(newSong->artist, 100, stdin);
    printf("Duration (in seconds): ");
    scanf("%d", &newSong->duration);
    printf("Rating (out of 10): ");
    scanf("%d", &newSong->rating);
    getchar(); // To clear input buffer of newline character

    // Add the new song to the head of the linked list
    newSong->next = head;
    head = newSong;
    printf("\nSong added successfully!\n");
    return head;
}

// Function to display all songs in the library
void displaySongs(Song* head) {
    Song* current = head;
    printf("\nAll Songs in Library:\n");
    while (current != NULL) {
        printf("Title: %s", current->title);
        printf("Artist: %s", current->artist);
        printf("Duration: %d seconds\n", current->duration);
        printf("Rating: %d/10\n", current->rating);
        current = current->next;
    }
}

int main() {
    Song* head = NULL; // Initializing an empty linked list

    // Menu-driven program
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Add a new song\n");
        printf("2. Display all songs\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);
        getchar(); // To clear input buffer of newline character

        switch (choice) {
            case 1:
                head = addSong(head);
                break;
            case 2:
                displaySongs(head);
                break;
            case 3:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}