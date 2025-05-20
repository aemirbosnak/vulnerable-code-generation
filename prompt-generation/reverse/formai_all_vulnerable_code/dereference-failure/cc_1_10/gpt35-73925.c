//FormAI DATASET v1.0 Category: Music Library Management System ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Song {
    char name[100];
    char artist[100];
    char album[100];
    int year;
};

struct Node {
    struct Song song;
    struct Node* next;
};

void displayMenu() {
    printf("====================================\n");
    printf("C MUSIC LIBRARY MANAGEMENT SYSTEM\n");
    printf("====================================\n");
    printf("1. Add a Song\n");
    printf("2. Remove a Song\n");
    printf("3. Display the Entire Library\n");
    printf("0. Exit\n");
    printf("====================================\n");
}

void addSong(struct Node** head_ref) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the Song Name: ");
    fgets(new_node->song.name, 100, stdin);
    printf("Enter the Artist Name: ");
    fgets(new_node->song.artist, 100, stdin);
    printf("Enter the Album Name: ");
    fgets(new_node->song.album, 100, stdin);
    printf("Enter the Year of Release: ");
    scanf("%d", &new_node->song.year);
    getchar();
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("\nSong Added to the Library!\n");
}

void removeSong(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("\nLibrary is already empty!\n");
        return;
    }
    struct Node* temp = *head_ref, * prev_node = NULL;
    char song_name[100];
    printf("Enter the Name of the Song you want to remove: ");
    fgets(song_name, 100, stdin);
    while (temp != NULL && strcmp(temp->song.name, song_name) != 0) {
        prev_node = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nSong not found in the library!\n");
        return;
    }
    if (prev_node == NULL) {
        (*head_ref) = temp->next;
    }
    else {
        prev_node->next = temp->next;
    }
    printf("\nSong \"%s\" removed from the library!\n", temp->song.name);
    free(temp);
}

void displayLibrary(struct Node* head) {
    if (head == NULL) {
        printf("\nLibrary is empty!\n");
        return;
    }
    printf("\n-----------------------------------------------------\n");
    printf("%-30s| %-20s| %-20s| %4s\n", "Song Name", "Artist Name", "Album Name", "Year");
    printf("-----------------------------------------------------\n");
    struct Node* current = head;
    while (current != NULL) {
        printf("%-30s| %-20s| %-20s| %4d\n", current->song.name, current->song.artist, current->song.album, current->song.year);
        current = current->next;
    }
    printf("-----------------------------------------------------\n");
}

int main() {
    struct Node* library = NULL;
    int option;
    do {
        displayMenu();
        printf("Enter option number: ");
        scanf("%d", &option);
        getchar();
        switch (option) {
        case 1:
            addSong(&library);
            break;
        case 2:
            removeSong(&library);
            break;
        case 3:
            displayLibrary(library);
            break;
        case 0:
            printf("\nGoodbye!\n");
            break;
        default:
            printf("\nInvalid option!\n");
        }
        printf("\nPress Enter to continue...");
        getchar();
        system("clear");
    } while (option != 0);    
    return 0;
}