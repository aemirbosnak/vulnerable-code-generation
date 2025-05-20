//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char genre[MAX_SIZE];
    char shape[MAX_SIZE];
    struct Node *next;
} Node;

void initShape(Node *node) {
    strcpy(node->shape, "Sphere");
}

void transformShape(Node *node, char *newShape) {
    strcpy(node->shape, newShape);
}

void printNode(Node *node) {
    printf("Title: %s\n", node->title);
    printf("Artist: %s\n", node->artist);
    printf("Genre: %s\n", node->genre);
    printf("Shape: %s\n", node->shape);
}

void addSong(Node **head, char *title, char *artist, char *genre) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->title, title);
    strcpy(newNode->artist, artist);
    strcpy(newNode->genre, genre);
    initShape(newNode);
    newNode->next = *head;
    *head = newNode;
}

void deleteSong(Node **head, char *title) {
    Node *current = *head;
    Node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    Node *head = NULL;

    addSong(&head, "Bohemian Rhapsody", "Queen", "Rock");
    addSong(&head, "Stairway to Heaven", "Led Zeppelin", "Classic Rock");

    Node *current = head;

    while (current != NULL) {
        printNode(current);
        transformShape(current, "Cube");
        current = current->next;
    }

    deleteSong(&head, "Bohemian Rhapsody");

    current = head;

    while (current != NULL) {
        printNode(current);
        current = current->next;
    }

    return 0;
}