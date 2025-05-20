//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct Song {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char genre[MAX_SIZE];
    int length;
    struct Song *next;
} Song;

typedef struct Library {
    Song *head;
    int num_songs;
} Library;

void add_song(Library *lib, const char *title, const char *artist, const char *genre, int length) {
    Song *new_song = (Song *) malloc(sizeof(Song));
    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    strcpy(new_song->genre, genre);
    new_song->length = length;
    new_song->next = lib->head;
    lib->head = new_song;
    lib->num_songs++;
}

void print_library(Library *lib) {
    Song *current = lib->head;
    printf("----------------------\n");
    printf("| %-20s | %-20s | %-10s | %5d |\n", "Title", "Artist", "Genre", "Length");
    printf("----------------------\n");

    while (current != NULL) {
        printf("| %-20s | %-20s | %-10s | %5d |\n", current->title, current->artist, current->genre, current->length);
        current = current->next;
    }

    printf("----------------------\n");
}

void transform_library(Library *lib, const char *cmd) {
    Song *current = lib->head;
    Song *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->title, cmd) == 0) {
            if (prev != NULL) {
                prev->next = current->next;
                current->next = NULL;
                lib->num_songs--;
                free(current);
            }
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    Library lib = {NULL, 0};
    int choice;
    char title[MAX_SIZE], artist[MAX_SIZE], genre[MAX_SIZE];
    int length;
    char cmd[MAX_SIZE];

    while (1) {
        printf("1. Add Song\n");
        printf("2. Print Library\n");
        printf("3. Transform Library (Remove Song)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter artist: ");
                scanf("%s", artist);
                printf("Enter genre: ");
                scanf("%s", genre);
                printf("Enter length: ");
                scanf("%d", &length);
                add_song(&lib, title, artist, genre, length);
                break;
            case 2:
                print_library(&lib);
                break;
            case 3:
                printf("Enter title to transform: ");
                scanf("%s", cmd);
                transform_library(&lib, cmd);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Shape shifting style:
// The library is a shape-shifting entity that can add, print, or transform itself based on the user's choice.
// The add_song function grows the library by appending a new Song node to its head.
// The print_library function shapes itself into a printer, displaying the library's contents in a neat table format.
// The transform_library function shapes itself into a transformer, removing a Song node from the library based on the user's command.