//FormAI DATASET v1.0 Category: Music Library Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int duration;
};

// Function to add a new Song to the library
void addSong(struct Song *library, int *numSongs) {
    struct Song newSong;
    printf("Enter the Song title: ");
    scanf("%s", newSong.title);
    printf("Enter the artist name: ");
    scanf("%s", newSong.artist);
    printf("Enter the album name: ");
    scanf("%s", newSong.album);
    printf("Enter the Song duration in seconds: ");
    scanf("%d", &newSong.duration);
    library[*numSongs] = newSong;
    *numSongs += 1;
}

// Function to display all the Songs in the library
void displaySongs(struct Song *library, int numSongs) {
    printf("\n%-30s%-20s%-20s%-10s\n","Title","Artist","Album","Duration");
    printf("-----------------------------------------------------------------\n");
    for (int i=0; i<numSongs; i++) {
        printf("%-30s%-20s%-20s%-10d\n",library[i].title, library[i].artist, library[i].album, library[i].duration);
    }
    printf("\n");
}

// Function to search and display Songs by an artist
void searchByArtist(struct Song *library, int numSongs) {
    char searchArtist[100];
    printf("Enter the artist name to search: ");
    scanf("%s", searchArtist);
    printf("\n%-30s%-20s%-20s%-10s\n","Title","Artist","Album","Duration");
    printf("-----------------------------------------------------------------\n");
    for (int i=0; i<numSongs; i++) {
        if (strcmp(library[i].artist,searchArtist)==0) {
            printf("%-30s%-20s%-20s%-10d\n",library[i].title, library[i].artist, library[i].album, library[i].duration);
        }
    }
    printf("\n");
}

int main() {
    int option, numSongs=0;
    struct Song *library = malloc(100 * sizeof(struct Song));

    do {
        printf("Welcome to the C Music Library Management System\n");
        printf("1. Add a new Song\n");
        printf("2. Display all Songs\n");
        printf("3. Search Songs by artist\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addSong(library, &numSongs);
                break;
            case 2:
                displaySongs(library, numSongs);
                break;
            case 3:
                searchByArtist(library, numSongs);
                break;
            case 4:
                printf("Thank you for using the C Music Library Management System!\n");
                break;
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }

    } while(option!=4);

    free(library);
    return 0;
}