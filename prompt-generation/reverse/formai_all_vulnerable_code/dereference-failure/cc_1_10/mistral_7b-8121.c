//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define SONG_SIZE 50

typedef struct Song {
    char title[SONG_SIZE];
    char artist[SONG_SIZE];
    char album[SONG_SIZE];
    int length;
    struct Song *next;
} Song;

Song *library = NULL;
int num_songs = 0;

void add_song(Song *new_song) {
    if (library == NULL) {
        library = new_song;
    } else {
        Song *current = library;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_song;
    }
    num_songs++;
}

void display_library() {
    Song *current = library;
    printf("\n***** Music Library *****\n");
    printf("S.no | Title                 | Artist               | Album           | Length (sec) \n");
    printf("---------------------------------------------------------------------------------------\n");
    int count = 1;
    while (current != NULL) {
        printf("%d | %-30s | %-30s | %-30s | %5d\n", count, current->title, current->artist, current->album, current->length);
        current = current->next;
        count++;
    }
}

int main() {
    char title[SONG_SIZE], artist[SONG_SIZE], album[SONG_SIZE];
    int length;
    char command;

    while (1) {
        printf("\n1. Add Song\n2. Display Library\n3. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &command);

        switch (command) {
            case '1':
                printf("Enter Song Title: ");
                scanf("%s", title);
                printf("Enter Artist Name: ");
                scanf("%s", artist);
                printf("Enter Album Name: ");
                scanf("%s", album);
                printf("Enter Song Length (sec): ");
                scanf("%d", &length);

                Song *new_song = (Song *)malloc(sizeof(Song));
                strcpy(new_song->title, title);
                strcpy(new_song->artist, artist);
                strcpy(new_song->album, album);
                new_song->length = length;
                add_song(new_song);
                printf("Song added successfully!\n");
                break;

            case '2':
                display_library();
                break;

            case '3':
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}