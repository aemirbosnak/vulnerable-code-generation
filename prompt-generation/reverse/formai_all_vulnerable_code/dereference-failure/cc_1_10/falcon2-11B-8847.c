//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song {
    char title[50];
    char artist[50];
    int length;
    int rating;
};

struct library {
    int size;
    struct song* songs;
};

int main() {
    struct library lib;
    lib.size = 0;
    lib.songs = NULL;

    struct song song1 = {
        "Bohemian Rhapsody",
        "Queen",
        5,
        4
    };

    struct song song2 = {
        "Imagine",
        "John Lennon",
        4,
        3
    };

    struct song song3 = {
        "Stairway to Heaven",
        "Led Zeppelin",
        8,
        5
    };

    lib.songs = (struct song*)malloc(sizeof(struct song) * 3);
    if (lib.songs == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    lib.songs[0] = song1;
    lib.songs[1] = song2;
    lib.songs[2] = song3;

    printf("Music Library\n");
    printf("---------------------\n");
    printf("Size: %d\n", lib.size);
    printf("Songs:\n");
    for (int i = 0; i < lib.size; i++) {
        printf("Song %d:\n", i + 1);
        printf("Title: %s\n", lib.songs[i].title);
        printf("Artist: %s\n", lib.songs[i].artist);
        printf("Length: %d seconds\n", lib.songs[i].length);
        printf("Rating: %d\n\n", lib.songs[i].rating);
    }

    return 0;
}