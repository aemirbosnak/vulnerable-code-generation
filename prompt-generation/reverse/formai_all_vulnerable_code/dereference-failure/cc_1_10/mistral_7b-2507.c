//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[50];
    char artist[50];
    int year;
} Song;

typedef struct Node {
    Song data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void addSong(Song song) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = song;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void printLibrary() {
    Node* current = head;
    printf("\n--- Montague's Music Library ---\n");

    while (current != NULL) {
        printf("%s by %s (%d)\n", current->data.title, current->data.artist, current->data.year);
        current = current->next;
    }
}

int main() {
    addSong((Song){"O Romeo, O Romeo! wherefore art thou Romeo?", "Melancholy Gentleman", 1597});
    addSong((Song){"But soft! what light through yonder window breaks?", "Juliet Capulet", 1597});
    addSong((Song){"It is the east, and Juliet is the sun.", "Romeo Montague", 1597});

    printLibrary();

    return 0;
}