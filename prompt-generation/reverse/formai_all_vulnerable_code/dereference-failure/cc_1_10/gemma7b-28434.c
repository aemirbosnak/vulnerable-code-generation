//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store music library information
typedef struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a new music entry into the library
void insertMusic(MusicLibrary** head) {
    MusicLibrary* newMusic = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    printf("Enter title: ");
    scanf("%s", newMusic->title);
    printf("Enter artist: ");
    scanf("%s", newMusic->artist);
    printf("Enter genre: ");
    scanf("%s", newMusic->genre);
    printf("Enter year: ");
    scanf("%d", &newMusic->year);
    newMusic->next = NULL;

    if (*head == NULL) {
        *head = newMusic;
    } else {
        (*head)->next = newMusic;
    }
}

// Function to display all music entries in the library
void displayMusic(MusicLibrary* head) {
    while (head) {
        printf("Title: %s\n", head->title);
        printf("Artist: %s\n", head->artist);
        printf("Genre: %s\n", head->genre);
        printf("Year: %d\n", head->year);
        printf("\n");
        head = head->next;
    }
}

int main() {
    MusicLibrary* musicLibrary = NULL;
    int choice;

    printf("Welcome to the Music Library Management System!\n");

    while (1) {
        printf("Enter 1 to insert a new music entry, 2 to display all music entries, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertMusic(&musicLibrary);
                break;
            case 2:
                displayMusic(musicLibrary);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}