//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Song {
    char title[50];
    char artist[50];
    char genre[50];
    int releaseYear;
} Song;

typedef struct MusicLibrary {
    Song* songs[MAX_SIZE];
    int numOfSongs;
} MusicLibrary;

void addSong(MusicLibrary* library, Song* song);
void removeSong(MusicLibrary* library, char* title, char* artist);
void searchSong(MusicLibrary* library, char* keyword);

int main() {
    MusicLibrary library;
    library.numOfSongs = 0;

    int choice;
    do {
        printf("\n--- MUSIC LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("1. Add new song\n");
        printf("2. Remove a song\n");
        printf("3. Search for a song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                Song* song = (Song*)malloc(sizeof(Song));

                printf("\nEnter song details: \n");
                printf("Title: ");
                getchar();
                fgets(song->title, 50, stdin);
                song->title[strcspn(song->title, "\r\n")] = '\0';

                printf("Artist: ");
                fgets(song->artist, 50, stdin);
                song->artist[strcspn(song->artist, "\r\n")] = '\0';

                printf("Genre: ");
                fgets(song->genre, 50, stdin);
                song->genre[strcspn(song->genre, "\r\n")] = '\0';

                printf("Release Year: ");
                scanf("%d", &song->releaseYear);

                addSong(&library, song);
                printf("\nSong added successfully!\n");
                break;
            }

            case 2: {
                char title[50], artist[50];

                printf("\nEnter song details: \n");
                printf("Title: ");
                getchar();
                fgets(title, 50, stdin);
                title[strcspn(title, "\r\n")] = '\0';

                printf("Artist: ");
                fgets(artist, 50, stdin);
                artist[strcspn(artist, "\r\n")] = '\0';

                removeSong(&library, title, artist);
                break;
            }

            case 3: {
                char keyword[50];

                printf("\nEnter song title or artist name: ");
                getchar();
                fgets(keyword, 50, stdin);
                keyword[strcspn(keyword, "\r\n")] = '\0';

                searchSong(&library, keyword);
                break;
            }

            case 4: {
                printf("\nThank you for using Music Library Management System!\n");
                break;
            }

            default: {
                printf("\nInvalid choice! Please try again.\n");
                break;
            }
        }
    } while(choice != 4);

    return 0;
}

void addSong(MusicLibrary* library, Song* song) {
    if(library->numOfSongs == MAX_SIZE) {
        printf("Music library is full!\n");
        return;
    }

    library->songs[library->numOfSongs++] = song;
}

void removeSong(MusicLibrary* library, char* title, char* artist) {
    int i, found = 0;
    for(i = 0; i < library->numOfSongs; i++) {
        Song* song = library->songs[i];
        if(strcmp(song->title, title) == 0 && strcmp(song->artist, artist) == 0) {
            found = 1;
            free(library->songs[i]);
            library->songs[i] = NULL;
            printf("\nSong removed successfully!\n");
            break;
        }
    }
    if(!found) {
        printf("\nSong not found!\n");
    } else {
        for(i; i < library->numOfSongs - 1; i++) {
            library->songs[i] = library->songs[i+1];
        }
        library->numOfSongs--;
    }
}

void searchSong(MusicLibrary* library, char* keyword) {
    int i, found = 0;
    for(i = 0; i < library->numOfSongs; i++) {
        Song* song = library->songs[i];
        if(strstr(song->title, keyword) != NULL || strstr(song->artist, keyword) != NULL) {
            found = 1;
            printf("\nSong found: \n");
            printf("Title: %s\n", song->title);
            printf("Artist: %s\n", song->artist);
            printf("Genre: %s\n", song->genre);
            printf("Release Year: %d\n", song->releaseYear);
        }
    }
    if(!found) {
        printf("\nSong not found!\n");
    }
}