//FormAI DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* C Music Library Management System */

struct song {
    char title[100];
    char artist[100];
    char album[100];
    int duration; // in seconds
    int rating; // out of 5
};

int main() {

    int n, i;
    printf("\n=============== Welcome to C Music Library Management System ===============\n\n");

    printf("How many songs do you want to store in your library? ");
    scanf("%d", &n);

    struct song library[n];

    printf("\n\nStart entering the details of all songs in your library:\n\n");

    for(i=0; i<n; i++) {
        printf("Song %d:\n", i+1);
        printf("Enter title: ");
        getchar();
        fgets(library[i].title, 100, stdin);
        library[i].title[strcspn(library[i].title, "\n")] = 0;
        printf("Enter artist: ");
        fgets(library[i].artist, 100, stdin);
        library[i].artist[strcspn(library[i].artist, "\n")] = 0;
        printf("Enter album: ");
        fgets(library[i].album, 100, stdin);
        library[i].album[strcspn(library[i].album, "\n")] = 0;
        printf("Enter duration in seconds: ");
        scanf("%d", &library[i].duration);
        printf("Enter rating out of 5: ");
        scanf("%d", &library[i].rating);
        printf("\n");
    }

    printf("\n\nThe details of all songs in your library are as follows:\n\n");

    for(i=0; i<n; i++) {
        printf("Song %d:\n", i+1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Duration: %d seconds\n", library[i].duration);
        printf("Rating: %d out of 5\n", library[i].rating);
        printf("\n");
    }

    return 0;
}