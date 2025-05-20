//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the music library structure
typedef struct MusicLibrary {
    char title[255];
    char artist[255];
    char genre[255];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a music library node
MusicLibrary* insertNode(MusicLibrary* head) {
    MusicLibrary* newNode = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    printf("Enter the title: ");
    scanf("%s", newNode->title);
    printf("Enter the artist: ");
    scanf("%s", newNode->artist);
    printf("Enter the genre: ");
    scanf("%s", newNode->genre);
    printf("Enter the year: ");
    scanf("%d", &newNode->year);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

// Function to display the music library
void displayLibrary(MusicLibrary* head) {
    MusicLibrary* current = head;
    printf("Music Library:\n");
    while (current) {
        printf("Title: %s\n", current->title);
        printf("Artist: %s\n", current->artist);
        printf("Genre: %s\n", current->genre);
        printf("Year: %d\n", current->year);
        printf("\n");
        current = current->next;
    }
}

int main() {
    MusicLibrary* head = NULL;

    // Insert some music library nodes
    head = insertNode(head);
    insertNode(head);
    insertNode(head);

    // Display the music library
    displayLibrary(head);

    return 0;
}