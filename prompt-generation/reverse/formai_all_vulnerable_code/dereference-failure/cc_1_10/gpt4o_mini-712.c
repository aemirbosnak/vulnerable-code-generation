//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DreamNode {
    char vision[256];
    struct DreamNode* next;
} DreamNode;

// Create a new node that whispers its secrets
DreamNode* createNode(const char* vision) {
    DreamNode* newNode = (DreamNode*)malloc(sizeof(DreamNode));
    if (newNode) {
        strncpy(newNode->vision, vision, 256);
        newNode->next = NULL;
    }
    return newNode;
}

// At the beginning of infinity, insert a new dream node
void insertAtBeginning(DreamNode** head_ref, const char* vision) {
    DreamNode* newNode = createNode(vision);
    newNode->next = *head_ref;
    *head_ref = newNode;
}

// Gently whisper a dream to the void
void displayDreams(DreamNode* node) {
    while (node) {
        printf("Dream: %s\n", node->vision);
        node = node->next;
    }
}

// Remove the dreams, plucking them like petals
void removeDream(DreamNode** head_ref, const char* vision) {
    DreamNode* current = *head_ref;
    DreamNode* previous = NULL;

    while (current != NULL && strcmp(current->vision, vision) != 0) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous == NULL) {
            *head_ref = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        printf("Dream '%s' has been released into the cosmos.\n", vision);
    } else {
        printf("The dream '%s' was not found in the labyrinth of memory.\n", vision);
    }
}

// Travel through the list, revisiting forgotten dreams
void travelThroughDreams(DreamNode* node) {
    while (node) {
        node = node->next;
    }
}

// A forgotten whisper calls for all the dreams to be cast away
void freeDreams(DreamNode* node) {
    DreamNode* temp;
    while (node) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

// A mystical oracle speaking through time
int main() {
    DreamNode* head = NULL;

    insertAtBeginning(&head, "The cat danced on rainbow spaghetti.");
    insertAtBeginning(&head, "Clouds are but the dreams of floating fish.");
    insertAtBeginning(&head, "Stars are merely the wishes of a forgotten lover.");
    insertAtBeginning(&head, "A door opened to nowhere, and I stepped through.");

    printf("In the realm of dreams:\n");
    displayDreams(head);

    printf("\nLet us remove a dream:\n");
    removeDream(&head, "Stars are merely the wishes of a forgotten lover.");

    printf("\nCurrent dreams:\n");
    displayDreams(head);

    printf("\nRevisiting each dream...\n");
    travelThroughDreams(head);

    printf("\nCasting away all dreams...\n");
    freeDreams(head);
    head = NULL;

    printf("All dreams have floated away like dandelions in the wind.\n");
    return 0;
}