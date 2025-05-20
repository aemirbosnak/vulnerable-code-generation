//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct that represents a music album
typedef struct album {
    char *name;
    char *artist;
    int releaseYear;
} Album;

// struct that represents a node in the linked list
typedef struct node {
    Album album;
    struct node *next;
} Node;

// function to print the details of an album
void printAlbum(Album album) {
    printf("Album Name: %s\n", album.name);
    printf("Artist: %s\n", album.artist);
    printf("Release Year: %d\n", album.releaseYear);
    printf("----------------------------------------\n");
}

// function to search for an album in the linked list
// returns a pointer to the node containing the album if found, or NULL otherwise
Node *searchAlbum(Node *head, char *name) {
    Node *curr = head;
    while(curr != NULL) {
        if(strcmp(curr->album.name, name) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

int main() {
    Node *head = NULL;  // initialize the linked list to be empty

    // add some albums to the library
    Album album1 = {"The Dark Side of the Moon", "Pink Floyd", 1973};
    Album album2 = {"Nevermind", "Nirvana", 1991};
    Album album3 = {"Abbey Road", "The Beatles", 1969};

    // add the albums to the linked list
    Node *node1 = (Node*)malloc(sizeof(Node));
    node1->album = album1;
    node1->next = NULL;
    head = node1;

    Node *node2 = (Node*)malloc(sizeof(Node));
    node2->album = album2;
    node2->next = NULL;
    node1->next = node2;

    Node *node3 = (Node*)malloc(sizeof(Node));
    node3->album = album3;
    node3->next = NULL;
    node2->next = node3;

    // print all the albums in the library
    printf("Library contents:\n");
    Node *curr = head;
    while(curr != NULL) {
        printAlbum(curr->album);
        curr = curr->next;
    }

    // search for an album and print its details
    char *searchName = "Abbey Road";
    Node *found = searchAlbum(head, searchName);
    if(found != NULL) {
        printf("Found album: %s\n", searchName);
        printAlbum(found->album);
    } else {
        printf("Could not find album: %s\n", searchName);
    }

    // free the memory allocated for the linked list
    curr = head;
    while(curr != NULL) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }

    return 0;
}