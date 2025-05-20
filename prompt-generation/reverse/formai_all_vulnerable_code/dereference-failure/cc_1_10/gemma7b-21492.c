//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Create Romeo and Juliet
    Node* romeo = malloc(sizeof(Node));
    strcpy(romeo->name, "Romeo");
    romeo->next = NULL;
    if (head == NULL) {
        head = tail = romeo;
    } else {
        tail->next = romeo;
        tail = romeo;
    }

    Node* juliet = malloc(sizeof(Node));
    strcpy(juliet->name, "Juliet");
    juliet->next = NULL;
    if (head == NULL) {
        head = tail = juliet;
    } else {
        tail->next = juliet;
        tail = juliet;
    }

    // Create their friends
    Node* ben = malloc(sizeof(Node));
    strcpy(ben->name, "Ben");
    ben->next = NULL;
    tail->next = ben;
    tail = ben;

    Node* Mercutio = malloc(sizeof(Node));
    strcpy(Mercutio->name, "Mercutio");
    Mercutio->next = NULL;
    tail->next = Mercutio;
    tail = Mercutio;

    // The feud begins!
    printf("Romeo and Juliet's feud begins...\n");
    printf("A Montague and Capulet feud...\n");
    printf("Their love knows no bounds...\n");

    return 0;
}