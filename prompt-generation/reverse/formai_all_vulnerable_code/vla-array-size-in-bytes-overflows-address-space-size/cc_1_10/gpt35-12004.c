//FormAI DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <string.h>

struct Song {
    char title[50];
    char artist[50];
    int duration;
};

int main() {
    int num_songs;
    printf("Enter the number of songs in your music library: ");
    scanf("%d", &num_songs);

    struct Song songs[num_songs];

    // populate song library
    for (int i = 0; i < num_songs; i++) {
        printf("\nEnter details of Song %d:\n", i+1);
        printf("Title: ");
        scanf("%s", songs[i].title);
        printf("Artist: ");
        scanf("%s", songs[i].artist);
        printf("Duration (in seconds): ");
        scanf("%d", &songs[i].duration);
    }

    // display song library
    printf("\nYour music library:\n\n");
    for (int i = 0; i < num_songs; i++) {
        printf("Song %d:\n", i+1);
        printf("Title: %s\n", songs[i].title);
        printf("Artist: %s\n", songs[i].artist);
        printf("Duration: %d seconds\n\n", songs[i].duration);
    }

    // search for a song
    char search_title[50];
    printf("Enter title of song to search: ");
    scanf("%s", search_title);

    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(songs[i].title, search_title) == 0) {
            printf("\n%s by %s was found in your library.\n", songs[i].title, songs[i].artist);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\n%s was not found in your library.\n", search_title);
    }

    return 0;
}