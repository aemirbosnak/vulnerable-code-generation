//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char artist[50];
    char genre[20];
    int year;
    struct Node *next;
} Song;

typedef struct Node {
    Song *data;
    struct Node *next;
} Node;

Node *head = NULL;

void addSong(Song *newSong) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = newSong;
    newNode->next = head;
    head = newNode;
}

void printLibrary() {
    Node *current = head;
    while (current != NULL) {
        printf("Title: %s\n", current->data->title);
        printf("Artist: %s\n", current->data->artist);
        printf("Genre: %s\n", current->data->genre);
        printf("Year: %d\n", current->data->year);
        printf("\n");
        current = current->next;
    }
}

int main() {
    int choice, option;
    char title[100], artist[50], genre[20];
    int year;
    Song *newSong;

    while (1) {
        printf("1. Add Song\n");
        printf("2. Print Library\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                newSong = (Song *) malloc(sizeof(Song));
                printf("Enter title: ");
                scanf("%s", title);
                strcpy(newSong->title, title);

                printf("Enter artist: ");
                scanf("%s", artist);
                strcpy(newSong->artist, artist);

                printf("Enter genre: ");
                scanf("%s", genre);
                strcpy(newSong->genre, genre);

                printf("Enter year: ");
                scanf("%d", &year);
                newSong->year = year;

                addSong(newSong);
                break;

            case 2:
                printLibrary();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }

        printf("\n");
    }

    return 0;
}