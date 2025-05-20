//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the nodes in the linked list
typedef struct Node {
    char *event;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(const char *event) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->event = (char *)malloc(strlen(event) + 1);
    strcpy(newNode->event, event);
    newNode->next = NULL;
    return newNode;
}

// Function to add an event at the end of the linked list
void addEvent(Node **head, const char *event) {
    Node *newNode = createNode(event);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove the last event from the linked list
void removeLastEvent(Node **head) {
    if (*head == NULL) {
        printf("Alas! There are no events to remove!\n");
        return;
    }

    Node *temp = *head;
    if (temp->next == NULL) {
        free(temp->event);
        free(temp);
        *head = NULL;
        printf("The last event hath departed: %s\n", temp->event);
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("The last event hath departed: %s\n", temp->next->event);
    free(temp->next->event);
    free(temp->next);
    temp->next = NULL;
}

// Function to print all events in the linked list
void printEvents(Node *head) {
    if (head == NULL) {
        printf("No events to display, like a broken heart...\n");
        return;
    }
    printf("These are the moments of passion:\n");
    Node *temp = head;
    while (temp != NULL) {
        printf("-> %s\n", temp->event);
        temp = temp->next;
    }
    printf("\n");
}

// Function to clear the linked list
void clearEvents(Node **head) {
    Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp->event);
        free(temp);
    }
}

// Main function with a dramatic storyline
int main() {
    Node *events = NULL;
    printf("In fair Verona, where we lay our scene...\n");

    addEvent(&events, "Romeo first meets Juliet under the moonlight.");
    addEvent(&events, "They declare their love amidst the nightingale's song.");
    addEvent(&events, "A secret marriage, forged by fate.");
    addEvent(&events, "The feud between the Montagues and Capulets rages.");
    addEvent(&events, "Tybalt slays Mercutio, bringing despair.");
    addEvent(&events, "Romeo avenges his friend, a fateful blow.");
    addEvent(&events, "A banishment that tears them apart.");
    addEvent(&events, "A potion, a plan, a darkened chamber...");

    printEvents(events);

    printf("But alas, what fate awaits our lovers?\n");
    removeLastEvent(&events); // Remove the last event to signify tragedy
    printEvents(events);

    // Another dramatic removal
    printf("As fate would have it...\n");
    removeLastEvent(&events);
    printEvents(events);

    // Clearing events to end the tragedy
    clearEvents(&events);
    printf("All events are fled, like the dreams of youth.\n");

    return 0;
}