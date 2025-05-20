//FormAI DATASET v1.0 Category: Music Library Management System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char title[50];
    char artist[50];
    int year;
    struct node* next;
};

typedef struct node Node;

Node* start = NULL;

// Function to print the main menu
void print_menu() {
    printf("\nC MUSIC LIBRARY MANAGEMENT SYSTEM");
    printf("\n----------------------------------");
    printf("\n1. Add a new song");
    printf("\n2. Display all songs in library");
    printf("\n3. Search for a song");
    printf("\n4. Delete a song");
    printf("\n5. Exit");
    printf("\n----------------------------------");
    printf("\nEnter your choice: ");
}

// Function to add a new song to the library
void add_song() {
    Node* new_song = (Node*) malloc(sizeof(Node));

    printf("\nEnter the title of the song: ");
    scanf("%s", new_song->title);
    printf("Enter the name of the artist: ");
    scanf("%s", new_song->artist);
    printf("Enter the release year: ");
    scanf("%d", &new_song->year);

    new_song->next = NULL;

    if (start == NULL) {
        start = new_song;
        printf("\nSong added successfully!");
        return;
    }

    Node* current_node = start;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_song;
    printf("\nSong added successfully!");
}

// Function to display all songs in the library
void display_songs() {
    if (start == NULL) {
        printf("\nThe library is empty.");
        return;
    }

    Node* current_node = start;
    printf("\n%-30s%-20s%s", "Title", "Artist", "Year");
    printf("\n--------------------------------------------------");
    while (current_node != NULL) {
        printf("\n%-30s%-20s%d", current_node->title, current_node->artist, current_node->year);
        current_node = current_node->next;
    }
}

// Function to search for a song in the library
void search_song() {
    if (start == NULL) {
        printf("\nThe library is empty.");
        return;
    }

    char search_title[50];
    printf("\nEnter the title of the song to search for: ");
    scanf("%s", search_title);

    Node* current_node = start;
    while (current_node != NULL) {
        if (strcmp(current_node->title, search_title) == 0) {
            printf("\n%-30s%-20s%d", current_node->title, current_node->artist, current_node->year);
            return;
        }
        current_node = current_node->next;
    }

    printf("\nSong not found.");
}

// Function to delete a song from the library
void delete_song() {
    if (start == NULL) {
        printf("\nThe library is empty.");
        return;
    }

    char delete_title[50];
    printf("\nEnter the title of the song to delete: ");
    scanf("%s", delete_title);

    if (strcmp(start->title, delete_title) == 0) {
        Node* temp = start;
        start = start->next;
        free(temp);
        printf("\nSong deleted successfully!");
        return;
    }

    Node* current_node = start->next;
    Node* previous_node = start;
    while (current_node != NULL) {
        if (strcmp(current_node->title, delete_title) == 0) {
            previous_node->next = current_node->next;
            free(current_node);
            printf("\nSong deleted successfully!");
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    printf("\nSong not found.");
}

int main() {
    int choice;

    while(1) {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song();
                break;
            case 2:
                display_songs();
                break;
            case 3:
                search_song();
                break;
            case 4:
                delete_song();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid option. Please try again.");
        }
    }
    return 0;
}