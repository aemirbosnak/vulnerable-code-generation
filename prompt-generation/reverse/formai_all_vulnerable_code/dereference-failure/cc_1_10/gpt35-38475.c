//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

void add_song(struct song arr[], int *num_songs) {
    printf("Enter the song title: ");
    fgets(arr[*num_songs].title, 50, stdin);
    arr[*num_songs].title[strlen(arr[*num_songs].title) - 1] = '\0';
    printf("Enter the artist: ");
    fgets(arr[*num_songs].artist, 50, stdin);
    arr[*num_songs].artist[strlen(arr[*num_songs].artist) - 1] = '\0';
    printf("Enter the album: ");
    fgets(arr[*num_songs].album, 50, stdin);
    arr[*num_songs].album[strlen(arr[*num_songs].album) - 1] = '\0';
    printf("Enter the year: ");
    scanf("%d", &arr[*num_songs].year);
    getchar(); // consume the newline character
    (*num_songs)++;
    printf("Song added successfully!\n");
}

void display_songs(struct song arr[], int num_songs) {
    if (num_songs == 0) {
        printf("No songs added yet.\n");
        return;
    }
    printf("*********************\n");
    for (int i = 0; i < num_songs; i++) {
        printf("Title: %s\n", arr[i].title);
        printf("Artist: %s\n", arr[i].artist);
        printf("Album: %s\n", arr[i].album);
        printf("Year: %d\n", arr[i].year);
        printf("*********************\n");
    }
}

int main() {
    struct song songs[100];
    int num_songs = 0;

    printf("Welcome to the C Music Library!\n");

    while (1) {
        printf("\n");
        printf("1. Add a song\n");
        printf("2. Display songs\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // consume the newline character

        if (choice == 1) {
            add_song(songs, &num_songs);
        } else if (choice == 2) {
            display_songs(songs, num_songs);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Thank you for using the Music Library!\n");
    return 0;
}