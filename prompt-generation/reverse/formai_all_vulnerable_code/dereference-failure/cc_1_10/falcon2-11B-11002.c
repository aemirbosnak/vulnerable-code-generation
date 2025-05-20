//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a song
typedef struct song {
    char title[100];
    char artist[100];
    char album[100];
} Song;

// Define a linked list node
typedef struct node {
    Song song;
    struct node* next;
} Node;

// Function to create a new song
void create_song(Song* song, char title[], char artist[], char album[]) {
    strcpy(song->title, title);
    strcpy(song->artist, artist);
    strcpy(song->album, album);
}

// Function to add a new song to the linked list
void add_song(Node** head, char title[], char artist[], char album[]) {
    Node* new_song = (Node*) malloc(sizeof(Node));
    create_song(&new_song->song, title, artist, album);
    new_song->next = NULL;
    if (*head == NULL) {
        *head = new_song;
    } else {
        Node* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_song;
    }
}

// Function to search for a song in the linked list
int search_song(Node* head, char title[], char artist[], char album[]) {
    Node* current = head;
    while (current!= NULL) {
        if (strcmp(current->song.title, title) == 0 && 
            strcmp(current->song.artist, artist) == 0 && 
            strcmp(current->song.album, album) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to delete a song from the linked list
void delete_song(Node** head, char title[], char artist[], char album[]) {
    Node* current = *head;
    Node* previous = NULL;
    while (current!= NULL) {
        if (strcmp(current->song.title, title) == 0 && 
            strcmp(current->song.artist, artist) == 0 && 
            strcmp(current->song.album, album) == 0) {
            if (previous!= NULL) {
                previous->next = current->next;
            } else {
                *head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to print the linked list
void print_linked_list(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%s (%s) - %s\n", current->song.title, current->song.artist, current->song.album);
        current = current->next;
    }
}

// Main function
int main() {
    Node* head = NULL;

    // Add some songs to the linked list
    add_song(&head, "Bohemian Rhapsody", "Queen", "A Night at the Opera");
    add_song(&head, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV");
    add_song(&head, "Hotel California", "Eagles", "Hotel California");

    // Search for a song in the linked list
    printf("Search for 'Bohemian Rhapsody': %d\n", search_song(head, "Bohemian Rhapsody", "Queen", "A Night at the Opera"));

    // Delete a song from the linked list
    delete_song(&head, "Bohemian Rhapsody", "Queen", "A Night at the Opera");

    // Print the updated linked list
    printf("Updated linked list:\n");
    print_linked_list(head);

    return 0;
}