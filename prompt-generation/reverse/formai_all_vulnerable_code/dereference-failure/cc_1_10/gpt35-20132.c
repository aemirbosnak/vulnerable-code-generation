//FormAI DATASET v1.0 Category: Music Library Management System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct to hold information about a song
struct song{
    char name[50];
    char artist[50];
    char genre[20];
    float duration;
    struct song *next;
};

// function to create a new song node
struct song* create_song(){
    struct song *new_song;
    new_song = malloc(sizeof(struct song));
    printf("\nEnter song name: ");
    scanf("%s", new_song->name);
    printf("Enter artist name: ");
    scanf("%s", new_song->artist);
    printf("Enter genre: ");
    scanf("%s", new_song->genre);
    printf("Enter duration: ");
    scanf("%f", &new_song->duration);
    new_song->next = NULL;
    return new_song;
}

// function to add a song to the library
void add_song(struct song **library){
    struct song *new_song = create_song();
    if (*library == NULL){
        *library = new_song;
        printf("\nAdded %s by %s to the library.", new_song->name, new_song->artist);
    } else {
        struct song *curr_song = *library;
        while (curr_song->next != NULL){
            curr_song = curr_song->next;
        }
        curr_song->next = new_song;
        printf("\nAdded %s by %s to the library.", new_song->name, new_song->artist);
    }
}

// function to remove a song from the library
void remove_song(struct song **library, char name[]){
    struct song *curr_song = *library;
    struct song *prev_song = NULL;

    if (curr_song == NULL){
        printf("The library is empty!");
    } else if (strcmp(curr_song->name, name) == 0){ // first song in the list
        *library = curr_song->next;
        printf("\nRemoved %s by %s from the library.", curr_song->name, curr_song->artist);
        free(curr_song);
    } else {
        while (curr_song != NULL && strcmp(curr_song->name, name) != 0){
            prev_song = curr_song;
            curr_song = curr_song->next;
        }
        if (curr_song == NULL){ // song not found
            printf("\n%s was not found in the library.", name);
        } else { // song found
            prev_song->next = curr_song->next;
            printf("\nRemoved %s by %s from the library.", curr_song->name, curr_song->artist);
            free(curr_song);
        }
    }
}

// function to search for songs by artist
void search_by_artist(struct song *library, char artist[]){
    int count = 0;
    struct song *curr_song = library;
    while (curr_song != NULL){
        if (strcmp(curr_song->artist, artist) == 0){
            printf("%s by %s (%s, %.2f min)\n", curr_song->name, curr_song->artist, curr_song->genre, curr_song->duration);
            count++;
        }
        curr_song = curr_song->next;
    }
    if (count == 0){
        printf("No songs found by %s.", artist);
    }
}

// function to display all songs in the library
void display_library(struct song *library){
    if (library == NULL){
        printf("The library is empty!");
    } else {
        struct song *curr_song = library;
        while (curr_song != NULL){
            printf("%s by %s (%s, %.2f min)\n", curr_song->name, curr_song->artist, curr_song->genre, curr_song->duration);
            curr_song = curr_song->next;
        }
    }
}

int main(){
    struct song *library = NULL;
    int choice;
    char name[50];
    char artist[50];

    printf("Welcome to the Music Library Management System!\n");

    do {
        printf("\n");
        printf("\n1. Add song to library");
        printf("\n2. Remove song from library");
        printf("\n3. Search for songs by artist");
        printf("\n4. Display library");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1: // Add song to library
                add_song(&library);
                break;
            case 2: // Remove song from library
                printf("\nEnter song name to remove: ");
                scanf("%s", name);
                remove_song(&library, name);
                break;
            case 3: // Search for songs by artist
                printf("\nEnter artist name: ");
                scanf("%s", artist);
                search_by_artist(library, artist);
                break;
            case 4: // Display library
                display_library(library);
                break;
            case 5: // Exit
                printf("\nGoodbye!");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }

    } while (choice != 5);

    return 0;
}