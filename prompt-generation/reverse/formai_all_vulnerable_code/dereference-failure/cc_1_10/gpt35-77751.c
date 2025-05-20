//FormAI DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50 // maximum length of the song name

typedef struct Song {
    char name[MAX_LEN];
    char artist[MAX_LEN];
    int year;
    int duration;
    struct Song *next;
} Song;

Song *newSong(char name[MAX_LEN], char artist[MAX_LEN], int year, int duration) {
    Song *new = (Song*) malloc(sizeof(Song));
    strncpy(new->name, name, MAX_LEN);
    strncpy(new->artist, artist, MAX_LEN);
    new->year = year;
    new->duration = duration;
    new->next = NULL;
    return new;
}

void addSong(Song **head, char name[MAX_LEN], char artist[MAX_LEN], int year, int duration) {
    Song *new = newSong(name, artist, year, duration);
    if (*head == NULL) {
        *head = new;
    } else {
        Song *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }
}

void printSongs(Song *head) {
    if (head == NULL) {
        printf("No songs in the library.\n");
    } else {
        Song *current = head;
        while (current != NULL) {
            printf("%s by %s (%d) - %d seconds\n", current->name, current->artist, current->year, current->duration);
            current = current->next;
        }
    }
}

void deleteSong(Song **head, char name[MAX_LEN]) {
    if (*head == NULL) {
        printf("No songs in the library.\n");
    } else {
        Song *current = *head;
        Song *previous = NULL;
        while (current != NULL) {
            if (strcmp(current->name, name) == 0) {
                if (previous == NULL) {
                    *head = current->next;
                } else {
                    previous->next = current->next;
                }
                free(current);
                printf("Song removed from the library.\n");
                return;
            }
            previous = current;
            current = current->next;
        }
        printf("Song not found in the library.\n");
    }
}

int main() {
    Song *head = NULL;
    int choice;
    char name[MAX_LEN], artist[MAX_LEN];
    int year, duration;
    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add a song\n");
        printf("2. Display all songs\n");
        printf("3. Remove a song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter song name: ");
                scanf("%s", name);
                printf("Enter artist name: ");
                scanf("%s", artist);
                printf("Enter year of release: ");
                scanf("%d", &year);
                printf("Enter duration of the song (in seconds): ");
                scanf("%d", &duration);
                addSong(&head, name, artist, year, duration);
                printf("Song added to the library.\n");
                break;
            case 2:
                printf("\nMusic Library\n");
                printSongs(head);
                break;
            case 3:
                printf("Enter the name of the song to be removed: ");
                scanf("%s", name);
                deleteSong(&head, name);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0;
}