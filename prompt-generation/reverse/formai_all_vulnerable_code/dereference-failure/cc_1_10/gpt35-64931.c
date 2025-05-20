//FormAI DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Song {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char album[MAX_SIZE];
    int year;
    float duration;
    char genre[MAX_SIZE];
    struct Song *nextSong;
} Song;

Song *createSong(char title[], char artist[], char album[], int year, float 
duration, char genre[]) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    strcpy(newSong->album, album);
    newSong->year = year;
    newSong->duration = duration;
    strcpy(newSong->genre, genre);
    
    newSong->nextSong = NULL;
    
    return newSong;
}

void displaySong(Song *s) {
    printf("%s | %s | %s | %d | %.2f | %s\n", s->title, s->artist, 
    s->album, s->year, s->duration, s->genre);
}

typedef struct SongList {
    Song *head;
    int size;
} SongList;

SongList *createSongList() {
    SongList *newList = (SongList *)malloc(sizeof(SongList));
    newList->head = NULL;
    newList->size = 0;
    
    return newList;
}

void addSong(SongList *list, char title[], char artist[], char album[], 
int year, float duration, char genre[]) {
    Song *newSong = createSong(title, artist, album, year, duration, genre);
    
    if (list->head == NULL) {
        list->head = newSong;
    } else {
        Song *currentSong = list->head;
        while (currentSong->nextSong != NULL) {
            currentSong = currentSong->nextSong;
        }
        currentSong->nextSong = newSong;
    }
    list->size++;
}

void displayList(SongList *list) {
    if (list->size == 0) {
        printf("The list is currently empty.\n");
    } else {
        Song *currentSong = list->head;
        printf("Title | Artist | Album | Year | Duration | Genre\n");
        while (currentSong != NULL) {
            displaySong(currentSong);
            currentSong = currentSong->nextSong;
        }
    }
}

void searchList(SongList *list, char term[]) {
    Song *currentSong = list->head;
    while (currentSong != NULL) {
        if (strstr(currentSong->title, term) != NULL || 
        strstr(currentSong->artist, term) != NULL || 
        strstr(currentSong->album, term) != NULL ||
        strstr(currentSong->genre, term) != NULL ||
        currentSong->year == atoi(term)) {
            displaySong(currentSong);
        }
        currentSong = currentSong->nextSong;
    }
}

void deleteSong(SongList *list, char title[]) {
    if (list->size == 0) {
        printf("The list is currently empty.\n");
        return;
    }
    
    Song *currentSong = list->head;
    Song *prevSong = NULL;
    
    while (currentSong != NULL) {
        if (strcmp(currentSong->title, title) == 0) {
            if (prevSong == NULL) {
                list->head = currentSong->nextSong;
            } else {
                prevSong->nextSong = currentSong->nextSong;
            }
            free(currentSong);
            list->size--;
            printf("%s has been deleted.\n", title);
            return;
        }
        prevSong = currentSong;
        currentSong = currentSong->nextSong;
    }
    
    printf("%s is not in the list.\n", title);
}

void deleteList(SongList *list) {
    Song *currentSong = list->head;
    Song *nextSong = NULL;
    
    while (currentSong != NULL) {
        nextSong = currentSong->nextSong;
        free(currentSong);
        currentSong = nextSong;
    }
    
    printf("The list has been deleted.\n");
}

int main() {
    SongList *list = createSongList();
    
    int choice;
    char title[MAX_SIZE], artist[MAX_SIZE], album[MAX_SIZE], 
    yearStr[MAX_SIZE], durationStr[MAX_SIZE], genre[MAX_SIZE], term[MAX_SIZE];
    int year;
    float duration;
    
    printf("Welcome to the Music Library Management System!\n");
    
    do {
        printf("\n---------------------------------------------------------------\n");
        printf("Please choose from the following options:\n");
        printf("1. Add a song to the library\n");
        printf("2. Display the list of songs in the library\n");
        printf("3. Search the list of songs in the library\n");
        printf("4. Delete a song from the library\n");
        printf("5. Delete the entire library\n");
        printf("6. Exit the program\n");
        printf("---------------------------------------------------------------\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nAdding a song to the library...\n");
                printf("Enter the title of the song: ");
                scanf(" %[^\n]s", title);
                printf("Enter the name of the artist: ");
                scanf(" %[^\n]s", artist);
                printf("Enter the name of the album: ");
                scanf(" %[^\n]s", album);
                printf("Enter the year the song was released: ");
                scanf(" %[^\n]s", yearStr);
                year = atoi(yearStr);
                printf("Enter the duration of the song: ");
                scanf(" %[^\n]s", durationStr);
                duration = strtof(durationStr, NULL);
                printf("Enter the genre of the song: ");
                scanf(" %[^\n]s", genre);
                addSong(list, title, artist, album, year, duration, genre);
                printf("%s by %s has been successfully added to the library.\n", title, artist);
                break;
            case 2:
                printf("\nDisplaying the list of songs in the library...\n");
                displayList(list);
                break;
            case 3:
                printf("\nSearching the list of songs in the library...\n");
                printf("Enter a search term: ");
                scanf(" %[^\n]s", term);
                searchList(list, term);
                break;
            case 4:
                printf("\nDeleting a song from the library...\n");
                printf("Enter the title of the song you wish to delete: ");
                scanf(" %[^\n]s", title);
                deleteSong(list, title);
                break;
            case 5:
                printf("\nDeleting the entire library...\n");
                deleteList(list);
                list = createSongList();
                break;
            case 6:
                printf("\nThank you for using the Music Library Management System!\n");
                deleteList(list);
                free(list);
                exit(0);
            default:
                printf("\nPlease enter a valid option.\n");
                break;
        }
        
    } while (choice != 6);

    return 0;
}