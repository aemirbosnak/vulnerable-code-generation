//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char name[32];
    int whimsy;
    struct Node *next;
} DreamNode;

DreamNode *head = NULL;

void addNode(char *name, int whimsy) {
    DreamNode *newNode = (DreamNode *)malloc(sizeof(DreamNode));
    strcpy(newNode->name, name);
    newNode->whimsy = whimsy;
    newNode->next = head;
    head = newNode;
}

void deleteNode(char *name) {
    DreamNode *current = head;
    DreamNode *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Node not found.\n");
}

DreamNode *searchNode(char *name) {
    DreamNode *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void displayList() {
    DreamNode *current = head;

    printf("Welcome to the Dreamscape Garden!\n");
    printf("---------------------------------\n");

    while (current != NULL) {
        printf("%s (Whimsy: %d)\n", current->name, current->whimsy);
        current = current->next;
    }

    printf("---------------------------------\n");
}

int main() {
    addNode("Rose", 5);
    addNode("Tulip", 3);
    addNode("Daisy", 8);

    displayList();

    DreamNode *foundNode = searchNode("Tulip");
    if (foundNode != NULL) {
        printf("Found node 'Tulip'.\n");
        foundNode->whimsy += 2;
        printf("Updated whimsy for node 'Tulip': %d\n", foundNode->whimsy);
    }

    deleteNode("Daisy");

    displayList();

    return 0;
}