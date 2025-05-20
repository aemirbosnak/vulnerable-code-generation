//FormAI DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    struct song *next;
} Song;

Song *head = NULL; // global variable to keep track of the first element in the linked list

Song *createSong(char title[], char artist[], char album[], int year) {
    Song *newSong = (Song *) malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    strcpy(newSong->album, album);
    newSong->year = year;
    newSong->next = NULL;
    return newSong;
}

void addSong(Song *newSong) {
    if (head == NULL) {
        head = newSong; // if list is empty, add new song to the head
    } else {
        Song *current = head;
        while (current->next != NULL) {
            current = current->next; // move to the end of the list
        }
        current->next = newSong; // link the new song to the list
    }
}

void printSong(Song *song) {
    printf("%s\n", song->title);
    printf("%s\n", song->artist);
    printf("%s\n", song->album);
    printf("%d\n", song->year);
}

void printLibrary() {
    Song *current = head;
    while (current != NULL) {
        printSong(current);
        current = current->next; // move to the next element in the list
    }
}

Song *search(char title[], char artist[]) {
    Song *current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0 && strcmp(current->artist, artist) == 0) {
            return current; // return the song if found
        }
        current = current->next; // move to the next element in the list
    }
    printf("Song not found.\n");
    return NULL;
}

void delete(char title[], char artist[]) {
    if (head == NULL) {
        printf("Library is empty.\n");
        return;
    }
    Song *current = head;
    Song *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0 && strcmp(current->artist, artist) == 0) {
            if (previous == NULL) {
                head = current->next; // if first element is the song to be deleted
            } else {
                previous->next = current->next; // link the previous element to the next element
            }
            free(current);
            printf("Song deleted.\n");
            return;
        }
        previous = current;
        current = current->next; // move to the next element in the list
    }
    printf("Song not found.\n");
}

void saveToFile(char fileName[]) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error in opening file.\n");
        return;
    }
    Song *current = head;
    while (current != NULL) {
        fprintf(file, "%s;%s;%s;%d\n", current->title, current->artist, current->album, current->year);
        current = current->next;
    }
    fclose(file);
    printf("Library saved to file.\n");
}

void loadFromFile(char fileName[]) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error in opening file.\n");
        return;
    }
    char line[200];
    char *token;
    while (fgets(line, 200, file) != NULL) {
        token = strtok(line, ";"); // get title
        char title[50];
        strcpy(title, token);
        token = strtok(NULL, ";"); // get artist
        char artist[50];
        strcpy(artist, token);
        token = strtok(NULL, ";"); // get album
        char album[50];
        strcpy(album, token);
        token = strtok(NULL, "\n"); // get year
        int year = atoi(token);
        Song *newSong = createSong(title, artist, album, year);
        addSong(newSong);
    }
    fclose(file);
    printf("Library loaded from file.\n");
}

int main() {
    int option;
    char title[50];
    char artist[50];
    char album[50];
    int year;
    char fileName[50];
    while (1) {
        printf("Select an option:\n");
        printf("1. Add a song\n");
        printf("2. Print library\n");
        printf("3. Search for a song\n");
        printf("4. Delete a song\n");
        printf("5. Save to file\n");
        printf("6. Load from file\n");
        printf("7. Exit\n");
        scanf("%d", &option);
        getchar(); // to consume the newline character
        switch (option) {
            case 1:
                printf("Enter the title: ");
                fgets(title, 50, stdin);
                title[strcspn(title, "\n")] = 0; // remove the newline character
                printf("Enter the artist: ");
                fgets(artist, 50, stdin);
                artist[strcspn(artist, "\n")] = 0;
                printf("Enter the album: ");
                fgets(album, 50, stdin);
                album[strcspn(album, "\n")] = 0;
                printf("Enter the year: ");
                scanf("%d", &year);
                getchar(); // to consume the newline character
                Song *newSong = createSong(title, artist, album, year);
                addSong(newSong);
                printf("Song added.\n");
                break;
            case 2:
                printLibrary();
                break;
            case 3:
                printf("Enter the title: ");
                fgets(title, 50, stdin);
                title[strcspn(title, "\n")] = 0;
                printf("Enter the artist: ");
                fgets(artist, 50, stdin);
                artist[strcspn(artist, "\n")] = 0;
                Song *foundSong = search(title, artist);
                if (foundSong != NULL) {
                    printSong(foundSong);
                }
                break;
            case 4:
                printf("Enter the title: ");
                fgets(title, 50, stdin);
                title[strcspn(title, "\n")] = 0;
                printf("Enter the artist: ");
                fgets(artist, 50, stdin);
                artist[strcspn(artist, "\n")] = 0;
                delete(title, artist);
                break;
            case 5:
                printf("Enter the filename: ");
                fgets(fileName, 50, stdin);
                fileName[strcspn(fileName, "\n")] = 0;
                saveToFile(fileName);
                break;
            case 6:
                printf("Enter the filename: ");
                fgets(fileName, 50, stdin);
                fileName[strcspn(fileName, "\n")] = 0;
                loadFromFile(fileName);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    return 0;
}