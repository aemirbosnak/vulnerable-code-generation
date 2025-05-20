//FormAI DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a music track
typedef struct TrackStruct {
    char title[50];
    char artist[50];
    int year;
    struct TrackStruct *next;
} Track;

// Function to add a new track to the library
void addTrack(Track **library) {
    Track *newTrack = (Track*)malloc(sizeof(Track));

    printf("Enter the title of the track: ");
    fgets(newTrack->title, 50, stdin);
    newTrack->title[strcspn(newTrack->title, "\n")] = 0;

    printf("Enter the artist of the track: ");
    fgets(newTrack->artist, 50, stdin);
    newTrack->artist[strcspn(newTrack->artist, "\n")] = 0;

    printf("Enter the year of the track: ");
    scanf("%d", &newTrack->year);

    newTrack->next = *library;
    *library = newTrack;
}

// Function to display all tracks in the library
void displayLibrary(Track *library) {
    if(library == NULL) {
        printf("The library is empty.\n");
        return;
    }

    printf("%-50s %-50s %-4s\n", "Title", "Artist", "Year");
    printf("--------------------------------------------------\n");
    while(library != NULL) {
        printf("%-50s %-50s %-4d\n", library->title, library->artist, library->year);
        library = library->next;
    }
}

// Function to search for a track in the library
void searchLibrary(Track *library) {
    if(library == NULL) {
        printf("The library is empty.\n");
        return;
    }

    char searchTerm[50];
    printf("Enter a search term: ");
    fgets(searchTerm, 50, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0;
    
    int found = 0;
    while(library != NULL) {
        if(strstr(library->title, searchTerm) != NULL || strstr(library->artist, searchTerm) != NULL) {
            printf("%-50s %-50s %-4d\n", library->title, library->artist, library->year);
            found = 1;
        }
        library = library->next;
    }

    if(!found) {
        printf("No results found for '%s'.\n", searchTerm);
    }
}

// Function to delete a track from the library
void deleteTrack(Track **library) {
    if(*library == NULL) {
        printf("The library is empty.\n");
        return;
    }

    char deleteTitle[50];
    printf("Enter the title of the track to delete: ");
    fgets(deleteTitle, 50, stdin);
    deleteTitle[strcspn(deleteTitle, "\n")] = 0;

    Track *prev = NULL;
    Track *curr = *library;
    while(curr != NULL) {
        if(strcmp(curr->title, deleteTitle) == 0) {
            if(prev == NULL) {
                *library = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("The track '%s' has been deleted from the library.\n", deleteTitle);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("The track '%s' was not found in the library.\n", deleteTitle);
}

// Main function
int main() {
    Track *library = NULL;
    int choice;

    do {
        printf("\nMusic Library Management System\n");
        printf("--------------------------------\n");
        printf("1. Display library\n");
        printf("2. Add track to library\n");
        printf("3. Search library\n");
        printf("4. Delete track from library\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                displayLibrary(library);
                break;
            case 2:
                addTrack(&library);
                break;
            case 3:
                searchLibrary(library);
                break;
            case 4:
                deleteTrack(&library);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}