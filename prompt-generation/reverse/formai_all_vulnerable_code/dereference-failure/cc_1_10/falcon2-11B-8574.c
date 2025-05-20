//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Library {
    char name[100];
    char artist[100];
    char album[100];
    int year;
    int tracks;
    int rating;
} Library;

void addLibrary(Library *library) {
    printf("Enter the name of the library: ");
    scanf("%s", library->name);

    printf("Enter the artist of the library: ");
    scanf("%s", library->artist);

    printf("Enter the album of the library: ");
    scanf("%s", library->album);

    printf("Enter the year of the library: ");
    scanf("%d", &library->year);

    printf("Enter the number of tracks in the library: ");
    scanf("%d", &library->tracks);

    printf("Enter the rating of the library (0-10): ");
    scanf("%d", &library->rating);
}

void displayLibrary(Library library) {
    printf("Name: %s\n", library.name);
    printf("Artist: %s\n", library.artist);
    printf("Album: %s\n", library.album);
    printf("Year: %d\n", library.year);
    printf("Tracks: %d\n", library.tracks);
    printf("Rating: %d\n", library.rating);
}

void deleteLibrary(Library *library) {
    printf("Are you sure you want to delete the library '%s'? (y/n): ", library->name);
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y') {
        free(library);
        printf("Library '%s' deleted successfully.\n", library->name);
    } else {
        printf("Library '%s' not deleted.\n", library->name);
    }
}

void updateLibrary(Library *library) {
    printf("Enter the new name of the library: ");
    scanf("%s", library->name);

    printf("Enter the new artist of the library: ");
    scanf("%s", library->artist);

    printf("Enter the new album of the library: ");
    scanf("%s", library->album);

    printf("Enter the new year of the library: ");
    scanf("%d", &library->year);

    printf("Enter the new number of tracks in the library: ");
    scanf("%d", &library->tracks);

    printf("Enter the new rating of the library (0-10): ");
    scanf("%d", &library->rating);
}

int main() {
    Library library1;
    addLibrary(&library1);
    displayLibrary(library1);

    Library library2;
    addLibrary(&library2);
    displayLibrary(library2);

    Library library3;
    addLibrary(&library3);
    displayLibrary(library3);

    deleteLibrary(&library1);

    Library library4;
    updateLibrary(&library4);
    displayLibrary(library4);

    return 0;
}