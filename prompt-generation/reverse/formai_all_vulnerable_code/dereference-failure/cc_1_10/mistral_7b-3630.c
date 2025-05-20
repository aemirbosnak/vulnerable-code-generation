//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    char artist[50];
    char album[50];
    int release_year;
    struct Song *next;
} Song;

Song *head = NULL;

void add_song(char title[], char artist[], char album[], int year) {
    Song *new_song = (Song *)malloc(sizeof(Song));
    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    strcpy(new_song->album, album);
    new_song->release_year = year;
    new_song->next = head;
    head = new_song;
}

void print_library() {
    Song *current = head;
    printf("\nCurrent music library:\n");
    printf("-----------------------\n");
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Artist: %s\n", current->artist);
        printf("Album: %s\n", current->album);
        printf("Release Year: %d\n", current->release_year);
        current = current->next;
    }
}

void search_song(char query[]) {
    Song *current = head;
    int found = 0;
    while (current != NULL && !found) {
        if (strstr(current->title, query) != NULL ||
            strstr(current->artist, query) != NULL ||
            strstr(current->album, query) != NULL) {
            found = 1;
            printf("\nSong found:\n");
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n", current->artist);
            printf("Album: %s\n", current->album);
            printf("Release Year: %d\n", current->release_year);
        }
        current = current->next;
    }
    if (!found) {
        printf("\nSong not found.\n");
    }
}

int main() {
    add_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
    add_song("Another One Bites the Dust", "Queen", "Queen II", 1974);
    add_song("We Will Rock You", "Queen", "News of the World", 1977);
    add_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
    add_song("Whole Lotta Love", "Led Zeppelin", "Led Zeppelin II", 1969);

    print_library();
    search_song("Queen");
    search_song("Love");

    return 0;
}