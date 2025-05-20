//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[30];
    struct Node* next;
} Node;

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, const char* name) {
    Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayLoversJourney(Node* head) {
    Node* current = head;
    printf("A Love Story:\n");
    printf("=================\n");
    while (current != NULL) {
        printf("Together they wandered, hand in hand, through the fields of dreams... %s\n", current->name);
        current = current->next;
    }
    printf("=================\n");
}

void freeMemory(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* loversJourney = NULL;

    // Their journey begins
    insertAtEnd(&loversJourney, "Under the starlit sky");
    insertAtEnd(&loversJourney, "Through the whispering woods");
    insertAtEnd(&loversJourney, "Along the shimmering beach");
    insertAtEnd(&loversJourney, "Across the blooming meadows");
    insertAtEnd(&loversJourney, "Beneath the moonlit glow");

    // Display their journey
    displayLoversJourney(loversJourney);

    // Free the memory of their beautiful journey
    freeMemory(loversJourney);

    return 0;
}