//FormAI DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    char artist[100];
    char genre[50];
    int year;
} Song;

typedef struct Node {
    Song song;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

void addSong() {
    /* Prompts user to input song details and creates a new node to store the song */
    Node* newSong = (Node*)malloc(sizeof(Node));

    printf("Enter song title: ");
    scanf("%s", newSong->song.title);

    printf("Enter artist name: ");
    scanf("%s", newSong->song.artist);

    printf("Enter song genre: ");
    scanf("%s", newSong->song.genre);

    printf("Enter song release year: ");
    scanf("%d", &newSong->song.year);

    /* Add new song to the linked list */
    if(head == NULL) {
        /* If it's the first song added, set head and tail pointers to the new node */
        head = newSong;
        tail = newSong;
        newSong->prev = NULL;
    } else {
        /* Otherwise, set the tail to the new node and link it to the previous node */
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
    newSong->next = NULL;
}

void displaySongs() {
    /* Displays all songs in the linked list */
    Node* curr = head;

    printf("Title\t\tArtist\t\tGenre\t\tYear\n");
    printf("---------------------------------------------------------\n");

    while(curr != NULL) {
        printf("%s\t\t%s\t\t%s\t\t%d\n", curr->song.title, curr->song.artist, curr->song.genre, curr->song.year);
        curr = curr->next;
    }
}

void deleteSong() {
    /* Prompts user to enter the song title of the song to be deleted */
    char title[100];
    printf("Enter song title to delete: ");
    scanf("%s", title);

    Node* curr = head;
    Node* temp = NULL;

    while(curr != NULL) {
        if(strcmp(curr->song.title, title) == 0) {
            temp = curr;
            break;
        }
        curr = curr->next;
    }

    if(temp != NULL) {
        /* If the song is found in the linked list, link the previous node to the next node 
        and free the memory allocated for the deleted node */
        if(temp == head && temp == tail) {
            /* If the deleted node is the only node in the linked list, set the head and tail pointers to NULL */
            head = NULL;
            tail = NULL;
        } else if(temp == head) {
            /* If the deleted node is the head node, set the head pointer to the next node */
            head = temp->next;
            head->prev = NULL;
        } else if(temp == tail) {
            /* If the deleted node is the tail node, set the tail pointer to the previous node */
            tail = temp->prev;
            tail->next = NULL;
        } else {
            /* If the deleted node is in between two nodes, link the previous node to the next node */
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
        printf("\nSong successfully deleted!\n");
    } else {
        printf("\nSong not found!\n");
    }
}

void searchSong() {
    /* Prompts user to enter the song title to be searched */
    char title[100];
    printf("Enter song title to search: ");
    scanf("%s", title);

    Node* curr = head;
    int found = 0;

    while(curr != NULL) {
        if(strcmp(curr->song.title, title) == 0) {
            /* If song is found in the linked list, display its details */
            printf("\nTitle\t\tArtist\t\tGenre\t\tYear\n");
            printf("---------------------------------------------------------\n");
            printf("%s\t\t%s\t\t%s\t\t%d\n", curr->song.title, curr->song.artist, curr->song.genre, curr->song.year);
            found = 1;
            break;
        }
        curr = curr->next;
    }

    if(!found) {
        printf("\nSong not found!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n+--------------------------------------------------------------+\n");
        printf("|                    MUSIC LIBRARY MANAGEMENT                   |\n");
        printf("+--------------------------------------------------------------+\n");
        printf("| Options:                                                     |\n");
        printf("|        1. Add a new song to the library                       |\n");
        printf("|        2. Display all songs in the library                    |\n");
        printf("|        3. Delete a song from the library                       |\n");
        printf("|        4. Search for a song in the library                      |\n");
        printf("|        5. Exit                                                |\n");
        printf("+--------------------------------------------------------------+\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong();
                break;
            case 2:
                displaySongs();
                break;
            case 3:
                deleteSong();
                break;
            case 4:
                searchSong();
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    } while(choice != 5);
    
    return 0;
}