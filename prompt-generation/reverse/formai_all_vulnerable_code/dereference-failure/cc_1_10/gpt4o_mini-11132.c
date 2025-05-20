//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a surrealist node: a dream-like entity intertwining the mundane and the bizarre
struct SurrealistNode {
    char *data;               // A string representing the node's essence
    struct SurrealistNode *next; // A pointer to the next entity in the dreamscape
};

// Function to create a new surrealist node filled with words from the void
struct SurrealistNode* createNode(char *value) {
    struct SurrealistNode *newNode = (struct SurrealistNode*)malloc(sizeof(struct SurrealistNode));
    newNode->data = strdup(value);
    newNode->next = NULL;
    printf("A new surreal entity has materialized: %s\n", newNode->data);
    return newNode;
}

// Function to append a node to the dreamlike list
void appendNode(struct SurrealistNode **head, char *value) {
    struct SurrealistNode *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct SurrealistNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the dream world, where nodes whisper their secrets
void displayList(struct SurrealistNode *node) {
    printf("In the realm of the linked list, the following dreams exist:\n");
    while (node != NULL) {
        printf(" - %s\n", node->data);
        node = node->next;
    }
}

// Function to free the mind's eye, releasing all nodes into oblivion
void freeList(struct SurrealistNode *node) {
    while (node != NULL) {
        struct SurrealistNode *temp = node;
        node = node->next;
        free(temp->data);
        free(temp);
    }
    printf("The dreamscape has been cleansed; all entities have returned to the void.\n");
}

// Function to dream up a surreal insertion in the middle of the linked list
void insertMiddle(struct SurrealistNode **head, char *value, int position) {
    struct SurrealistNode *newNode = createNode(value);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct SurrealistNode *current = *head;
    int index = 0;
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }
    if (current == NULL) {
        printf("Cannot insert %s, position is beyond reach of the linked cosmos.\n", value);
        free(newNode->data);
        free(newNode);
    } else {
        newNode->next = current->next;
        current->next = newNode;
        printf("Inserted '%s' into the surreal tapestry at position %d.\n", value, position);
    }
}

// Function to conjure the echoes in the list, finding a specific dream
int searchNode(struct SurrealistNode *head, char *value) {
    int index = 0;
    while (head != NULL) {
        if (strcmp(head->data, value) == 0) {
            printf("Found the dream '%s' at position %d.\n", value, index);
            return index;
        }
        head = head->next;
        index++;
    }
    printf("The dream '%s' eludes our grasp.\n", value);
    return -1;
}

// Main function to weave the various threads together
int main() {
    struct SurrealistNode *head = NULL;

    appendNode(&head, "A cloud of lavender whispers");
    appendNode(&head, "Time dances on a mirage");
    appendNode(&head, "The fish wears a crown of feathers");
    
    displayList(head);

    insertMiddle(&head, "A shadow laughs at the dawn", 1);
    displayList(head);

    searchNode(head, "Time dances on a mirage");
    searchNode(head, "An illusion of reality");

    freeList(head);
    return 0;
}