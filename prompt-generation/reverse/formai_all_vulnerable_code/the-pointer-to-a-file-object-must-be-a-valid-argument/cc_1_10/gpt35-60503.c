//FormAI DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONG_LENGTH 100
#define MAX_ARTIST_LENGTH 50
#define MAX_YEAR_LENGTH 5
#define MAX_ALBUM_LENGTH 50
#define MAX_GENRE_LENGTH 20

typedef struct Song {
    char title[MAX_SONG_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char year[MAX_YEAR_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    struct Song *next;
} Song;

Song *head = NULL;

void addSong() {
    Song *newSong = malloc(sizeof(Song));
    printf("Enter song title: ");
    fgets(newSong->title, MAX_SONG_LENGTH, stdin);
    printf("Enter artist name: ");
    fgets(newSong->artist, MAX_ARTIST_LENGTH, stdin);
    printf("Enter year released: ");
    fgets(newSong->year, MAX_YEAR_LENGTH, stdin);
    printf("Enter album name: ");
    fgets(newSong->album, MAX_ALBUM_LENGTH, stdin);
    printf("Enter genre: ");
    fgets(newSong->genre, MAX_GENRE_LENGTH, stdin);
    newSong->next = head;
    head = newSong;
}

void displaySongs() {
    Song *current = head;
    if(current == NULL) {
        printf("No songs in library.\n");
        return;
    }
    printf("%-30s %-20s %-10s %-20s %-15s\n", "TITLE", "ARTIST", "YEAR", "ALBUM", "GENRE");
    while(current != NULL) {
        printf("%-30s %-20s %-10s %-20s %-15s\n", current->title, current->artist, current->year, current->album, current->genre);
        current = current->next;
    }
}

void deleteSong() {
    char title[MAX_SONG_LENGTH];
    Song *current = head;
    Song *prev = NULL;
    printf("Enter title of song to delete: ");
    fgets(title, MAX_SONG_LENGTH, stdin);
    while(current != NULL) {
        if(strcmp(current->title, title) == 0) {
            if(prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            printf("%s deleted from library.\n", current->title);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("%s not found in library.\n", title);
}

void saveLibrary() {
    FILE *fp = fopen("library.txt", "w");
    Song *current = head;
    while(current != NULL) {
        fprintf(fp, "%s|%s|%s|%s|%s\n", current->title, current->artist, current->year, current->album, current->genre);
        current = current->next;
    }
    fclose(fp);
}

void loadLibrary() {
    FILE *fp = fopen("library.txt", "r");
    char line[MAX_SONG_LENGTH + MAX_ARTIST_LENGTH + MAX_YEAR_LENGTH + MAX_ALBUM_LENGTH + MAX_GENRE_LENGTH + 4];
    char *title, *artist, *year, *album, *genre;
    Song *newSong;
    while(fgets(line, MAX_SONG_LENGTH + MAX_ARTIST_LENGTH + MAX_YEAR_LENGTH + MAX_ALBUM_LENGTH + MAX_GENRE_LENGTH + 4, fp)) {
        title = strtok(line, "|");
        artist = strtok(NULL, "|");
        year = strtok(NULL, "|");
        album = strtok(NULL, "|");
        genre = strtok(NULL, "\n");
        newSong = malloc(sizeof(Song));
        strcpy(newSong->title, title);
        strcpy(newSong->artist, artist);
        strcpy(newSong->year, year);
        strcpy(newSong->album, album);
        strcpy(newSong->genre, genre);
        newSong->next = head;
        head = newSong;
    }
    fclose(fp);
}

int main() {
    char choice;
    loadLibrary();
    do {
        printf("Music Library Management System\n");
        printf("--------------------------------\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Delete song\n");
        printf("4. Save library\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        getchar();
        switch(choice) {
            case '1':
                addSong();
                break;
            case '2':
                displaySongs();
                break;
            case '3':
                deleteSong();
                break;
            case '4':
                saveLibrary();
                break;
            case '5':
                saveLibrary();
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != '5');
    return 0;
}