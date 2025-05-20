//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store music library information
typedef struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a music library item at the end
void insertAtEnd(MusicLibrary** head) {
    MusicLibrary* newNode = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    printf("Enter the title: ");
    scanf("%s", newNode->title);
    printf("Enter the artist: ");
    scanf("%s", newNode->artist);
    printf("Enter the genre: ");
    scanf("%s", newNode->genre);
    printf("Enter the year: ");
    scanf("%d", &newNode->year);

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
    *head = newNode;
}

// Function to search for a music library item by title
MusicLibrary* searchByTitle(MusicLibrary* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to print the music library
void printMusicLibrary(MusicLibrary* head) {
    while (head) {
        printf("Title: %s\n", head->title);
        printf("Artist: %s\n", head->artist);
        printf("Genre: %s\n", head->genre);
        printf("Year: %d\n", head->year);
        printf("\n");
        head = head->next;
    }
}

int main() {
    MusicLibrary* head = NULL;

    // Insert some music library items
    insertAtEnd(&head);
    insertAtEnd(&head);
    insertAtEnd(&head);

    // Search for a music library item by title
    MusicLibrary* item = searchByTitle(head, "Song 2");

    // Print the music library item
    if (item) {
        printMusicLibrary(item);
    } else {
        printf("Item not found.\n");
    }

    return 0;
}