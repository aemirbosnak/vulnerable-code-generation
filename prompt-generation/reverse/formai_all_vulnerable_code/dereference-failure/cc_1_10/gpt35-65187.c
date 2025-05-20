//FormAI DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for music item
typedef struct MusicItem {
    int code;
    char title[50];
    char artist[50];
    int year;
} MusicItem;

// Define function to create a new music item
MusicItem* createMusicItem(int code, char* title, char* artist, int year) {
    MusicItem* newItem = (MusicItem*) malloc(sizeof(MusicItem));
    newItem->code = code;
    strcpy(newItem->title, title);
    strcpy(newItem->artist, artist);
    newItem->year = year;
    return newItem;
}

// Define function to add a music item to the library
void addMusicItem(MusicItem** library, int* itemCount, MusicItem* item) {
    library[*itemCount] = item;
    (*itemCount)++;
}

// Define function to remove a music item from the library
void removeMusicItem(MusicItem** library, int* itemCount, int code) {
    int i, j;
    for (i = 0; i < *itemCount; i++) {
        if (library[i]->code == code) {
            free(library[i]);
            for (j = i; j < *itemCount - 1; j++) {
                library[j] = library[j+1];
            }
            (*itemCount)--;
            break;
        }
    }
}

// Define function to display all music items in the library
void displayAllMusicItems(MusicItem** library, int itemCount) {
    int i;
    printf("All music items in the library:\n");
    for (i = 0; i < itemCount; i++) {
        printf("%d. %s - %s (%d)\n", library[i]->code, library[i]->title, library[i]->artist, library[i]->year);
    }
}

int main() {
    // Create an empty library
    MusicItem** library = (MusicItem**) malloc(sizeof(MusicItem*)*100);
    int itemCount = 0;
    int choice;

    do {
        // Display menu
        printf("\nChoose an option:\n");
        printf("1. Add a music item\n");
        printf("2. Remove a music item\n");
        printf("3. Display all music items\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Add a new music item
                int code, year;
                char title[50], artist[50];
                printf("Enter music item code: ");
                scanf("%d", &code);
                printf("Enter music item title: ");
                scanf("%s", title);
                printf("Enter music item artist: ");
                scanf("%s", artist);
                printf("Enter music item year: ");
                scanf("%d", &year);
                MusicItem* newItem = createMusicItem(code, title, artist, year);
                addMusicItem(library, &itemCount, newItem);
                break;
            }
            case 2: {
                // Remove a music item
                int code;
                printf("Enter music item code to remove: ");
                scanf("%d", &code);
                removeMusicItem(library, &itemCount, code);
                break;
            }
            case 3: {
                // Display all music items
                displayAllMusicItems(library, itemCount);
                break;
            }
            case 4:
                // Quit program
                printf("Goodbye!");
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.");
                break;
        }
    } while (choice != 4);

    // Free memory
    int i;
    for (i = 0; i < itemCount; i++) {
        free(library[i]);
    }
    free(library);
    return 0;
}