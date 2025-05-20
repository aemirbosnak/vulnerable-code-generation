//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

struct Music {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char genre[MAX_LENGTH];
};

void addMusic(struct Music* library, char* title, char* artist, char* genre) {
    if (title!= NULL && artist!= NULL && genre!= NULL) {
        library->title[0] = '\0';
        strcpy(library->title, title);
        library->artist[0] = '\0';
        strcpy(library->artist, artist);
        library->genre[0] = '\0';
        strcpy(library->genre, genre);
    }
}

void displayMusic(struct Music library) {
    printf("Title: %s\n", library.title);
    printf("Artist: %s\n", library.artist);
    printf("Genre: %s\n", library.genre);
}

void deleteMusic(struct Music* library) {
    if (library!= NULL) {
        free(library->title);
        free(library->artist);
        free(library->genre);
        free(library);
    }
}

int main() {
    struct Music library;
    library.title[0] = '\0';
    library.artist[0] = '\0';
    library.genre[0] = '\0';

    addMusic(&library, "Bohemian Rhapsody", "Queen", "Rock");
    addMusic(&library, "Imagine", "John Lennon", "Pop");
    addMusic(&library, "Smells Like Teen Spirit", "Nirvana", "Grunge");

    displayMusic(library);

    deleteMusic(&library);

    return 0;
}