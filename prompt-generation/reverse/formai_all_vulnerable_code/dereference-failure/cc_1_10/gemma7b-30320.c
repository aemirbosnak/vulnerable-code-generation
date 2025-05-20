//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Define the Music Library Management System (MLMS) structure
typedef struct MusicLibrary {
    char title[255];
    char artist[255];
    char genre[255];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a new music library item into the MLMS
void insertMusicItem(MusicLibrary** head) {
    // Allocate memory for the new music library item
    MusicLibrary* newMusicItem = (MusicLibrary*)malloc(sizeof(MusicLibrary));

    // Get the item's details from the user
    printf("Enter the title of the music item: ");
    scanf("%s", newMusicItem->title);

    printf("Enter the artist of the music item: ");
    scanf("%s", newMusicItem->artist);

    printf("Enter the genre of the music item: ");
    scanf("%s", newMusicItem->genre);

    printf("Enter the year of the music item: ");
    scanf("%d", &newMusicItem->year);

    // Insert the new music library item into the MLMS
    if (*head == NULL) {
        *head = newMusicItem;
    } else {
        (*head)->next = newMusicItem;
        *head = newMusicItem;
    }
}

// Function to search for a music library item in the MLMS
MusicLibrary* searchMusicItem(MusicLibrary* head, char* title) {
    // Traverse the MLMS to find the music library item
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }

    // Return NULL if the item is not found
    return NULL;
}

// Function to delete a music library item from the MLMS
void deleteMusicItem(MusicLibrary* head, char* title) {
    // Search for the music library item to delete
    MusicLibrary* itemToDelete = searchMusicItem(head, title);

    // If the item is found, delete it
    if (itemToDelete) {
        MusicLibrary* previousItem = NULL;

        // Traverse the MLMS to find the item to delete
        while (head) {
            if (head == itemToDelete) {
                if (previousItem) {
                    previousItem->next = itemToDelete->next;
                } else {
                    head = itemToDelete->next;
                }
                free(itemToDelete);
                itemToDelete = NULL;
            } else {
                previousItem = head;
                head = head->next;
            }
        }
    }
}

// Main function
int main() {
    // Create a new music library management system
    MusicLibrary* head = NULL;

    // Insert some music library items
    insertMusicItem(&head);
    insertMusicItem(&head);
    insertMusicItem(&head);

    // Search for a music library item
    MusicLibrary* item = searchMusicItem(head, "Song 2");

    // If the item is found, print its details
    if (item) {
        printf("Title: %s\n", item->title);
        printf("Artist: %s\n", item->artist);
        printf("Genre: %s\n", item->genre);
        printf("Year: %d\n", item->year);
    } else {
        printf("Item not found.\n");
    }

    // Delete a music library item
    deleteMusicItem(head, "Song 2");

    // Search for the item after deletion
    item = searchMusicItem(head, "Song 2");

    // If the item is not found, print an error message
    if (item == NULL) {
        printf("Item not found.\n");
    } else {
        printf("Item found.\n");
    }

    return 0;
}