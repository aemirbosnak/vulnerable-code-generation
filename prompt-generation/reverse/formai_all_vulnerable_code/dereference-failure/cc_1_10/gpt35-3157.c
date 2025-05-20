//FormAI DATASET v1.0 Category: Music Library Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song{
    char title[50];
    char artist[50];
    char album[50];
    int track_number;
    struct song *next;
};

void add_song(struct song **list_ptr) {
    struct song *new_song = (struct song *)malloc(sizeof(struct song));
    printf("\nEnter song title: ");
    scanf("%s", new_song->title);
    printf("Enter artist name: ");
    scanf("%s", new_song->artist);
    printf("Enter album name: ");
    scanf("%s", new_song->album);
    printf("Enter track number: ");
    scanf("%d", &new_song->track_number);
    new_song->next = NULL;
    if (*list_ptr == NULL) {
        *list_ptr = new_song;
    } else {
        struct song *last_song = *list_ptr;
        while (last_song->next != NULL) {
            last_song = last_song->next;
        }
        last_song->next = new_song;
    }
    printf("\nSong added to library.\n");
}

void display_songs(struct song *list) {
    if (list == NULL) {
        printf("\nThere are no songs in the library.\n");
    } else {
        printf("\nSong Library:\n");
        printf("Title\tArtist\tAlbum\tTrack No.\n");
        while (list != NULL) {
            printf("%s\t%s\t%s\t%d\n", list->title, list->artist, list->album, list->track_number);
            list = list->next;
        }
    }
}

void search_song(struct song *list) {
    char title[50];
    printf("\nEnter song title: ");
    scanf("%s", title);
    while (list != NULL) {
        if (strcmp(list->title, title) == 0) {
            printf("\nSearch results:\n");
            printf("Title\tArtist\tAlbum\tTrack No.\n");
            printf("%s\t%s\t%s\t%d\n", list->title, list->artist, list->album, list->track_number);
            return;
        }
        list = list->next;
    }
    printf("\nSong not found.\n");
}

int main() {
    struct song *library = NULL;
    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("\n1. Add Song to Library");
        printf("\n2. Display Songs from Library");
        printf("\n3. Search Song in Library");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_song(&library);
                break;
            case 2:
                display_songs(library);
                break;
            case 3:
                search_song(library);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}