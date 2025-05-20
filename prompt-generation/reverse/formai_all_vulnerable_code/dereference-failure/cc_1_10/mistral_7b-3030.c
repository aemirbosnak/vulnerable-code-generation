//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    char genre[20];
    char year[5];
} Song;

typedef struct Node {
    Song data;
    struct Node *next;
} Node;

Node* createNode(Song song) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = song;
    newNode->next = NULL;
    return newNode;
}

void addSongToPlaylist(Node **head, Song song) {
    Node *newSongNode = createNode(song);
    newSongNode->next = *head;
    *head = newSongNode;
}

void printPlaylist(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s by %s - %s (%s)\n", current->data.title, current->data.artist, current->data.album, current->data.year);
        current = current->next;
    }
}

int main() {
    Node *playlist = NULL;

    // Romeo's songs
    addSongToPlaylist(&playlist, ((Song){"O Romeo, O Romeo!", "Romeo Montague", "The Montagues' Collection", "Romantic", "1597"}));
    addSongToPlaylist(&playlist, ((Song){"If Love be Lost", "Romeo Montague", "The Montagues' Collection", "Romantic", "1597"}));
    addSongToPlaylist(&playlist, ((Song){"Fortune's Fool", "Romeo Montague", "The Montagues' Collection", "Romantic", "1597"}));

    // Juliet's songs
    addSongToPlaylist(&playlist, ((Song){"O Romeo, Romeo!", "Juliet Capulet", "The Capulets' Collection", "Romantic", "1597"}));
    addSongToPlaylist(&playlist, ((Song){"A Rose by Any Other Name", "Juliet Capulet", "The Capulets' Collection", "Romantic", "1597"}));
    addSongToPlaylist(&playlist, ((Song){"When in the Tempest's Eye I am Calm", "Juliet Capulet", "The Capulets' Collection", "Romantic", "1597"}));

    printf("Romeo's Playlist:\n");
    printPlaylist(playlist);

    printf("\n--------------------\n");

    printf("Juliet's Playlist:\n");
    Node *temp = playlist;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    printPlaylist(temp->next);

    return 0;
}