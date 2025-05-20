//FormAI DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

int main() {
    struct Song *library;
    int n;

    printf("Enter the number of songs in your library: ");
    scanf("%d", &n);

    // Allocate memory to store song data
    library = (struct Song *) malloc(n * sizeof(struct Song));

    // Input song data
    for (int i = 0; i < n; i++) {
        printf("\nSong %d details:\n", i+1);
        printf("Title: ");
        scanf("%s", library[i].title);
        printf("Artist: ");
        scanf("%s", library[i].artist);
        printf("Album: ");
        scanf("%s", library[i].album);
        printf("Year: ");
        scanf("%d", &library[i].year);
    }

    // Sort the songs by title name
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (strcmp(library[i].title, library[j].title) > 0) {
                struct Song temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }

    // Display the sorted library
    printf("\nYour music library:\n");
    printf("Title\tArtist\tAlbum\tYear\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%s\t%d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }

    return 0;
}