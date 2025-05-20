//FormAI DATASET v1.0 Category: Music Library Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_info {
    char title[100];
    char artist[100];
    char album[100];
    char genre[100];
    float duration;
} SongInfo;

typedef struct song_node {
    SongInfo song;
    struct song_node *prev, *next;
} SongNode;

SongNode *head = NULL;

void add_song(SongInfo song) {
    SongNode *new_node = malloc(sizeof(SongNode));
    new_node->song = song;
    new_node->prev = NULL;
    new_node->next = head;
    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
}

void delete_song(char *title) {
    SongNode *current = head;
    while (current != NULL) {
        if (strcmp(current->song.title, title) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

void display_songs() {
    SongNode *current = head;
    while (current != NULL) {
        printf("Title: %s\nArtist: %s\nAlbum: %s\nGenre: %s\nDuration: %.2f\n", current->song.title,
               current->song.artist, current->song.album, current->song.genre, current->song.duration);
        current = current->next;
    }
}

int main() {
    int choice;
    char title[100];
    SongInfo song;
    printf("Welcome to the C Music Library Management System!\n");
    while (1) {
        printf("\n");
        printf("Please choose an option:\n");
        printf("1. Add a song\n");
        printf("2. Delete a song\n");
        printf("3. Display all songs\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                printf("Enter the song title: ");
                scanf("%s", song.title);
                printf("Enter the artist: ");
                scanf("%s", song.artist);
                printf("Enter the album: ");
                scanf("%s", song.album);
                printf("Enter the genre: ");
                scanf("%s", song.genre);
                printf("Enter the duration: ");
                scanf("%f", &song.duration);
                add_song(song);
                printf("Song added!\n");
                break;

            case 2:
                printf("Enter the title of the song you want to delete: ");
                scanf("%s", title);
                delete_song(title);
                printf("Song deleted!\n");
                break;

            case 3:
                printf("Songs in library:\n");
                display_songs();
                break;

            case 4:
                printf("Thank you for using the C Music Library Management System!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}