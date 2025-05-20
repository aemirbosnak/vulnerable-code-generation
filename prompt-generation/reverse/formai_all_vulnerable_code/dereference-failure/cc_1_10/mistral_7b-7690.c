//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Music {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char genre[MAX_SIZE];
    int length;
} Music;

typedef struct Node {
    Music data;
    struct Node* next;
} Node;

Node* createNode(Music music) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = music;
    newNode->next = NULL;
    return newNode;
}

void addSongToList(Node** head, Music music) {
    Node* newNode = createNode(music);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s by %s (%s) - %d seconds\n", current->data.title, current->data.artist, current->data.genre, current->data.length);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    Music song1 = {"Bohemian Rhapsody", "Queen", "Rock", 551};
    Music song2 = {"Stairway to Heaven", "Led Zeppelin", "Hard Rock", 801};
    Music song3 = {"Black Dog", "Led Zeppelin", "Hard Rock", 402};

    addSongToList(&head, song1);
    addSongToList(&head, song2);
    addSongToList(&head, song3);

    printf("Music library:\n");
    printList(head);

    return 0;
}